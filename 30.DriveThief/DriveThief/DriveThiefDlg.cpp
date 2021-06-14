
// DriveThiefDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DriveThief.h"
#include "DriveThiefDlg.h"
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

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDriveThiefDlg 对话框



CDriveThiefDlg::CDriveThiefDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriveThiefDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDriveThiefDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LIst_Copy_Type);
	DDX_Control(pDX, IDC_EDIT1, EDIT_ROUTE_1);
}

BEGIN_MESSAGE_MAP(CDriveThiefDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDriveThiefDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDriveThiefDlg 消息处理程序

BOOL CDriveThiefDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	TCHAR szDisk[16] = { 0 };
	GetMaxSpaceDisk(szDisk, 16);
	CString m_strSavePath = szDisk;
	SetDlgItemText(IDC_EDIT1, m_strSavePath);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDriveThiefDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDriveThiefDlg::OnPaint()
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
HCURSOR CDriveThiefDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDriveThiefDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//这堆代码是打开目录的
	WCHAR szDir[MAX_PATH]; //依旧ansi和unicode更换类型
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szDir;
	bi.lpszTitle = L"请选择保存目录";
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;

	pidl = SHBrowseForFolder(&bi);
	if (pidl == NULL)
		return;
	if (SHGetPathFromIDList(pidl, szDir))
	{
	
		m_strSavePath.Format(L"%s", szDir);
	}
	//这堆代码是打开目录的
	SetDlgItemText(IDC_EDIT1, m_strSavePath);
}

BOOL CDriveThiefDlg::GetMaxSpaceDisk(TCHAR* pszDisk, int nDiskBuffLength)
{
	TCHAR szWinFolder[MAX_PATH] = { 0 };
	GetWindowsDirectory(szWinFolder, MAX_PATH);
	int nFlag = -1;
	for (UINT idx = 0; idx < _tcslen(szWinFolder); idx++)
	{
		if (szWinFolder[idx] != '\\') continue;
		nFlag = idx;
		break;
	}
	if (nFlag >= 0)
	{
		szWinFolder[nFlag + 1] = '\0';
	}
	//这一堆东西是获取系统盘

	TCHAR szDrives[MAX_PATH] = { 0 };
	GetLogicalDriveStrings(MAX_PATH, szDrives);
	//此处获得到磁盘分区了
	
	//用于存储最大磁盘分区的变量
	TCHAR* MaxDrive = NULL;
	ULONGLONG nMaxFreeSize = 0;

	TCHAR* pDrive = szDrives;
	while (*pDrive)
	{
		if (_tcscmp(pDrive,szWinFolder) == 0)
		{
			pDrive += _tcslen(pDrive) + 1;
			continue;
		}
		UINT nType = GetDriveType(pDrive);
		if (nType != DRIVE_FIXED)
		{
			pDrive += _tcslen(pDrive) + 1;
			continue;
		}
		//是本机自带的磁盘分区
		//获取该磁盘可用空间
		ULARGE_INTEGER lpUse = { 0 };
		ULARGE_INTEGER lpTotal = { 0 };
		ULARGE_INTEGER lpFree = { 0 };
		GetDiskFreeSpaceEx(pDrive, &lpUse, &lpTotal, &lpFree);
		//总容量、已用空间大小、剩余空间大小
		if (lpFree.QuadPart > nMaxFreeSize)
		{
			MaxDrive = pDrive;
			nMaxFreeSize = lpFree.QuadPart;
		}
		pDrive += _tcslen(pDrive) + 1;
	}
	_tcscpy_s(pszDisk, nDiskBuffLength,MaxDrive);
	return TRUE;
}
