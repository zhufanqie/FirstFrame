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
* �������ƣ�OnPaint()
* ��������: ��
* ��������:void     
* ��������:�ú�����������ͼ��Ҷ�ֱ��ͼ
 ************************************************************************/
void CDlgHistogram::OnPaint() 
{
	CPaintDC dc(this);// �豸������		
	CWnd* pWnd = GetDlgItem(IDC_COORD);// ��ȡ����������ı���
	
	CString str;// �ַ���		
	long i;// ѭ������		
	long lMaxCount = 0;// ������				
	CDC* pDC = pWnd->GetDC();// ָ��
	//	pWnd->Invalidate();
	//	pWnd->UpdateWindow();	
	//	pDC->Rectangle(0,0,310,300);
	
	CPen* pPenGreen = new CPen;// �������ʶ���		
	pPenGreen->CreatePen(PS_SOLID,2,RGB(0,160,0));// ��ɫ����
	
	CPen* pPenBlue = new CPen;// �������ʶ���		
	pPenBlue->CreatePen(PS_SOLID,2,RGB(0,0, 255));// ��ɫ����
	
	CGdiObject* pOldPen = pDC->SelectObject(pPenBlue);// ѡ�е�ǰ��ɫ���ʣ���������ǰ�Ļ���
	
	
	pDC->MoveTo(10,10);// ����������	
	pDC->LineTo(10,280);// ��ֱ��		
	pDC->LineTo(300,280);// ˮƽ��	
	
	str.Format("0");// дX��̶�ֵ
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
	
	for (i = 0; i < 256; i += 5)// ����X��̶�
	{
		if ((i & 1) == 0)
		{
			pDC->MoveTo(i + 10, 280);// 10�ı���
			pDC->LineTo(i + 10, 284);
		}
		else
		{		
			pDC->MoveTo(i + 10, 280);
			pDC->LineTo(i + 10, 282);
		}
	}		
	pDC->MoveTo(295,275);// ����X���ͷ
	pDC->LineTo(300,280);
	pDC->LineTo(295,285);	
	
	pDC->MoveTo(10,10);// ����Y���ͷ
	pDC->LineTo(5,15);
	pDC->MoveTo(10,10);
	pDC->LineTo(15,15);
	
	for (i =0; i <=255; i ++)// ����������ֵ
	{		
		if (m_lDibCount[i] > lMaxCount)//�Ƿ���ڵ�ǰ���ֵ
		{			
			lMaxCount = m_lDibCount[i];// �������ֵ
		}
	}	
	pDC->MoveTo(10, 25);// ���������ֵ
	pDC->LineTo(14, 25);
	str.Format("%d", lMaxCount);
	pDC->TextOut(11, 26, str);	
	
	
	str.Format("ͼ��ĻҶ�ֱ��ͼ");//�������
	pDC->TextOut(185, 5, str);	
	
	pDC->SelectObject(pPenGreen);// ���ĳ���ɫ����	
	
	if (lMaxCount > 0)// �ж��Ƿ��м���
	{		
		for (i = 0; i <= 255; i ++)// ����ֱ��ͼ
		{
			pDC->MoveTo(i + 10, 280);
			pDC->LineTo(i + 10, 281 - (int) (m_lDibCount[i] * 256 / lMaxCount));
		}
	}		
	pDC->SelectObject(pOldPen);	// �ָ��ɻ���		
	delete pPenGreen;// ɾ���½��Ļ��ʶ���
	delete pPenBlue;
	// TODO: Add your message handler code here
	Sleep(1000);
	// Do not call CDialog::OnPaint() for painting messages
}



BOOL CDlgHistogram::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	unsigned char * lpDibSrc;// ָ��Դͼ�����ص�ָ��		
	long i;// ѭ������
	long j;					
	CWnd* pWnd = GetDlgItem(IDC_COORD);// ��ȡ����ֱ��ͼ��ָ��		
	for (i = 0; i < 256; i ++)// ��0
	{		
		m_lDibCount[i] = 0;
	}	
	// ����ͼ��ÿ�е��ֽ�����ͨ���ĵ����Dib����ĳ�Ա���������
	//long lLineBytes =pView->m_dib.GetReqByteWidth(m_lDibWidth * 8);
                                 
long lLineBytes=1000;
	for (i = 0; i < m_lDibHeight; i ++)// ���Ҷ�ֵ�ļ���
	{
		for (j = 0; j < m_lDibWidth; j ++)
		{
			lpDibSrc = (unsigned char *)m_lpDibBits + lLineBytes * i + j;						
			m_lDibCount[*(lpDibSrc)]++;// ��1
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
