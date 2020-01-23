// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__010B0374_BAF1_4210_8324_E76A864BC47D__INCLUDED_)
#define AFX_CLIENTDLG_H__010B0374_BAF1_4210_8324_E76A864BC47D__INCLUDED_

#include "MySocket.h"
#include "CDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor

	MySocket m_ClientSock;
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CListBox	m_ListOnline;
	CListBox	m_ListMsgs;
	CString	m_Address;
	UINT	m_Port;
	CString	m_SendMsg;
	CString	m_NickName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnConnect();
	afx_msg void OnBtnSend();
	afx_msg void OnGetlist();
	afx_msg void OnDblclkListonline();
	afx_msg void OnBtnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CCDialog ccChat;
	CCDialog ccChat2;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__010B0374_BAF1_4210_8324_E76A864BC47D__INCLUDED_)
