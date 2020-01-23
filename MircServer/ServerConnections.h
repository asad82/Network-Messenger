#if !defined(AFX_SERVERCONNECTIONS_H__BCEF4D34_0C4E_41C6_A81B_A6A6281489DF__INCLUDED_)
#define AFX_SERVERCONNECTIONS_H__BCEF4D34_0C4E_41C6_A81B_A6A6281489DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerConnections.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// ServerConnections command target

class ServerConnections : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	ServerConnections();
	virtual ~ServerConnections();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ServerConnections)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(ServerConnections)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
public:
	void UpdateClientOnlineList();
//	int totalConnections;
	

	int socketNumber;
	int index;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERCONNECTIONS_H__BCEF4D34_0C4E_41C6_A81B_A6A6281489DF__INCLUDED_)
