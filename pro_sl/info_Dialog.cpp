// info_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "pro_sl.h"
#include "info_Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// info_Dialog dialog


info_Dialog::info_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(info_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(info_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void info_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(info_Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	CString total1,total2,total3;
    CString win1,win2,win3;
    CString btime1,btime2,btime3;
    GetPrivateProfileString("Easy","Total","0",total1.GetBuffer(10),10,"C:\\memory.ini"); 
	GetPrivateProfileString("Easy","Win","0",win1.GetBuffer(10),10,"D:\\C:\\memory.ini");
	GetPrivateProfileString("Easy","Best time","0",btime1.GetBuffer(10),10,"D:\\C:\\memory.ini");
    
	GetPrivateProfileString("Middle","Total","0",total2.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Middle","Win","0",win2.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Middle","Best time","0",btime2.GetBuffer(10),10,"C:\\memory.ini");
	
	GetPrivateProfileString("Hard","Total","0",total3.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Hard","Win","0",win3.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Hard","Best time","0",btime3.GetBuffer(10),10,"C:\\memory.ini");

    SetDlgItemText(IDC_PLAY1,total1);
	SetDlgItemText(IDC_WIN1,win1);
	SetDlgItemText(IDC_BTIME1,btime1);

	SetDlgItemText(IDC_PLAY2,total2);
	SetDlgItemText(IDC_WIN2,win2);
	SetDlgItemText(IDC_BTIME2,btime2);

	SetDlgItemText(IDC_PLAY3,total3);
	SetDlgItemText(IDC_WIN3,win3);
	SetDlgItemText(IDC_BTIME3,btime3);
}


BEGIN_MESSAGE_MAP(info_Dialog, CDialog)
	//{{AFX_MSG_MAP(info_Dialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// info_Dialog message handlers
