// MyButton.cpp: implementation of the CMyButton class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "pro_sl.h"
#include "MyButton.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{

}

CString CMyButton::numstr(int n)
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

void CMyButton::OnRButtonUp(UINT nFlags,CPoint)
{
	int nID=GetDlgCtrlID();
	CWnd *p=AfxGetMainWnd();
	if(p!=NULL){
		if(nFlags==(MK_LBUTTON|MK_RBUTTON))p->PostMessage(WM_MYBUTTONRLC,nID,0);
		//if(nFlags==MK_RBUTTON)
		else p->PostMessage(WM_MYBUTTONRC,nID,0);
	}
}

void CMyButton::OnRButtonDown(UINT nFlags, CPoint)
{
	int nID=GetDlgCtrlID();
 	CWnd *p=AfxGetMainWnd();
 	if(p!=NULL){
 		if(nFlags==(MK_RBUTTON|MK_LBUTTON))p->PostMessage(WM_MYBUTTONRLC,nID,0);
 	}
 }
  
  
BEGIN_MESSAGE_MAP(CMyButton,   CButton)   
	ON_WM_RBUTTONUP()  
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()   




