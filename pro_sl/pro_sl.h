// pro_sl.h : main header file for the PRO_SL application
//

#if !defined(AFX_PRO_SL_H__7F6C506F_836A_400F_AB20_B84083F4B1A2__INCLUDED_)
#define AFX_PRO_SL_H__7F6C506F_836A_400F_AB20_B84083F4B1A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPro_slApp:
// See pro_sl.cpp for the implementation of this class
//

class CPro_slApp : public CWinApp
{
public:
	CPro_slApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro_slApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPro_slApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO_SL_H__7F6C506F_836A_400F_AB20_B84083F4B1A2__INCLUDED_)
