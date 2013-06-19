// MyFrame.h : main header file for the MYFRAME application
//

#if !defined(AFX_MYFRAME_H__2CC6BDD2_163B_475E_BE5A_FD2C32B56FBD__INCLUDED_)
#define AFX_MYFRAME_H__2CC6BDD2_163B_475E_BE5A_FD2C32B56FBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyFrameApp:
// See MyFrame.cpp for the implementation of this class
//

class CMyFrameApp : public CWinApp
{
public:
	CMyFrameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFrameApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyFrameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFRAME_H__2CC6BDD2_163B_475E_BE5A_FD2C32B56FBD__INCLUDED_)
