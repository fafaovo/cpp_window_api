
// TmpFolderCleanerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TmpFolderCleaner.h"
#include "TmpFolderCleanerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTmpFolderCleanerDlg* Extern_DlgMain = NULL;
//获取目录的两种方法
bool GetTempFolders(LPTSTR pszWinTemp, LPTSTR pszUserTemp)
{
	//获取用户的临时目录
	GetTempPath(MAX_PATH, pszWinTemp);  	
	//获取系统临时目录
	GetWindowsDirectory(pszUserTemp, MAX_PATH); 	// 获取到的是C:\WINDOWS 然后我们拼接一下
	_tcscat_s(pszUserTemp, MAX_PATH,  _T("\\Temp\\"));
	return true;
}

//或者使用数组指针传出去
bool GetTempFolders1(LPTSTR* PszTempArray, int *count)
{
	TCHAR* pWinTemp = new TCHAR[MAX_PATH];
	TCHAR* pUserTemp = new TCHAR[MAX_PATH];
	GetTempPath(MAX_PATH, pWinTemp);
	GetWindowsDirectory(pUserTemp, MAX_PATH); 	// 获取到的是C:\WINDOWS 然后我们拼接一下
	_tcscat_s(pUserTemp, MAX_PATH , _T("\\Temp\\"));
	PszTempArray[0] = pUserTemp;
	PszTempArray[1] = pWinTemp;
	*count = 2;
	return true;
}

//删除一个非空目录  删掉一切传进来的东西
bool DelteFolder(LPCTSTR lpszFolderPath)
{
	//首先进来先判断路径是不是空或者长度不对
	if (!lpszFolderPath || _tcslen(lpszFolderPath) <= 0)
		return false;

	TCHAR szFindPath[MAX_PATH] = { 0 };
	TCHAR szOrigPath[MAX_PATH] = { 0 };
	_tcscpy_s(szFindPath, lpszFolderPath); //字符串拷贝

	//如果最后一个是\的话，就删掉 \0结束符
	UINT len = _tcslen(szFindPath);
	if (szFindPath[len - 1] == '\\')
		szFindPath[len - 1] = '\0';
	_tcscpy_s(szOrigPath, szFindPath);
	
	_stprintf_s(szFindPath, _T("%s\\*.*"), szFindPath);
	//到这里szFindPath等于 目录\\*.*  szOrigPath等于 目录
	
	WIN32_FIND_DATA findData = { 0 };
	HANDLE hFind = FindFirstFile(szFindPath, &findData);
	if (hFind == INVALID_HANDLE_VALUE) //执行错误
		return false;

	//开始遍历文件夹
	while (FindNextFile(hFind,&findData))
	{
		//过滤掉当前目录和上一级目录 .目录 或者 ..目录 就是当前和上一级了
		if (findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY && 
			(_tcscmp(findData.cFileName, _T(".")) == 0 || _tcscmp(findData.cFileName, _T("..")) == 0))
			continue; 

		TCHAR szSubPath[MAX_PATH] = { 0 }; //文件夹|文件的路径
		_stprintf_s(szSubPath, _T("%s\\%s"), szOrigPath, findData.cFileName);
		//此时相当于 目录\\文件夹|文件
		//判断是否是文件夹
		if (findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) //是文件夹	
		{		
			DelteFolder(szSubPath); //递归调用
			RemoveDirectory(szSubPath); //删除空文件夹
		}
		else //是文件 
		{
			//获取有多少行
			int DelListCount = Extern_DlgMain->m_list_2.GetItemCount();
			Extern_DlgMain->m_list_2.InsertItem(0,_T(" "));
			CString DelCount;
			DelCount.Format(_T("%d"), DelListCount);
			Extern_DlgMain->m_list_2.SetItemText(0, 0,DelCount);
			Extern_DlgMain->m_list_2.SetItemText(0, 1, szSubPath);

			BOOL bRet = DeleteFile(szSubPath);
			Extern_DlgMain->STATICError = GetLastError();
			if (bRet)
			{
				Extern_DlgMain->m_list_2.SetItemText(0, 2, _T("已删除"));
			}
			else
			{
				Extern_DlgMain->m_list_2.SetItemText(0, 2, _T("未删除"));
			}
		}
	}
	FindClose(hFind);
	return true;
}


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


// CTmpFolderCleanerDlg 对话框



CTmpFolderCleanerDlg::CTmpFolderCleanerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTmpFolderCleanerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTmpFolderCleanerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_1);
	DDX_Control(pDX, IDC_LIST2, m_list_2);
}

BEGIN_MESSAGE_MAP(CTmpFolderCleanerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTmpFolderCleanerDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTmpFolderCleanerDlg 消息处理程序

BOOL CTmpFolderCleanerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	Extern_DlgMain = this;

	m_list_1.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	m_list_1.InsertColumn(0, _T("ID"), 0, 80 );
	m_list_1.InsertColumn(1, _T("临时目录"), 0, 652);

	m_list_2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	m_list_2.InsertColumn(0, _T("ID"), 0, 80);
	m_list_2.InsertColumn(1, _T("文件路径"), 0, 560);
	m_list_2.InsertColumn(2, _T("删除状态"), 0, 98);

	
	//GetTempFolders(LPTSTR pszWinTemp, LPTSTR pszUserTemp)
	TCHAR pszWinTemp[MAX_PATH] = { 0 };
	TCHAR pszUserTemp[MAX_PATH] = { 0 };
	GetTempFolders(pszWinTemp, pszUserTemp);

	*PszTempArray = { 0 };
	int count = 0;
	GetTempFolders1(PszTempArray, &count);

	for (int i = 0; i < count; i++)
	{
		m_list_1.InsertItem(i, _T("1"));
		CString strCount;
		strCount.Format(_T("%d"), i+1);
		m_list_1.SetItemText(i, 0, strCount);
		m_list_1.SetItemText(i, 1, PszTempArray[i]);
	}

	

	//bool GetTempFolders(LPTSTR** PszTempArray,int* Count)
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTmpFolderCleanerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTmpFolderCleanerDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTmpFolderCleanerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTmpFolderCleanerDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	DelteFolder(PszTempArray[0]);
	DelteFolder(PszTempArray[1]);
	if (STATICError == 32)
	{
		MessageBox(_T("另一个程序正在使用此文件，进程无法访问！"));
	}
	
}


void CTmpFolderCleanerDlg::PostNcDestroy()
{
	// TODO:  在此添加专用代码和/或调用基类
	delete[] *PszTempArray;
	CDialogEx::PostNcDestroy();
}
