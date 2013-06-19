#if !defined(AFX_DLGHISTOGRAM_H__78E12AC4_703E_4B17_8D84_913B04AB2D6F__INCLUDED_)
#define AFX_DLGHISTOGRAM_H__78E12AC4_703E_4B17_8D84_913B04AB2D6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgHistogram.h : header file
//
//为了声明下面的指针变量，必须包含视头文件
#include "MyFrameDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgHistogram dialog

//定义一个外部变量，用来存储视图类的实例的指针
extern CMyFrameDlg *pView;

class CDlgHistogram : public CDialog
{
// Construction
public:
	CDlgHistogram(CWnd* pParent = NULL);   // standard constructor
	long	m_lDibHeight;// DIB的高度		
	long	m_lDibWidth;// DIB的宽度		
	char *	m_lpDibBits;// 指向当前DIB像素的指针		
	long	m_lDibCount[256];// 各个灰度值的计数

// Dialog Data
	//{{AFX_DATA(CDlgHistogram)
	enum { IDD = IDD_dlg_histogram };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgHistogram)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgHistogram)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGHISTOGRAM_H__78E12AC4_703E_4B17_8D84_913B04AB2D6F__INCLUDED_)
