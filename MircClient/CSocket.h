#if !defined(AFX_CSOCKET_H__9E84BF42_56A6_11D9_B5E0_E874EFB06723__INCLUDED_)
#define AFX_CSOCKET_H__9E84BF42_56A6_11D9_B5E0_E874EFB06723__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CCSocket command target

class CCSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CCSocket();
	virtual ~CCSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSOCKET_H__9E84BF42_56A6_11D9_B5E0_E874EFB06723__INCLUDED_)
