; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPro_slDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "pro_sl.h"

ClassCount=6
Class1=CPro_slApp
Class2=CPro_slDlg
Class3=CAboutDlg

ResourceCount=11
Resource1=IDR_MENU1 (Chinese (P.R.C.))
Resource2=IDR_MAINFRAME
Resource3=IDD_PRO_SL_DIALOG (Chinese (P.R.C.))
Resource4=IDD_ABOUTBOX (Chinese (P.R.C.))
Resource5=IDD_DIALOG1
Class4=CMyButton
Resource6=IDD_DIALOG2
Class5=info_Dialog
Resource7=IDD_DIALOG2 (Chinese (P.R.C.))
Class6=owndefine
Resource8=IDD_PRO_SL_DIALOG
Resource9=IDD_ABOUTBOX
Resource10=IDD_DIALOG1 (Chinese (P.R.C.))
Resource11=IDR_MENU1

[CLS:CPro_slApp]
Type=0
HeaderFile=pro_sl.h
ImplementationFile=pro_sl.cpp
Filter=N

[CLS:CPro_slDlg]
Type=0
HeaderFile=pro_slDlg.h
ImplementationFile=pro_slDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDD_ABOUTBOX

[CLS:CAboutDlg]
Type=0
HeaderFile=pro_slDlg.h
ImplementationFile=pro_slDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PRO_SL_DIALOG]
Type=1
Class=CPro_slDlg
ControlCount=6
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1073807360
Control4=IDC_TIME,button,1342275584
Control5=IDC_LAST,button,1342275584
Control6=IDC_STATIC12,static,1073872896

[DLG:IDD_PRO_SL_DIALOG (Chinese (P.R.C.))]
Type=1
Class=CPro_slDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1073807360
Control4=IDC_TIME,button,1342275584
Control5=IDC_LAST,button,1342275584

[DLG:IDD_ABOUTBOX (Chinese (P.R.C.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MENU1]
Type=1
Class=CPro_slDlg
Command1=IDC_BUTTON1
Command2=ID_EASY
Command3=ID_MID
Command4=ID_HARD
Command5=ID_OWN
Command6=ID_STATISTIC
Command7=IDCANCEL
Command8=IDD_ABOUTBOX
CommandCount=8

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
LastObject=CMyButton

[DLG:IDD_DIALOG1]
Type=1
Class=info_Dialog
ControlCount=22
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDCANCEL,button,1342242816
Control4=IDC_PLAY1,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BTIME1,static,1342308352
Control7=IDC_WIN1,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_PLAY2,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_WIN2,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_PLAY3,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_WIN3,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_BTIME2,static,1342308352
Control22=IDC_BTIME3,static,1342308352

[CLS:info_Dialog]
Type=0
HeaderFile=info_Dialog.h
ImplementationFile=info_Dialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_EASY

[DLG:IDD_DIALOG2]
Type=1
Class=owndefine
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_OK,button,1342242816
Control5=IDC_hang,edit,1350631552
Control6=IDC_lie,edit,1350631552
Control7=IDC_lei,edit,1350631552

[CLS:owndefine]
Type=0
HeaderFile=owndefine.h
ImplementationFile=owndefine.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_hang
VirtualFilter=dWC

[DLG:IDD_DIALOG1 (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_PLAY,static,1350701569
Control4=IDC_WIN,static,1350701569
Control5=IDC_BUTTON2,button,1342242816

[DLG:IDD_DIALOG2 (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_OK,button,1342242816
Control5=IDC_hang,edit,1350631552
Control6=IDC_lie,edit,1350631552
Control7=IDC_lei,edit,1350631552

[MNU:IDR_MENU1 (Chinese (P.R.C.))]
Type=1
Class=?
Command1=IDC_BUTTON1
Command2=ID_EASY
Command3=ID_MID
Command4=ID_HARD
Command5=ID_OWN
Command6=ID_STATISTIC
Command7=IDCANCEL
Command8=IDD_ABOUTBOX
CommandCount=8

