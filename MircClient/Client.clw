; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCDialog
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Client.h"

ClassCount=7
Class1=CClientApp
Class2=CClientDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=MySocket
Resource3=IDD_CLIENT_DIALOG
Class5=CCDialog
Class6=CCSocket
Class7=FileSocket
Resource4=IDD_DIALOG1

[CLS:CClientApp]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D
LastObject=CClientDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=17
Control1=IDC_EDIT_NICKNAME,edit,1350631552
Control2=IDC_EDIT_ADDRESS,edit,1350631552
Control3=IDC_EDIT_PORT,edit,1350631552
Control4=IDC_EDIT_SENDMSG,edit,1350631552
Control5=IDC_BTN_SEND,button,1342242816
Control6=IDC_LISTONLINE,listbox,1352728833
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BTN_CONNECT,button,1342242816
Control10=IDC_LISTMSG,listbox,1352728833
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_BTN_CLOSE,button,1342242816
Control14=IDC_STATIC,button,1342177287
Control15=IDC_GETLIST,button,1073807360
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,static,1342308352

[CLS:MySocket]
Type=0
HeaderFile=MySocket.h
ImplementationFile=MySocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=MySocket

[DLG:IDD_DIALOG1]
Type=1
Class=CCDialog
ControlCount=9
Control1=IDOK,button,1073807361
Control2=IDC_MESSAGESLIST,listbox,1352728833
Control3=IDC_EDITMESSAGE,edit,1350631552
Control4=IDC_BUTTONSEND,button,1342242816
Control5=IDC_SENDFILE,button,1342242816
Control6=IDC_SELECTFILE,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287

[CLS:CCDialog]
Type=0
HeaderFile=CDialog.h
ImplementationFile=CDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CCDialog
VirtualFilter=dWC

[CLS:CCSocket]
Type=0
HeaderFile=CSocket.h
ImplementationFile=CSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CCSocket

[CLS:FileSocket]
Type=0
HeaderFile=FileSocket.h
ImplementationFile=FileSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=FileSocket

