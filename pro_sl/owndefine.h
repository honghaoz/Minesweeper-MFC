#if !defined(AFX_OWNDEFINE_H__6862C4EE_AC6C_40AC_86FB_0FBB98BE8B59__INCLUDED_)
#define AFX_OWNDEFINE_H__6862C4EE_AC6C_40AC_86FB_0FBB98BE8B59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// owndefine.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// owndefine dialog

class owndefine : public CDialog
{
// Construction
public:
	owndefine(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(owndefine)
	enum { IDD = IDD_DIALOG2 };
	int		m_hang;
	int		m_lei;
	int		m_lie;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(owndefine)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(owndefine)
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OWNDEFINE_H__6862C4EE_AC6C_40AC_86FB_0FBB98BE8B59__INCLUDED_)
