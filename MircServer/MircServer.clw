; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=ServerConnections
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MircServer.h"

ClassCount=4
Class1=CMircServerApp
Class2=CMircServerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=ServerConnections
Resource3=IDD_MIRCSERVER_DIALOG

[CLS:CMircServerApp]
Type=0
HeaderFile=MircServer.h
ImplementationFile=MircServer.cpp
Filter=N

[CLS:CMircServerDlg]
Type=0
HeaderFile=MircServerDlg.h
ImplementationFile=MircServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CLIENTNAMESLIST

[CLS:CAboutDlg]
Type=0
HeaderFile=MircServerDlg.h
ImplementationFile=MircServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MIRCSERVER_DIALOG]
Type=1
Class=CMircServerDlg
ControlCount=15
Control1=IDC_LISTEN,button,1342242816
Control2=IDC_IPADDRESS,edit,1350631552
Control3=IDC_SOCKET,edit,1350631552
Control4=IDC_EXIT,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CLIENTNAMESLIST,listbox,1352728833
Control10=IDC_CLIENTIPADDRESSESLIST,listbox,1352728833
Control11=IDC_MESSAGES,listbox,1352728833
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[CLS:ServerConnections]
Type=0
HeaderFile=ServerConnections.h
ImplementationFile=ServerConnections.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=ServerConnections

