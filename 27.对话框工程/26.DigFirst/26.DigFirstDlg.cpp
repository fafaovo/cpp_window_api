
// 26.DigFirstDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "26.DigFirst.h"
#include "26.DigFirstDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

//����Ч�飬�ؼ���
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

//��װ�ĺ꣬������Ϣӳ��
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMy26DigFirstDlg �Ի���


//�����ǹ��캯��
CMy26DigFirstDlg::CMy26DigFirstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy26DigFirstDlg::IDD, pParent)
	, click_2_val(0)
	, EDIT_C_1(_T(""))
{
	//��ʼ�����붪������
	pCheckBox2 = NULL;
	m_Time = 0;
	//�����ͼ��
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy26DigFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK3, m_Click1);
	DDX_Control(pDX, IDC_CHECK4, m_click2);
	DDX_Check(pDX, IDC_CHECK4, click_2_val);
	DDX_Text(pDX, IDC_EDIT1, EDIT_C_1);
}

BEGIN_MESSAGE_MAP(CMy26DigFirstDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//��Ϣ����
	ON_BN_CLICKED(IDC_BUTTON1, &CMy26DigFirstDlg::OnBnClickedButton1)
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_CHECK1, &CMy26DigFirstDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMy26DigFirstDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CMy26DigFirstDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CMy26DigFirstDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy26DigFirstDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMy26DigFirstDlg ��Ϣ�������

BOOL CMy26DigFirstDlg::OnInitDialog()
{
	CDialog::OnInitDialog(); //�������˵���Ի�����������Ŀؼ�������������

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	pCheckBox2 = (CButton*)GetDlgItem(IDC_CHECK2);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy26DigFirstDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy26DigFirstDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy26DigFirstDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��������


void CMy26DigFirstDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("123"));
}


void CMy26DigFirstDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MessageBox(_T("����Ҽ�̧���¼�����"));
	CDialog::OnRButtonUp(nFlags, point);
}


void CMy26DigFirstDlg::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���
	int result = MessageBox(_T("ȷ�Ϲر���"),NULL,MB_OKCANCEL);
	if (result == 1)
	{
		CDialog::OnCancel();
	}
	else
	{
		return;
	}
	
}





void CMy26DigFirstDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MessageBox(_T("������˫���¼�������"));
	CDialog::OnLButtonDblClk(nFlags, point);
}


void CMy26DigFirstDlg::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��api�汾��GetDlgItem
	HWND hCheckBox =  ::GetDlgItem(m_hWnd, IDC_CHECK1);
	//:: ȫ�ֺ�������  m_hWnd��ǰ�Ի���
	//��MFC��
	//CWnd* pCheckBox = GetDlgItem(IDC_CHECK1);

	//�ο�HTML�У�check��ʵ��input����ģ��������Ƕ�˵Cbutton��
	CButton* pCheckBox = (CButton*)GetDlgItem(IDC_CHECK1);
	int iCheck = pCheckBox->GetCheck();
	if (iCheck)
	{
		MessageBox(_T("iCheck�¼�������"));
	}


}


void CMy26DigFirstDlg::OnBnClickedCheck2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//ȫ�ֵ�pCheckBox2
	int iCheck = pCheckBox2->GetCheck();
	if (iCheck)
	{
		MessageBox(_T("ָ��iCheck�¼�������"));
	}
}


void CMy26DigFirstDlg::OnBnClickedCheck3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int iCheck = m_Click1.GetCheck();
	if (iCheck)
	{
		MessageBox(_T("����iCheck�¼�������"));
	}
}


void CMy26DigFirstDlg::OnBnClickedCheck4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int iCheck = click_2_val;
	if (iCheck)
	{
		MessageBox(_T("UpdateData�¼�������"));
	}
}

CString GetEditValue(CMy26DigFirstDlg * myMFC)
{
	CWnd* EDIT_1 = myMFC->GetDlgItem(IDC_EDIT1);
	myMFC->UpdateData(TRUE);
	return myMFC->EDIT_C_1;
}


void CMy26DigFirstDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString cout = GetEditValue(this);
	//�����Լ�����ȥ����ô�������������MFC�Ķ�����
	MessageBox(cout,_T("tip"));
}


