// pro_slDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "pro_sl.h"
#include "pro_slDlg.h"
#include"info_Dialog.h"
#include"owndefine.h"
#include <stdlib.h>
#include <ctime>
#include <cstring>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
     
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPro_slDlg dialog

CPro_slDlg::CPro_slDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPro_slDlg::IDD, pParent)
{    
    //current=map_boomall; 

	//{{AFX_DATA_INIT(CPro_slDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	ctime=0;
	allgame=0;winnum=0;state=2;
}

void CPro_slDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPro_slDlg)
	DDX_Control(pDX, IDCANCEL, m_Cancel);
	DDX_Control(pDX, IDC_TIME, m_Time);
	DDX_Control(pDX, IDC_LAST, m_Last);
	DDX_Control(pDX, IDC_BUTTON1, m_NewGame);
	DDX_Control(pDX, IDC_BUTTON2, m_FOCUS);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPro_slDlg, CDialog)
	//{{AFX_MSG_MAP(CPro_slDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	ON_COMMAND(ID_EASY, OnEasy)
	ON_COMMAND(ID_HARD, OnHard)
	ON_COMMAND(ID_MID, OnMid)
	ON_COMMAND(ID_STATISTIC, OnStatistic)
	ON_COMMAND(ID_OWN, OnOwn)
	ON_COMMAND(IDD_ABOUTBOX, OnAboutbox)
	//}}AFX_MSG_MAP
	ON_REGISTERED_MESSAGE(WM_MYBUTTONRC,OnMyButtonRC)
	ON_REGISTERED_MESSAGE(WM_MYBUTTONRLC,OnMyButtonRLC)
	ON_CONTROL_RANGE(BN_CLICKED,2001,2401,OnBoomBTN)
END_MESSAGE_MAP()
	afx_msg void OnBoomBTN(UINT nID);
/////////////////////////////////////////////////////////////////////////////
// CPro_slDlg message handlers

BOOL CPro_slDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	hIcon1=AfxGetApp()->LoadIcon(IDI_ICON1);
	hIcon2=AfxGetApp()->LoadIcon(IDI_ICON2);
	hIcon3=AfxGetApp()->LoadIcon(IDI_ICON3);
	hIcon4=AfxGetApp()->LoadIcon(IDI_ICON4);
	hIcon5=AfxGetApp()->LoadIcon(IDI_ICON5);
	hIcon6=AfxGetApp()->LoadIcon(IDI_ICON6);
	hIcon7=AfxGetApp()->LoadIcon(IDI_ICON7);
	hIcon8=AfxGetApp()->LoadIcon(IDI_ICON8);
	hIcon9=AfxGetApp()->LoadIcon(IDI_ICON9);
	hIconC=AfxGetApp()->LoadIcon(IDI_ICONCLEAR);
	hIconI=AfxGetApp()->LoadIcon(IDI_ICON10);
	hIconX=AfxGetApp()->LoadIcon(IDI_ICON11);
	map_h=16;map_w=16;map_boomall=40;
	for(int i=1;i<=399;i++)BoomBTN[i]=NULL;
	init();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPro_slDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPro_slDlg::OnPaint() 
{  // SetDlgItemText(IDC_LAST,numstr(map_boomall));
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPro_slDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int CPro_slDlg::init()
{   
	int i,j,k=0,a,b;CString t;
	ctime=0;nCount=0;win=0;current=map_boomall;
	int sc=32,py=0;//按钮大小
	for(i=1;i<=map_h;i++)for(j=1;j<=map_w;j++){map[i][j]=0;ismap[i][j]=1;ismapa[i][j]=0;}
	SetDlgItemText(IDC_LAST,numstr(map_boomall));
	//设置窗口大小
	CWnd *p=AfxGetMainWnd();
	long nWei,nHei;
	nWei=map_h*sc+64-py;nHei=map_w*sc+130;
	p->SetWindowPos(NULL,0,0,nWei,nHei,SWP_NOZORDER|SWP_NOMOVE);
	m_Last.SetWindowPos(NULL,10,0,50,32,SWP_NOZORDER);
	m_Time.SetWindowPos(NULL,nWei-70,0,50,32,SWP_NOZORDER);
	m_NewGame.SetWindowPos(NULL,nWei/2-70,nHei-90,50,32,SWP_NOZORDER);
	m_Cancel.SetWindowPos(NULL,nWei/2+10,nHei-90,50,32,SWP_NOZORDER);
	GetDlgItem(IDC_STATIC12)->SetWindowPos(NULL,60,0,50,32,SWP_NOZORDER);
	//动态生成按钮
	for(i=1;i<=map_h;i++)
		for(j=1;j<=map_w;j++){
			k+=1;
			BoomBTN[k] = new CMyButton;
			BoomBTN[k]->Create("", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_ICON, CRect(i*sc-py,j*sc-py,(i+1)*sc-py,(j+1)*sc-py), this, 2000+k);
			BoomBTN[k]->EnableWindow(FALSE);
		}
	i=1;//开始随机生成雷
	srand((unsigned)time(NULL));
	while(i<=map_boomall){
		a=(rand()%map_h)+1;b=(rand()%map_w)+1;
		if(map[a][b]!=-1){
			map[a][b]=-1;
			if(map[a-1][b-1]!=-1)map[a-1][b-1]+=1;
			if(map[a-1][b]!=-1)map[a-1][b]+=1;
			if(map[a-1][b+1]!=-1)map[a-1][b+1]+=1;
			if(map[a][b-1]!=-1)map[a][b-1]+=1;
			if(map[a][b]!=-1)map[a][b]+=1;
			if(map[a][b+1]!=-1)map[a][b+1]+=1;
			if(map[a+1][b-1]!=-1)map[a+1][b-1]+=1;
			if(map[a+1][b]!=-1)map[a+1][b]+=1;
			if(map[a+1][b+1]!=-1)map[a+1][b+1]+=1;
			i++;
		}
	}
	for(i=1;i<=k;i++)BoomBTN[i]->EnableWindow(TRUE);
	return 0;
}


void CPro_slDlg::OnButton1() 
{
	m_NewGame.EnableWindow(FALSE);
	for(int i=1;i<=map_w*map_h;i++)if(BoomBTN[i])delete BoomBTN[i];
	init();
	m_NewGame.EnableWindow(TRUE);
}

CString CPro_slDlg::numstr(int n)
{
	static CString c="";
	if(n<0){
		n=n*-1;
		c="-"+numstr(n);
		return c;
	}
	if(n<10)
	{
	    c=(char)(n%10+'0');
	    return c;
	}
	else
	{
		c=numstr(n/10)+(char)(n%10+'0');
		return c;
	}
}


void CPro_slDlg::OnBoomBTN(UINT nID)
{   
	if(ctime==0)	SetTimer(IDC_TIME,1000,NULL);
	int n=nID-2000;
	int x,y;
	y=n%map_w;if(y==0)y=map_w;
	x=(n+map_w-1)/map_w;
	if(map[x][y]==-1)gameover(1,nID);
	if((map[x][y]!=-1)&&(ismapa[x][y]==0)){
		expand(x,y,0);
	}
}

void CPro_slDlg::gameover(int n,int nID){   

	if(n==1){
		int x,y;
		for(x=1;x<=map_h;x++)
			for(y=1;y<=map_w;y++){
				int t=(x-1)*map_w+y;
				BoomBTN[t]->EnableWindow(FALSE);
				if(map[x][y]==-1){
					BoomBTN[t]->SetIcon(hIcon9);
				}
			}
		allgame+=1;
		tongji(map_boomall);
		ctime=-1;
		MessageBox("Over");
	}
	if(n==2){
		int x,y;
		for(x=1;x<=map_h;x++)
			for(y=1;y<=map_w;y++){
				int t=(x-1)*map_w+y;
				BoomBTN[t]->EnableWindow(FALSE);
			}
		SetDlgItemText(IDC_LAST,"0");
		winnum+=1;
		win=1;
		allgame+=1;
		tongji(map_boomall);
		ctime=-1;
		MessageBox("Success");
	}

}

void CPro_slDlg::seterror(int x, int y)
{
	int k=(x-1)*map_w+y;
	BoomBTN[k]->SetIcon(hIconX);
}

void CPro_slDlg::expand(int x, int y,int si=0)
{
	if(ismap[x][y]==1||si==1){
	int k=(x-1)*map_w+y;
	if(x<=0||x>map_h)return;
	if(y<=0||y>map_w)return;
	if(si==1){
		int a=0;
		if(ismapa[x-1][y-1]==1&&map[x-1][y-1]!=-1){seterror(x-1,y-1);a=1;}
		if(ismapa[x][y-1]==1&&map[x][y-1]!=-1){seterror(x,y-1);a=1;}
		if(ismapa[x+1][y-1]==1&&map[x+1][y-1]!=-1){seterror(x+1,y-1);a=1;}
		if(ismapa[x-1][y]==1&&map[x-1][y]!=-1){seterror(x-1,y);a=1;}
		if(ismapa[x+1][y]==1&&map[x+1][y]!=-1){seterror(x+1,y);a=1;}
		if(ismapa[x-1][y+1]==1&&map[x-1][y+1]!=-1){seterror(x-1,y+1);a=1;}
		if(ismapa[x][y+1]==1&&map[x][y+1]!=-1){seterror(x,y+1);a=1;}
		if(ismapa[x+1][y+1]==1&&map[x+1][y+1]!=-1){seterror(x+1,y+1);a=1;}
		if(a==1){gameover(1,k+2000);return;}
	}
	if(map[x][y]==-1)return;
	switch (map[x][y]){
		case 1:BoomBTN[k]->SetIcon(hIcon1);break;
		case 2:BoomBTN[k]->SetIcon(hIcon2);break;
		case 3:BoomBTN[k]->SetIcon(hIcon3);break;
		case 4:BoomBTN[k]->SetIcon(hIcon4);break;
		case 5:BoomBTN[k]->SetIcon(hIcon5);break;
		case 6:BoomBTN[k]->SetIcon(hIcon6);break;
		case 7:BoomBTN[k]->SetIcon(hIcon7);break;
		case 8:BoomBTN[k]->SetIcon(hIcon8);break;
		case 0:BoomBTN[k]->SetIcon(hIconI);break;
	}
	BoomBTN[k]->ModifyStyle(1,BS_FLAT);
	BoomBTN[k]->Invalidate(FALSE);
	ismap[x][y]=0;
	m_FOCUS.SetFocus();
	if(si==0)nCount++;
	if(map[x][y]==0||si==1){
		if(ismapa[x-1][y-1]==0)expand(x-1,y-1);
		if(ismapa[x][y-1]==0)expand(x,y-1);
		if(ismapa[x+1][y-1]==0)expand(x+1,y-1);
		if(ismapa[x-1][y]==0)expand(x-1,y);
		if(ismapa[x+1][y]==0)expand(x+1,y);
		if(ismapa[x-1][y+1]==0)expand(x-1,y+1);
		if(ismapa[x][y+1]==0)expand(x,y+1);
		if(ismapa[x+1][y+1]==0)expand(x+1,y+1);
	}
	}
	return;
}


void CPro_slDlg::OnMyButtonRC(WPARAM nID,LPARAM t)
{	
	int n=nID-2000;
	int x,y;
	y=n%map_w;if(y==0)y=map_w;
	x=(n+map_w-1)/map_w;
	if(ismap[x][y]==1){
		//add operation
		switch (ismapa[x][y]){
		case 0:BoomBTN[n]->SetIcon(hIcon9);ismapa[x][y]=1;current-=1;SetDlgItemText(IDC_LAST,numstr(current));break;
		case 1:BoomBTN[n]->SetIcon(hIconC);ismapa[x][y]=0;current+=1;SetDlgItemText(IDC_LAST,numstr(current));break;
		}
		UpdateData(false);
	}

}

void CPro_slDlg::OnMyButtonRLC(WPARAM nID,LPARAM t){
	int n=nID-2000;
	int x,y,nc=0;
	y=n%map_w;if(y==0)y=map_w;
	x=(n+map_w-1)/map_w;
	if(ismapa[x-1][y-1]==1)nc++;if(ismapa[x][y-1]==1)nc++;if(ismapa[x+1][y-1]==1)nc++;
	if(ismapa[x-1][y]==1)nc++;if(ismapa[x][y]==1)nc++;if(ismapa[x+1][y]==1)nc++;
	if(ismapa[x-1][y+1]==1)nc++;if(ismapa[x][y+1]==1)nc++;if(ismapa[x+1][y+1]==1)nc++;
	if(nc==map[x][y])expand(x,y,1);
}

void CPro_slDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	SetDlgItemText(IDC_STATIC12,numstr(nCount));
	if(ctime!=-1){
	ctime+=1;
	CString T=numstr(ctime);
    SetDlgItemText(IDC_TIME,T);
	UpdateData(false);
	}
	if(nCount==map_w*map_h-map_boomall){
		nCount++;
		gameover(2,2000);
	}
	CDialog::OnTimer(nIDEvent);
}

void CPro_slDlg::OnEasy() 
{
	// TODO: Add your command handler code here
	m_NewGame.EnableWindow(TRUE);
	int i,t=map_h*map_w;
	for(i=1;i<=t;i++)if(BoomBTN[i])delete BoomBTN[i];
	map_h=9;map_w=9;map_boomall=10;
	init();
	state=1;
}

void CPro_slDlg::OnMid() 
{
	// TODO: Add your command handler code here
	m_NewGame.EnableWindow(TRUE);

	int i,t=map_h*map_w;
	for(i=1;i<=t;i++)if(BoomBTN[i])delete BoomBTN[i];
	map_h=16;map_w=16;map_boomall=40;
	init();
	state=2;
}

void CPro_slDlg::OnHard() 
{
	// TODO: Add your command handler code here
	m_NewGame.EnableWindow(TRUE);

	int i,t=map_h*map_w;
	for(i=1;i<=t;i++)if(BoomBTN[i])delete BoomBTN[i];
	map_h=19;map_w=19;map_boomall=99;
	init();
	state=3;
}

void CPro_slDlg::OnStatistic() 
{
	// TODO: Add your command handler code here
	int i,t=map_h*map_w;
	for(i=1;i<=t;i++)if(BoomBTN[i])delete BoomBTN[i];
    info_Dialog infodlg; 
    infodlg.DoModal(); 
	init(); 

}

void CPro_slDlg::OnOwn() 
{
	// TODO: Add your command handler code here
	m_NewGame.EnableWindow(FALSE);

	int i,t=map_h*map_w;
	for(i=1;i<=t;i++)if(BoomBTN[i])delete BoomBTN[i];
	owndefine own; 
    own.DoModal(); 
	map_w=own.m_hang;
    map_h=own.m_lie;
	map_boomall=own.m_lei;
	if(map_w<=19&&map_h<=19)init();

	else{
		MessageBox("行数或列数超过最大值","出错啦");
		m_NewGame.EnableWindow(FALSE);
	}
}

void CPro_slDlg::tongji(int boom)
{   

	CString total1,total2,total3;
    CString win1,win2,win3;
    CString btime1,btime2,btime3;
	if(state==1){
    GetPrivateProfileString("Easy","Total","",total1.GetBuffer(10),10,"C:\\memory.ini"); 
	GetPrivateProfileString("Easy","Win","",win1.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Easy","Best time","",btime1.GetBuffer(10),10,"C:\\memory.ini");
    int a=atoi(total2);
		a=a+allgame;
		total1=numstr(a);
	int b=atoi(win2);
	b=b+winnum;
	win1=numstr(b);
	int c=atoi(btime2);
	c=c<=ctime?c:ctime;
	btime1=numstr(c);
	if(c!=0){
		c=c<ctime?c:ctime;
		btime1=numstr(c);
	}
	else btime1=numstr(ctime);
	}
	else if(state==2){
	GetPrivateProfileString("Middle","Total","",total2.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Middle","Win","",win2.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Middle","Best time","",btime2.GetBuffer(10),10,"C:\\memory.ini");
	int a=atoi(total2);
		a=a+allgame;
		total2=numstr(a);
	int b=atoi(win2);
	b=b+winnum;
	win2=numstr(b);
	int c=atoi(btime2);
    if(win==1){
		if(c!=0){
		c=c<ctime?c:ctime;
		btime3=numstr(c);
		}
	else btime3=numstr(ctime);
	}
}
	else if(state==3){
	GetPrivateProfileString("Hard","Total","",total3.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Hard","Win","",win3.GetBuffer(10),10,"C:\\memory.ini");
	GetPrivateProfileString("Hard","Best time","",btime3.GetBuffer(10),10,"C:\\memory.ini");
	int a=atoi(total2);
		a=a+allgame;
		total3=numstr(a);
	int b=atoi(win2);
	b=b+winnum;
	win3=numstr(b);
	int c=atoi(btime2);
    if(win==1){
		if(c!=0){
		c=c<ctime?c:ctime;
		btime3=numstr(c);
		}
	else btime3=numstr(ctime);
	}

	}



	if(state==1){
    WritePrivateProfileString("Easy","Total",total1,"C:\\memory.ini");
	WritePrivateProfileString("Easy","Win",win1,"C:\\memory.ini");
	WritePrivateProfileString("Easy","Best time",btime1,"C:\\memory.ini");
	}
	else if(state==2){
	WritePrivateProfileString("Middle","Total",total2,"C:\\memory.ini");
	WritePrivateProfileString("Middle","Win",win2,"C:\\memory.ini");
	WritePrivateProfileString("Middle","Best time",btime2,"C:\\memory.ini");
	}
	else if(state==3){
	WritePrivateProfileString("Hard","Total",total3,"C:\\memory.ini");
	WritePrivateProfileString("Hard","Win",win3,"C:\\memory.ini");
	WritePrivateProfileString("Hard","Best time",btime3,"C:\\memory.ini");
	}
	else return;
}


void CPro_slDlg::OnAboutbox() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}
