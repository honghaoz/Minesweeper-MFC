// MyButton.h: interface for the CMyButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBUTTON_H__0D7739A8_9FB4_4938_BFC9_C6918C5133F0__INCLUDED_)
#define AFX_MYBUTTON_H__0D7739A8_9FB4_4938_BFC9_C6918C5133F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
const UINT WM_MYBUTTONRC=::RegisterWindowMessage("MyButtonRC");
const UINT WM_MYBUTTONRLC=::RegisterWindowMessage("MyButtonRLC");     
#endif // _MSC_VER > 1000

class CMyButton:public CButton
{
public:
	void OnRButtonDown(UINT nFlags,CPoint);
	CMyButton();
	CString numstr(int);
	void OnRButtonUp(UINT nFlags,CPoint);
	virtual ~CMyButton();
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_MYBUTTON_H__0D7739A8_9FB4_4938_BFC9_C6918C5133F0__INCLUDED_)
