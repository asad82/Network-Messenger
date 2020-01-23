// CSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "CSocket.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CClientDlg *m_DlgPtr;

/////////////////////////////////////////////////////////////////////////////
// CCSocket

CCSocket::CCSocket()
{
}

CCSocket::~CCSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CCSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CCSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CCSocket member functions

void CCSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_DlgPtr->ccChat.m_ListenSocket.Accept(m_DlgPtr->ccChat.m_ConnectionSocket))
		;
	else
	{
		    m_DlgPtr->MessageBox("CC Connection can not be established");
	}

	if(!AfxSocketInit())
		m_DlgPtr->MessageBox("Failed to Initialize Sockets");
	
	m_DlgPtr->ccChat.DoModal();

	CAsyncSocket::OnAccept(nErrorCode);
}

void CCSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	char buff[1024];

	int rec=this->Receive(buff,1024);
	buff[rec]='\0';

	CString str;
	str.Format("%s",buff);
	m_DlgPtr->ccChat.m_List1.AddString(str);
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void CCSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnSend(nErrorCode);
}
