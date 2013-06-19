// MyFrameDlg.h : header file
//

#if !defined(AFX_MYFRAMEDLG_H__8E741CF1_2B58_4619_8F71_AC0188AA85F7__INCLUDED_)
#define AFX_MYFRAMEDLG_H__8E741CF1_2B58_4619_8F71_AC0188AA85F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Dib.h"
extern  m_dib;					//声明一个可用的外部成员变量
/////////////////////////////////////////////////////////////////////////////
// CMyFrameDlg dialog

class CMyFrameDlg : public CDialog
{
// Construction
public:
	CMyFrameDlg(CWnd* pParent = NULL);	// standard constructor
	HMENU m_hMenu;
	CString m_path;
	CToolBar m_toolbar;
	CDib m_dib;					//声明一个Dib对象
	HGLOBAL GetHObject() const	//获取Dib对象的句柄
	{ return m_hDIB; }
	CPalette* GetDocPal() const	//获取调色板指针
	{ return m_palDIB; }
	CSize GetDocDimension() const//获取调色板大小
	{ return m_sizeDoc; }
	void UpdateObject(HGLOBAL hDIB);//更新dib对象
	void SetDib();				//初始化dib对象
// Dialog Data
	//{{AFX_DATA(CMyFrameDlg)
	enum { IDD = IDD_MYFRAME_DIALOG };
	CListBox	m_ListFound;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFrameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HGLOBAL m_hDIB;
	CPalette* m_palDIB;
	CSize m_sizeDoc;
	// Generated message map functions
	//{{AFX_MSG(CMyFrameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnOpenImage();
	afx_msg void OnHistogram();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFRAMEDLG_H__8E741CF1_2B58_4619_8F71_AC0188AA85F7__INCLUDED_)
