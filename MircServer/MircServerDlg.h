// MircServerDlg.h : header file
//

#if !defined(AFX_MIRCSERVERDLG_H__D7388FC7_5452_11D9_B5E0_997058A15823__INCLUDED_)
#define AFX_MIRCSERVERDLG_H__D7388FC7_5452_11D9_B5E0_997058A15823__INCLUDED_

#include "ServerConnections.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMircServerDlg dialog

class CMircServerDlg : public CDialog
{
// Construction
public:
	CMircServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMircServerDlg)
	enum { IDD = IDD_MIRCSERVER_DIALOG };
	CListBox	m_List3;
	CListBox	m_List2;
	CListBox	m_List1;
	CString	m_IPAddress;
	int		m_Port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMircServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMircServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnListen();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	ServerConnections m_ListenSocket;
	ServerConnections m_ConnectSocket[100];
	ServerConnections m_Socket[100];

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIRCSERVERDLG_H__D7388FC7_5452_11D9_B5E0_997058A15823__INCLUDED_)
