// owndefine.cpp : implementation file
//

#include "stdafx.h"
#include "pro_sl.h"
#include "owndefine.h"
#include"pro_slDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// owndefine dialog


owndefine::owndefine(CWnd* pParent /*=NULL*/)
	: CDialog(owndefine::IDD, pParent)
{
	//{{AFX_DATA_INIT(owndefine)
	m_hang = 0;
	m_lei = 0;
	m_lie = 0;
	//}}AFX_DATA_INIT
}


void owndefine::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(owndefine)
	DDX_Text(pDX, IDC_hang, m_hang);
	DDX_Text(pDX, IDC_lei, m_lei);
	DDX_Text(pDX, IDC_lie, m_lie);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(owndefine, CDialog)
	//{{AFX_MSG_MAP(owndefine)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// owndefine message handlers
void owndefine::OnOk() 
{
	// TODO: Add your control notification handler code here


	CDialog::OnOK();
}
