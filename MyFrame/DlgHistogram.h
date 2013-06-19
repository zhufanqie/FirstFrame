#if !defined(AFX_DLGHISTOGRAM_H__78E12AC4_703E_4B17_8D84_913B04AB2D6F__INCLUDED_)
#define AFX_DLGHISTOGRAM_H__78E12AC4_703E_4B17_8D84_913B04AB2D6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgHistogram.h : header file
//
//Ϊ�����������ָ����������������ͷ�ļ�
#include "MyFrameDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgHistogram dialog

//����һ���ⲿ�����������洢��ͼ���ʵ����ָ��
extern CMyFrameDlg *pView;

class CDlgHistogram : public CDialog
{
// Construction
public:
	CDlgHistogram(CWnd* pParent = NULL);   // standard constructor
	long	m_lDibHeight;// DIB�ĸ߶�		
	long	m_lDibWidth;// DIB�Ŀ��		
	char *	m_lpDibBits;// ָ��ǰDIB���ص�ָ��		
	long	m_lDibCount[256];// �����Ҷ�ֵ�ļ���

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
