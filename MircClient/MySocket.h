#if !defined(AFX_MYSOCKET_H__E149C52F_EEED_4A2B_B732_C51C917C1D88__INCLUDED_)
#define AFX_MYSOCKET_H__E149C52F_EEED_4A2B_B732_C51C917C1D88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// MySocket command target

class MySocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	MySocket();
	virtual ~MySocket();

// Overrides
public:
	void ClientClientChat();
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MySocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(MySocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKET_H__E149C52F_EEED_4A2B_B732_C51C917C1D88__INCLUDED_)
