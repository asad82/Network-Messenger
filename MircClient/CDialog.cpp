// CDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "CDialog.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CClientDlg * m_DlgPtr;
/////////////////////////////////////////////////////////////////////////////
// CCDialog dialog


CCDialog::CCDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCDialog)
	m_Message = _T("");
	//}}AFX_DATA_INIT
}


void CCDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCDialog)
	DDX_Control(pDX, IDC_MESSAGESLIST, m_List1);
	DDX_Text(pDX, IDC_EDITMESSAGE, m_Message);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCDialog, CDialog)
	//{{AFX_MSG_MAP(CCDialog)
	ON_BN_CLICKED(IDC_BUTTONSEND, OnButtonsend)
	ON_BN_CLICKED(IDC_SELECTFILE, OnSelectfile)
	ON_BN_CLICKED(IDC_SENDFILE, OnSendfile)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDialog message handlers

void CCDialog::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CCDialog::OnButtonsend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_ConnectionSocket.Send(m_Message,m_Message.GetLength());
	CString str;
	str.Format("%s",m_Message);
	m_List1.AddString(str);
	m_Message="";
	UpdateData(false);
	
	
}

void CCDialog::OnSelectfile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDialog(true);
	fileName="";
	if(fileDialog.DoModal()==IDOK)
	{
		fileName = fileDialog.GetFileName();	
		filePathName=fileDialog.GetPathName();
			//fileName+='\\';	
	}
}// end of function

void CCDialog::OnSendfile() 
{
	// TODO: Add your control notification handler code here
	CString peerAddress;
	UINT peerPort;

	m_fConnectionSocket.Create();

	m_DlgPtr->ccChat.m_ConnectionSocket.GetPeerName(peerAddress,peerPort);

	if(m_fConnectionSocket.Connect(peerAddress,1500))
	{
		//AfxMessageBox("Client Connected");
	}

	filePtr1.Open(filePathName,CFile::modeRead,NULL);

	DWORD length = filePtr1.GetLength();
	
	char * buf;
	buf = new char[length];
	filePtr1.Read(buf,length);

	m_fConnectionSocket.Send(buf,length);
	filePtr1.Close();	

	m_fConnectionSocket.Close();

}

int CCDialog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	

	return 0;
}
