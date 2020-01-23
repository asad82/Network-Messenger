#if !defined(AFX_CDIALOG_H__9E84BF41_56A6_11D9_B5E0_E874EFB06723__INCLUDED_)
#define AFX_CDIALOG_H__9E84BF41_56A6_11D9_B5E0_E874EFB06723__INCLUDED_

#include "CSocket.h"
#include "FileSocket.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCDialog dialog

class CCDialog : public CDialog
{
// Construction
public:
	CCDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCDialog)
	enum { IDD = IDD_DIALOG1 };
	CListBox	m_List1;
	CString	m_Message;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCDialog)
	virtual void OnOK();
	afx_msg void OnButtonsend();
	afx_msg void OnSelectfile();
	afx_msg void OnSendfile();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CCSocket m_ListenSocket;
	CCSocket m_ConnectionSocket;
	
	FileSocket m_fListenSocket;
	FileSocket m_fConnectionSocket;

	CString fileName;
	CString filePathName;
	CString saveFilePathName;
	CFile filePtr1;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDIALOG_H__9E84BF41_56A6_11D9_B5E0_E874EFB06723__INCLUDED_)
