; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyFrameDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyFrame.h"

ClassCount=4
Class1=CMyFrameApp
Class2=CMyFrameDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_MYFRAME_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDR_MENU
Resource4=IDD_ABOUTBOX
Resource5=IDD_dlg_histogram
Class4=CDlgHistogram
Resource6=IDR_TOOLBAR

[CLS:CMyFrameApp]
Type=0
HeaderFile=MyFrame.h
ImplementationFile=MyFrame.cpp
Filter=N
LastObject=CMyFrameApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMyFrameDlg]
Type=0
HeaderFile=MyFrameDlg.h
ImplementationFile=MyFrameDlg.cpp
Filter=D
LastObject=ID_HISTOGRAM
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MyFrameDlg.h
ImplementationFile=MyFrameDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYFRAME_DIALOG]
Type=1
Class=CMyFrameDlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC_KEYIMAGE,static,1342177287
Control4=IDC_LIST_RESULT,listbox,1352728835
Control5=IDC_STATIC_FOUNDIMAGE,static,1342177287
Control6=IDC_STATIC_IMAGE1,static,1342177287
Control7=IDC_STATIC_IMAGE2,static,1342177287
Control8=IDC_STATIC_IMAGE3,static,1342177287
Control9=IDC_STATIC_IMAGE4,static,1342177287
Control10=IDC_STATIC_IMAGE5,static,1342177287
Control11=IDC_STATIC_IMAGE6,static,1342177287
Control12=IDC_STATIC_IMAGE7,static,1342177287
Control13=IDC_STATIC_IMAGE8,static,1342177287
Control14=IDC_STATIC_IMAGE9,static,1342177287
Control15=IDC_STATIC_IMAGE10,static,1342177287
Control16=IDC_STATIC_IMAGE11,static,1342177287
Control17=IDC_STATIC_IMAGE12,static,1342177287
Control18=IDC_STATIC_TOTAL,static,1342308352
Control19=IDC_STATIC,static,1342308352

[MNU:IDR_MENU]
Type=1
Class=CMyFrameDlg
Command1=ID_OpenImage
Command2=ID_EXIT
Command3=ID_CBIR_DIR
Command4=ID_CBIR_DATEBASE
Command5=ID_UPLOAD_IMAGE
Command6=ID_UPLOAD_IMAGE_ALL
Command7=ID_HISTOGRAM
Command8=ID_ABOUT
CommandCount=8

[TB:IDR_TOOLBAR]
Type=1
Class=?
Command1=ID_OpenImage
CommandCount=1

[DLG:IDD_dlg_histogram]
Type=1
Class=CDlgHistogram
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COORD,static,1342308352

[CLS:CDlgHistogram]
Type=0
HeaderFile=DlgHistogram.h
ImplementationFile=DlgHistogram.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgHistogram

