// DlgHistogram.cpp : implementation file
//

#include "stdafx.h"
#include "MyFrame.h"
#include "DlgHistogram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern m_dib;
/////////////////////////////////////////////////////////////////////////////
// CDlgHistogram dialog


CDlgHistogram::CDlgHistogram(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHistogram::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgHistogram)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgHistogram::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgHistogram)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgHistogram, CDialog)
	//{{AFX_MSG_MAP(CDlgHistogram)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgHistogram message handlers
/*************************************************************************
* 函数名称：OnPaint()
* 函数参数: 无
* 函数类型:void     
* 函数功能:该函数用来绘制图象灰度直方图
 ************************************************************************/
void CDlgHistogram::OnPaint() 
{
	CPaintDC dc(this);// 设备上下文		
	CWnd* pWnd = GetDlgItem(IDC_COORD);// 获取绘制坐标的文本框
	
	CString str;// 字符串		
	long i;// 循环变量		
	long lMaxCount = 0;// 最大计数				
	CDC* pDC = pWnd->GetDC();// 指针
	//	pWnd->Invalidate();
	//	pWnd->UpdateWindow();	
	//	pDC->Rectangle(0,0,310,300);
	
	CPen* pPenGreen = new CPen;// 创建画笔对象		
	pPenGreen->CreatePen(PS_SOLID,2,RGB(0,160,0));// 绿色画笔
	
	CPen* pPenBlue = new CPen;// 创建画笔对象		
	pPenBlue->CreatePen(PS_SOLID,2,RGB(0,0, 255));// 蓝色画笔
	
	CGdiObject* pOldPen = pDC->SelectObject(pPenBlue);// 选中当前绿色画笔，并保存以前的画笔
	
	
	pDC->MoveTo(10,10);// 绘制坐标轴	
	pDC->LineTo(10,280);// 垂直轴		
	pDC->LineTo(300,280);// 水平轴	
	
	str.Format("0");// 写X轴刻度值
	pDC->TextOut(10, 283, str);
	str.Format("50");
	pDC->TextOut(60, 283, str);
	str.Format("100");
	pDC->TextOut(110, 283, str);
	str.Format("150");
	pDC->TextOut(160, 283, str);
	str.Format("200");
	pDC->TextOut(210, 283, str);
	str.Format("255");
	pDC->TextOut(265, 283, str);
	
	for (i = 0; i < 256; i += 5)// 绘制X轴刻度
	{
		if ((i & 1) == 0)
		{
			pDC->MoveTo(i + 10, 280);// 10的倍数
			pDC->LineTo(i + 10, 284);
		}
		else
		{		
			pDC->MoveTo(i + 10, 280);
			pDC->LineTo(i + 10, 282);
		}
	}		
	pDC->MoveTo(295,275);// 绘制X轴箭头
	pDC->LineTo(300,280);
	pDC->LineTo(295,285);	
	
	pDC->MoveTo(10,10);// 绘制Y轴箭头
	pDC->LineTo(5,15);
	pDC->MoveTo(10,10);
	pDC->LineTo(15,15);
	
	for (i =0; i <=255; i ++)// 计算最大计数值
	{		
		if (m_lDibCount[i] > lMaxCount)//是否大于当前最大值
		{			
			lMaxCount = m_lDibCount[i];// 更新最大值
		}
	}	
	pDC->MoveTo(10, 25);// 输出最大计数值
	pDC->LineTo(14, 25);
	str.Format("%d", lMaxCount);
	pDC->TextOut(11, 26, str);	
	
	
	str.Format("图象的灰度直方图");//输出标题
	pDC->TextOut(185, 5, str);	
	
	pDC->SelectObject(pPenGreen);// 更改成蓝色画笔	
	
	if (lMaxCount > 0)// 判断是否有计数
	{		
		for (i = 0; i <= 255; i ++)// 绘制直方图
		{
			pDC->MoveTo(i + 10, 280);
			pDC->LineTo(i + 10, 281 - (int) (m_lDibCount[i] * 256 / lMaxCount));
		}
	}		
	pDC->SelectObject(pOldPen);	// 恢复旧画笔		
	delete pPenGreen;// 删除新建的画笔对象
	delete pPenBlue;
	// TODO: Add your message handler code here
	Sleep(1000);
	// Do not call CDialog::OnPaint() for painting messages
}



BOOL CDlgHistogram::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	unsigned char * lpDibSrc;// 指向源图象像素的指针		
	long i;// 循环变量
	long j;					
	CWnd* pWnd = GetDlgItem(IDC_COORD);// 获取绘制直方图的指针		
	for (i = 0; i < 256; i ++)// 置0
	{		
		m_lDibCount[i] = 0;
	}	
	// 计算图象每行的字节数，通过文档类的Dib对象的成员函数来获得
	//long lLineBytes =pView->m_dib.GetReqByteWidth(m_lDibWidth * 8);
                                 
long lLineBytes=1000;
	for (i = 0; i < m_lDibHeight; i ++)// 各灰度值的计数
	{
		for (j = 0; j < m_lDibWidth; j ++)
		{
			lpDibSrc = (unsigned char *)m_lpDibBits + lLineBytes * i + j;						
			m_lDibCount[*(lpDibSrc)]++;// 加1
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
