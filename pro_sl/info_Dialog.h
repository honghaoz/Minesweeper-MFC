#if !defined(AFX_INFO_DIALOG_H__229AAB67_7A88_4AC2_8672_AD194559037B__INCLUDED_)
#define AFX_INFO_DIALOG_H__229AAB67_7A88_4AC2_8672_AD194559037B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// info_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// info_Dialog dialog

class info_Dialog : public CDialog
{
// Construction
public:
	info_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(info_Dialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(info_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(info_Dialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFO_DIALOG_H__229AAB67_7A88_4AC2_8672_AD194559037B__INCLUDED_)
