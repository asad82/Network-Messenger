// ServerConnections.cpp : implementation file
//
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		     : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include "stdafx.h"
#include "MircServer.h"
#include "ServerConnections.h"
#include "MircServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int totalConnections=0;
int totalUsers=0;
ServerConnections * saveThis[100];
UINT recordPeerPort[200];
CString recordPeerAddress[200];
CString recordScreenName[200];
SOCKADDR* lpSockAddr[200]; 
ServerConnections broadcast;
/////////////////////////////////////////////////////////////////////////////
// ServerConnections
extern CMircServerDlg *m_pDlg;

ServerConnections::ServerConnections()
{
	//totalConnections = 0;
	index=0;
	socketNumber = 1200;

}


ServerConnections::~ServerConnections()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(ServerConnections, CAsyncSocket)
	//{{AFX_MSG_MAP(ServerConnections)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// ServerConnections member functions

void ServerConnections::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if(m_pDlg->m_ListenSocket.Accept(m_pDlg->m_ConnectSocket[totalConnections],lpSockAddr[totalConnections] ))
	{
		;	//m_pDlg->m_Socket[totalConnections].Create(socketNumber++);	
			//m_pDlg->MessageBox("Connection established");
	}
	else
	{
		    m_pDlg->MessageBox("Connection can not be established");
	}

	if(!AfxSocketInit())
		m_pDlg->MessageBox("Failed to Initialize Sockets");

	m_pDlg->m_ConnectSocket[totalConnections].SetSockOpt(TCP_NODELAY,(const void *)100,sizeof(bool),IPPROTO_TCP);
	//saveThis[totalConnections++]=this;
	totalConnections++;
	//OnReceive(0);

	CAsyncSocket::OnAccept(nErrorCode);
}

void ServerConnections::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
		char  buff[200];
		CString str;
		CString peerAddress;
		UINT peerPort=0;

		//int rec=m_pDlg->m_ConnectSocket[index].Receive(buff,500);
		int rec=this->Receive(buff,200);
		buff[rec]='\0';

		if(buff[0]=='%'  &&  buff[1]=='%')
		{
			char tempBuf[30];
			char ipAddress[30];

			for(int i=2;i<30;i++)
				tempBuf[i-2]=buff[i];

			str.Format("%s",tempBuf);	
			m_pDlg->m_List1.AddString(str);
			this->GetPeerName(peerAddress,peerPort);
			m_pDlg->m_List2.AddString(peerAddress);
			m_pDlg->UpdateData(false);
			recordScreenName[totalUsers] = str;
			recordPeerAddress[totalUsers] = peerAddress;
			recordPeerPort[totalUsers++] = peerPort;
			goto LABEL;
			
		}
		else if (buff[0]=='L' && buff[1]=='i' && buff[2]=='s' && buff[3]=='t')
		{
			LABEL:
				UpdateClientOnlineList();	
			

		}// end of else if 
		else
		{
			// delete below this point

			this->GetPeerName(peerAddress,peerPort);
			
			for(int i=0;i<totalUsers;i++)
				if(peerAddress.Compare(recordPeerAddress[i])==0 && recordPeerPort[i]==peerPort)
					break;

			str.Format("%s> %s",recordScreenName[i],buff);
			m_pDlg->m_List3.AddString(str);
			m_pDlg->UpdateData(false);
			// seperate the data
			for(int j=0;j<str.GetLength();j++)
				buff[j]=str.GetAt(j);

			for(j=0;j<totalUsers;j++)
			{	//if(i!=j)								
				m_pDlg->m_ConnectSocket[j].Send(buff,str.GetLength());
					//this->SendTo(buff,str.GetLength(),lpSockAddr[j],sizeof(lpSockAddr[j]));
			}
			


		}// end of else bracket

// clear the buffer
		for(int c=0;c<200;c++)
			buff[c]='\0';


	CAsyncSocket::OnReceive(nErrorCode);
}

void ServerConnections::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
//	for(int i=0;i<totalConnections;i++)
//	{
//	char  * buff = "Hello there";
//	int rec=m_pDlg->m_ConnectSocket[index].Send(buff,20);
//	}

	CAsyncSocket::OnSend(nErrorCode);
}

void ServerConnections::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnConnect(nErrorCode);
}




/*	for(int m=0;m<totalUsers;m++)
			for(i=0;i<totalUsers;i++)
			{
				tempBuf[0]='%';tempBuf[1]='-';
				for(int j=2;j<recordScreenName[i].GetLength()+2;j++)
				{
					//tempBuf[j]='\0';
					tempBuf[j]=recordScreenName[i].GetAt(j-2);
				}
				
				m_pDlg->m_ConnectSocket[m].Send(tempBuf,11);

				ipAddress[0]='%';ipAddress[1]='*';
				for(j=2;j<recordPeerAddress[i].GetLength()+2;j++)
				{
					//ipAddress[j]='\0';
					ipAddress[j]=recordPeerAddress[i].GetAt(j-2);
				}
				
				m_pDlg->m_ConnectSocket[m].Send(ipAddress,9);

				
//				this->Send(tempBuf,recordScreenName[i].GetLength()+2);
//				this->Send(ipAddress,recordPeerAddress[i].GetLength()+2);
//				for(int k=0;k<totalUsers;k++)
//				{
					m_pDlg->m_ConnectSocket[m].Send(tempBuf,recordScreenName[i].GetLength()+2);
					m_pDlg->m_ConnectSocket[m].Send(ipAddress,recordPeerAddress[i].GetLength()+2);

//					m_pDlg->m_ConnectSocket[k].SendTo(tempBuf,recordScreenName[i].GetLength()+2,recordPeerPort[k],"127.0.0.1");//.Send(tempBuf,30);
//					m_pDlg->m_ConnectSocket[k].SendTo(ipAddress,recordPeerAddress[i].GetLength()+2,recordPeerPort[k],"127.0.0.1");//.Send(ipAddress,30);

//					m_pDlg->m_ConnectSocket[k].SendTo(tempBuf,recordScreenName[i].GetLength()+2,lpSockAddr[k],sizeof(lpSockAddr[k]));//.Send(tempBuf,30);
//					m_pDlg->m_ConnectSocket[k].SendTo(ipAddress,recordPeerAddress[i].GetLength()+2,lpSockAddr[k],sizeof(lpSockAddr[k]));//.Send(ipAddress,30);

//				}
			}// end of for loop
			*/






//				this->Send(tempBuf,recordScreenName[i].GetLength()+2);
//				this->Send(ipAddress,recordPeerAddress[i].GetLength()+2);
//				for(int k=0;k<totalUsers;k++)
//				{
//					m_pDlg->m_ConnectSocket[m].Send(tempBuf,recordScreenName[i].GetLength()+2);
//					m_pDlg->m_ConnectSocket[m].Send(ipAddress,recordPeerAddress[i].GetLength()+2);

//					m_pDlg->m_ConnectSocket[k].SendTo(tempBuf,recordScreenName[i].GetLength()+2,recordPeerPort[k],"127.0.0.1");//.Send(tempBuf,30);
//					m_pDlg->m_ConnectSocket[k].SendTo(ipAddress,recordPeerAddress[i].GetLength()+2,recordPeerPort[k],"127.0.0.1");//.Send(ipAddress,30);

//					m_pDlg->m_ConnectSocket[k].SendTo(tempBuf,recordScreenName[i].GetLength()+2,lpSockAddr[k],sizeof(lpSockAddr[k]));//.Send(tempBuf,30);
//					m_pDlg->m_ConnectSocket[k].SendTo(ipAddress,recordPeerAddress[i].GetLength()+2,lpSockAddr[k],sizeof(lpSockAddr[k]));//.Send(ipAddress,30);

//				}



void ServerConnections::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString peerAddress;
	UINT peerPort;

	this->GetPeerName(peerAddress,peerPort);
	this->Close();
	
	for(int i=0;i<totalUsers;i++)
	{
		if(recordPeerAddress[i].Compare(peerAddress)==0 && recordPeerPort[i] == peerPort)
		{
			recordPeerAddress[i]="NULL";
			recordPeerPort[i]=-1;
			recordScreenName[i] ="NULL";
		}

	}
	

	// clear the list 
	for(i=0;i<100;i++)
	{
		m_pDlg->m_List2.DeleteString(0);
		m_pDlg->m_List1.DeleteString(0);
	}
	

	for(i=0;i<totalUsers;i++)
	{
		if(recordPeerAddress[i].Compare("NULL")!=0 && recordScreenName[i].Compare("NULL")!=0 && recordPeerPort[i]!=-1)
		{
			m_pDlg->m_List1.AddString(recordScreenName[i]);
			m_pDlg->m_List2.AddString(recordPeerAddress[i]);
		}

	}

	m_pDlg->UpdateData(false);
	
	UpdateClientOnlineList();

	CAsyncSocket::OnClose(nErrorCode);
}

void ServerConnections::UpdateClientOnlineList()
{

			char tempBuf[1024];
			//char ipAddress[30];

			for(int s=0;s<1024;s++)
				tempBuf[s]='*';

			for(int r=0;r<totalUsers;r++)
			{
				m_pDlg->m_ConnectSocket[r].Send(tempBuf,1024);
			}

			for(int t=0;t<totalConnections;t++)
			{
				for(int i=0;i<totalUsers;i++)
				{
					tempBuf[0]='%';tempBuf[1]='@';
					for(int j=2;j<recordScreenName[i].GetLength()+2;j++)
					{
						
						tempBuf[j]=recordScreenName[i].GetAt(j-2);
					}
					
					//this->Send(tempBuf,recordScreenName[i].GetLength()+2);
					int val=j;
					tempBuf[val]='%';tempBuf[val+1]='&';
					for(j=val+2;j<val+2+recordPeerAddress[i].GetLength();j++)
					{
						
						tempBuf[j]=recordPeerAddress[i].GetAt((j-2-val));
					}
					tempBuf[j]='/';
					m_pDlg->m_ConnectSocket[t].Send(tempBuf,1024);//recordPeerAddress[i].GetLength()+4+recordScreenName[i].GetLength());
				}
			}


}// end of functions
