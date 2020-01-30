// MySocket.cpp : implementation file
//
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		     : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include "stdafx.h"
#include "Client.h"
#include "MySocket.h"

#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CClientDlg *m_DlgPtr;
CString screenNames[200];
CString ipAddress[200];
int totalSCount=0,totalIPCount=0;

/////////////////////////////////////////////////////////////////////////////
// MySocket

MySocket::MySocket()
{



}

MySocket::~MySocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(MySocket, CAsyncSocket)
	//{{AFX_MSG_MAP(MySocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// MySocket member functions

void MySocket::OnReceive(int nErrorCode) 
{
	

	char buff[1024];
	CString str;
	int rec=m_DlgPtr->m_ClientSock.Receive(buff,1024);
	buff[rec]='\0';
	
	if(buff[0]=='*' && buff[1]=='*' && buff[2]=='*' && buff[3]=='*')
	{
			for(int clear=0;clear<500;clear++)
				m_DlgPtr->m_ListOnline.DeleteString(0);
			totalSCount=0;
			totalIPCount=0;
	}
	else if(buff[0]=='%' && buff[1]=='@')
	{
			char tempBuf[1024];
			char ipaddr[20];

			for(int k=0;k<1024;k++)
				tempBuf[k]='\0';

			for(int i=2;i<rec;i++)
			{
				if(buff[i]=='%')
					break;
				else
					tempBuf[i-2]=buff[i];
			}
			tempBuf[i]='\0';
			str.Format("%s",tempBuf);
			screenNames[totalSCount++]=str;
			m_DlgPtr->UpdateData(false);

			if(str.Compare("NULL")!=0)
				m_DlgPtr->m_ListOnline.AddString(str);
			
			m_DlgPtr->UpdateData(false);

			for( k=0;k<20;k++)
				ipaddr[k]='\0';

			for(int m=i+2;m<rec;m++)
			{
				if(buff[m]=='/')
					break;
				else
					ipaddr[m-2-i]=buff[m];
			}

			str.Format("%s",ipaddr);
			ipAddress[totalIPCount++]=str;


	}
	else
	{
		CString str;
		str.Format("%s",buff);
		m_DlgPtr->m_ListMsgs.AddString(str);
		m_DlgPtr->UpdateData(false);
	}

	CAsyncSocket::OnReceive(nErrorCode);
}

void MySocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnSend(nErrorCode);
}

void MySocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	CAsyncSocket::OnConnect(nErrorCode);
}

void MySocket::ClientClientChat()
{

	int selection=m_DlgPtr->m_ListOnline.GetCurSel();
	CString str;
	m_DlgPtr->m_ListOnline.GetText(selection,str);
	
	for(int i=0;i<totalSCount;i++)
	{
		if(str.Compare(screenNames[i])==0)
		{
			break;
		}

	}

	char addr[20];
	for(int b=0;b<ipAddress[i].GetLength();b++)
			addr[b]=ipAddress[i].GetAt(b);

	for(b;b<20;b++)
		addr[b]='\0';

	m_DlgPtr->ccChat.m_ConnectionSocket.Create();

	if(m_DlgPtr->ccChat.m_ConnectionSocket.Connect(addr,2000))
	{
		//AfxMessageBox("Client Connected");
	}
	
	
	m_DlgPtr->ccChat.DoModal();
	
	//m_DlgPtr->MessageBox(str);
}
