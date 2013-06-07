// pro_slDlg.h : header file
//

#if !defined(AFX_PRO_SLDLG_H__2AD8E5CE_E1B0_4FA1_BD8A_E258727AC32F__INCLUDED_)
#define AFX_PRO_SLDLG_H__2AD8E5CE_E1B0_4FA1_BD8A_E258727AC32F__INCLUDED_

#include "MyButton.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//const UINT WM_MYBUTTONRC=::RegisterWindowMessage("MyButtonRC");
/////////////////////////////////////////////////////////////////////////////
// CPro_slDlg dialog

class CPro_slDlg : public CDialog
{
// Construction
public:
	void seterror(int,int);
	int win;
	int state;
	int nCount;
	int winnum;
	int allgame;
	void tongji(int);
	void OnMyButtonRC(WPARAM,LPARAM);
	void OnMyButtonRLC(WPARAM,LPARAM);
	void expand(int,int,int);
	void gameover(int,int);
	int map_boomall;
	int map_w;
	int ctime;
	int map_h;
	int current;
	int map[21][21];
	int ismap[21][21];
	int ismapa[21][21];
	int init();
	CPro_slDlg(CWnd* pParent = NULL);	// standard constructor
	CMyButton *BoomBTN[400];
	CString numstr(int n);
	void OnBoomBTN(UINT);
	void OnRBoomBTN(UINT);
// Dialog Data
	//{{AFX_DATA(CPro_slDlg)
	enum { IDD = IDD_PRO_SL_DIALOG };
	CButton	m_Cancel;
	CButton	m_Time;
	CButton	m_Last;
	CButton	m_Static1;
	CButton	m_Static0;
	CButton	m_NewGame;
	CButton	m_FOCUS;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro_slDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:
	HICON hIcon1,hIcon2,hIcon3,hIcon4,hIcon5,hIcon6,hIcon7,hIcon8,hIcon9;
	HICON hIconC,hIconI,hIconX;
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPro_slDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEasy();
	afx_msg void OnHard();
	afx_msg void OnMid();
	afx_msg void OnStatistic();
	afx_msg void OnOwn();
	afx_msg void OnAboutbox();
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO_SLDLG_H__2AD8E5CE_E1B0_4FA1_BD8A_E258727AC32F__INCLUDED_)
