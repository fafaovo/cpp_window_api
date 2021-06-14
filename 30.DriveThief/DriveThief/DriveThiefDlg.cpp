
// DriveThiefDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DriveThief.h"
#include "DriveThiefDlg.h"
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

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDriveThiefDlg �Ի���



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


// CDriveThiefDlg ��Ϣ�������

BOOL CDriveThiefDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	TCHAR szDisk[16] = { 0 };
	GetMaxSpaceDisk(szDisk, 16);
	CString m_strSavePath = szDisk;
	SetDlgItemText(IDC_EDIT1, m_strSavePath);
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDriveThiefDlg::OnPaint()
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
HCURSOR CDriveThiefDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDriveThiefDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��Ѵ����Ǵ�Ŀ¼��
	WCHAR szDir[MAX_PATH]; //����ansi��unicode��������
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szDir;
	bi.lpszTitle = L"��ѡ�񱣴�Ŀ¼";
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
	//��Ѵ����Ǵ�Ŀ¼��
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
	//��һ�Ѷ����ǻ�ȡϵͳ��

	TCHAR szDrives[MAX_PATH] = { 0 };
	GetLogicalDriveStrings(MAX_PATH, szDrives);
	//�˴���õ����̷�����
	
	//���ڴ洢�����̷����ı���
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
		//�Ǳ����Դ��Ĵ��̷���
		//��ȡ�ô��̿��ÿռ�
		ULARGE_INTEGER lpUse = { 0 };
		ULARGE_INTEGER lpTotal = { 0 };
		ULARGE_INTEGER lpFree = { 0 };
		GetDiskFreeSpaceEx(pDrive, &lpUse, &lpTotal, &lpFree);
		//�����������ÿռ��С��ʣ��ռ��С
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
