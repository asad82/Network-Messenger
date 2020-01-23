#if !defined(AFX_FILESOCKET_H__D4258F21_56DE_11D9_B5E0_D7AC80FBCA23__INCLUDED_)
#define AFX_FILESOCKET_H__D4258F21_56DE_11D9_B5E0_D7AC80FBCA23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// FileSocket command target

class FileSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	FileSocket();
	virtual ~FileSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(FileSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(FileSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
public:
	CFile filePtr;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILESOCKET_H__D4258F21_56DE_11D9_B5E0_D7AC80FBCA23__INCLUDED_)
