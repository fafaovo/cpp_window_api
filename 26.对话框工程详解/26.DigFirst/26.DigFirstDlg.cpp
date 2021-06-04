
// 26.DigFirstDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "26.DigFirst.h"
#include "26.DigFirstDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

//数据效验，控件绑定
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

//封装的宏，进行消息映射
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMy26DigFirstDlg 对话框


//这里是构造函数
CMy26DigFirstDlg::CMy26DigFirstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy26DigFirstDlg::IDD, pParent)
{
	//初始化代码丢到这里
	m_Time = 0;
	//程序的图标
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy26DigFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy26DigFirstDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//消息处理
	ON_BN_CLICKED(IDC_BUTTON1, &CMy26DigFirstDlg::OnBnClickedButton1)
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// CMy26DigFirstDlg 消息处理程序

BOOL CMy26DigFirstDlg::OnInitDialog()
{
	CDialog::OnInitDialog(); //调用完就说明对话框界面和上面的控件被创建出来了

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy26DigFirstDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy26DigFirstDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//函数重载


void CMy26DigFirstDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(_T("123"));
}


void CMy26DigFirstDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	MessageBox(_T("鼠标右键抬起事件触发"));
	CDialog::OnRButtonUp(nFlags, point);
}


void CMy26DigFirstDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	int result = MessageBox(_T("确认关闭吗"),NULL,MB_OKCANCEL);
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	MessageBox(_T("鼠标左键双击事件触发！"));
	CDialog::OnLButtonDblClk(nFlags, point);
}
