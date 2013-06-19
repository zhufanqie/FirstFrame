// MyFrameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyFrame.h"
#include "MyFrameDlg.h"
#include "math.h"
#include "DlgHistogram.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CMyFrameApp theApp;       // �ڴ�����Ӧ�����е�theApp����ȡ������ָ��
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFrameDlg dialog

CMyFrameDlg::CMyFrameDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyFrameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyFrameDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hDIB = NULL;// ��ʼ������
	m_palDIB = NULL;
}

void CMyFrameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyFrameDlg)
	DDX_Control(pDX, IDC_LIST_RESULT, m_ListFound);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyFrameDlg, CDialog)
//{{AFX_MSG_MAP(CMyFrameDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_COMMAND(ID_EXIT, OnExit)
ON_COMMAND(ID_ABOUT, OnAbout)
ON_COMMAND(ID_OpenImage, OnOpenImage)
	ON_COMMAND(ID_HISTOGRAM, OnHistogram)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFrameDlg message handlers

BOOL CMyFrameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SkinH_Attach();
	m_toolbar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD|WS_VISIBLE|CBRS_TOP);
	m_toolbar.LoadToolBar(IDR_TOOLBAR);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyFrameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyFrameDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyFrameDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}








void CMyFrameDlg::OnExit() 
{
	// TODO: Add your command handler code here
	CDialog::OnOK();
}





void CMyFrameDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}







void CMyFrameDlg::OnOpenImage() 
{
	// TODO: Add your command handler code here
	LPCTSTR lpszFilter="BMP Files(*.bmp)|*.bmp|�κ��ļ�|*.*||";
	CFileDialog dlg(TRUE,lpszFilter,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpszFilter,NULL);
	CString filepath;
	CFile file;
	
    //���ļ��Ի���
	if( dlg.DoModal() == IDOK )
	{
		filepath = dlg.GetPathName();
		if (!file.Open(filepath, CFile::modeRead | 	CFile::shareDenyWrite))// ���ļ�
		{					
			return ;// ����FALSE
		}	
	}
	
	m_hDIB=m_dib.LoadFile(file);
	SetDib();// ��ʼ��DIB

    RECT rect;
	BITMAP bm;
	HBITMAP hBitmap;
	HDC hSrcDC;
	HDC hDesDC;
    CWnd *hwnd;

	hwnd = GetDlgItem(IDC_STATIC_KEYIMAGE);
	hDesDC = hwnd->GetDC()->m_hDC;
	hSrcDC = CreateCompatibleDC(hDesDC);
	hBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,0,0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	GetObject(hBitmap, sizeof(BITMAP), &bm);
	SelectObject(hSrcDC, hBitmap);
	hwnd->GetClientRect(&rect);
	::SetStretchBltMode(hDesDC,COLORONCOLOR); 
	::StretchBlt(hDesDC, rect.left, rect.top, rect.right, rect.bottom, hSrcDC,
		0, 0, bm.bmWidth, bm.bmHeight,+SRCCOPY);
	UpdateData(false);


	/*	// �ж�DIB�Ƿ�Ϊ��
	if (m_hDIB != NULL)
	{
		LPSTR lpDibSection = (LPSTR) ::GlobalLock((HGLOBAL) m_hDIB);
		
		// ��ȡDIB���
		int cxDIB = (int) m_dib.GetWidth(lpDibSection);
		
		// ��ȡDIB�߶�
		int cyDIB = (int) m_dib.GetHeight(lpDibSection);
		
		::GlobalUnlock((HGLOBAL) m_hDIB);
		
		CRect rcDIB;
		rcDIB.top = rcDIB.left = 0;
		rcDIB.right = cxDIB;
		rcDIB.bottom = cyDIB;		
		CRect rcDest= rcDIB;
		HDC hDesDC;
        CWnd *hwnd;

		hwnd = GetDlgItem(IDC_STATIC_KEYIMAGE);
	    hDesDC = hwnd->GetDC()->m_hDC;
	
       m_dib.DrawDib(hDesDC, &rcDest, GetHObject(),&rcDIB, GetDocPal());	// ���DIB

    	return ;// ����TRUE
		}
	*/
	
	
}

void CMyFrameDlg::SetDib()
{		
	LPSTR lpdib = (LPSTR) ::GlobalLock((HGLOBAL) m_hDIB);	
	
	if (m_dib.GetWidth(lpdib) > INT_MAX ||m_dib.GetHeight(lpdib) > INT_MAX)// �ж�ͼ���Ƿ����
	{
		::GlobalUnlock((HGLOBAL) m_hDIB);				
		::GlobalFree((HGLOBAL) m_hDIB);	// �ͷ�DIB����			
		m_hDIB = NULL;// ����DIBΪ��		
		AfxMessageBox("��ʼ��ʧ��"); 		
		return;
	}	
	m_sizeDoc = CSize((int)m_dib.GetWidth(lpdib), (int)m_dib.GetHeight(lpdib));// �����ĵ���С	
	::GlobalUnlock((HGLOBAL) m_hDIB);	
	m_palDIB = new CPalette;// �����µ�ɫ��		
	if (m_palDIB == NULL)// �ж��Ƿ񴴽��ɹ�
	{		
		::GlobalFree((HGLOBAL) m_hDIB);	// ʧ��		
		m_hDIB = NULL;// ����DIB����Ϊ��
		return;
	}	
	// ����CreateDIBPalette��������ɫ��
	if (m_dib.ConstructPalette(m_hDIB, m_palDIB) == NULL)
	{				
		delete m_palDIB;// ɾ��				
		m_palDIB = NULL;// ����Ϊ��	
		return;// ���ؿ�
	}
}

void CMyFrameDlg::UpdateObject(HGLOBAL hDIB)
{		
	if (m_hDIB != NULL)               // �ж�DIB�Ƿ�Ϊ��
	{		
		::GlobalFree((HGLOBAL) m_hDIB);// �ǿգ������
	}	
	m_hDIB = hDIB;                     // �滻���µ�DIB����	
}

void CMyFrameDlg::OnHistogram() 
{
	// TODO: Add your command handler code here
	long lSrcLineBytes;		//ͼ��ÿ�е��ֽ���
	long	lSrcWidth;      //ͼ��Ŀ�Ⱥ͸߶�
	long	lSrcHeight;
	LPSTR	lpSrcDib;		//ָ��Դͼ���ָ��	
	LPSTR	lpSrcStartBits;	//ָ��Դ���ص�ָ��
	lpSrcDib= (LPSTR) ::GlobalLock((HGLOBAL) GetHObject());// ����DIB
	if (m_dib.GetColorNum(lpSrcDib) != 256)// �ж��Ƿ���8-bppλͼ
	{		
		AfxMessageBox("�Բ��𣬲���256ɫλͼ��");// ����				
		::GlobalUnlock((HGLOBAL) GetHObject());// �������		
		return;									//����
	}										//�ж��Ƿ���8-bppλͼ,�����򷵻�	
	lpSrcStartBits=m_dib.GetBits(lpSrcDib);			// �ҵ�DIBͼ��������ʼλ��	
	lSrcWidth= m_dib.GetWidth(lpSrcDib);					// ��ȡͼ��Ŀ��		
	lSrcHeight= m_dib.GetHeight(lpSrcDib);					// ��ȡͼ��ĸ߶�		
	lSrcLineBytes=m_dib.GetReqByteWidth(lSrcWidth * 8);		// ����ͼ��ÿ�е��ֽ���
	/////////////////////////////////////////////////////////////////////////////////////////////////	
	CDlgHistogram HistogramPara;// �����Ի���		
	HistogramPara.m_lpDibBits =lpSrcStartBits;// ��ʼ������ֵ
	HistogramPara.m_lDibWidth = lSrcWidth;
	HistogramPara.m_lDibHeight = lSrcHeight;		
	if (HistogramPara.DoModal() != IDOK)// ��ʾ�Ի����趨ƽ����
	{
		return;	
	}
	::GlobalUnlock((HGLOBAL)GetHObject());// �������

}
