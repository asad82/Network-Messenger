// FileSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "FileSocket.h"
#include "CDialog.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// FileSocket
extern CClientDlg * m_DlgPtr;


FileSocket::FileSocket()
{
}

FileSocket::~FileSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(FileSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(FileSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// FileSocket member functions

void FileSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFileDialog saveFile(false);

	if(saveFile.DoModal()==IDOK)
	{
		m_DlgPtr->ccChat.saveFilePathName=saveFile.GetPathName();
	}
	else
		return;
	m_DlgPtr->ccChat.m_fConnectionSocket.Close();

	if(m_DlgPtr->ccChat.m_fListenSocket.Accept(m_DlgPtr->ccChat.m_fConnectionSocket))
		;
	else
	{
		    m_DlgPtr->MessageBox("File Connection can not be established");
	}

	if(!AfxSocketInit())
		m_DlgPtr->MessageBox("Failed to Initialize Sockets");

	filePtr.Open(m_DlgPtr->ccChat.saveFilePathName,CFile::modeCreate | CFile::modeWrite,NULL);
	filePtr.Close();
	//OnReceive(0);


	CAsyncSocket::OnAccept(nErrorCode);
}

void FileSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	filePtr.Open(m_DlgPtr->ccChat.saveFilePathName,CFile::modeWrite,NULL);
	
	char buff[50000];

	int rec=this->Receive(buff,50000);
	//buff[rec]='\0';
	//filePtr.WriteHuge(buff,50000);
	filePtr.Write(buff,rec);

	filePtr.Close();
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void FileSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	

	CAsyncSocket::OnSend(nErrorCode);
}
