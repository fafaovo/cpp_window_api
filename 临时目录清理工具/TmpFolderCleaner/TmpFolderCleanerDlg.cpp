
// TmpFolderCleanerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TmpFolderCleaner.h"
#include "TmpFolderCleanerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTmpFolderCleanerDlg* Extern_DlgMain = NULL;
//��ȡĿ¼�����ַ���
bool GetTempFolders(LPTSTR pszWinTemp, LPTSTR pszUserTemp)
{
	//��ȡ�û�����ʱĿ¼
	GetTempPath(MAX_PATH, pszWinTemp);  	
	//��ȡϵͳ��ʱĿ¼
	GetWindowsDirectory(pszUserTemp, MAX_PATH); 	// ��ȡ������C:\WINDOWS Ȼ������ƴ��һ��
	_tcscat_s(pszUserTemp, MAX_PATH,  _T("\\Temp\\"));
	return true;
}

//����ʹ������ָ�봫��ȥ
bool GetTempFolders1(LPTSTR* PszTempArray, int *count)
{
	TCHAR* pWinTemp = new TCHAR[MAX_PATH];
	TCHAR* pUserTemp = new TCHAR[MAX_PATH];
	GetTempPath(MAX_PATH, pWinTemp);
	GetWindowsDirectory(pUserTemp, MAX_PATH); 	// ��ȡ������C:\WINDOWS Ȼ������ƴ��һ��
	_tcscat_s(pUserTemp, MAX_PATH , _T("\\Temp\\"));
	PszTempArray[0] = pUserTemp;
	PszTempArray[1] = pWinTemp;
	*count = 2;
	return true;
}

//ɾ��һ���ǿ�Ŀ¼  ɾ��һ�д������Ķ���
bool DelteFolder(LPCTSTR lpszFolderPath)
{
	//���Ƚ������ж�·���ǲ��ǿջ��߳��Ȳ���
	if (!lpszFolderPath || _tcslen(lpszFolderPath) <= 0)
		return false;

	TCHAR szFindPath[MAX_PATH] = { 0 };
	TCHAR szOrigPath[MAX_PATH] = { 0 };
	_tcscpy_s(szFindPath, lpszFolderPath); //�ַ�������

	//������һ����\�Ļ�����ɾ�� \0������
	UINT len = _tcslen(szFindPath);
	if (szFindPath[len - 1] == '\\')
		szFindPath[len - 1] = '\0';
	_tcscpy_s(szOrigPath, szFindPath);
	
	_stprintf_s(szFindPath, _T("%s\\*.*"), szFindPath);
	//������szFindPath���� Ŀ¼\\*.*  szOrigPath���� Ŀ¼
	
	WIN32_FIND_DATA findData = { 0 };
	HANDLE hFind = FindFirstFile(szFindPath, &findData);
	if (hFind == INVALID_HANDLE_VALUE) //ִ�д���
		return false;

	//��ʼ�����ļ���
	while (FindNextFile(hFind,&findData))
	{
		//���˵���ǰĿ¼����һ��Ŀ¼ .Ŀ¼ ���� ..Ŀ¼ ���ǵ�ǰ����һ����
		if (findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY && 
			(_tcscmp(findData.cFileName, _T(".")) == 0 || _tcscmp(findData.cFileName, _T("..")) == 0))
			continue; 

		TCHAR szSubPath[MAX_PATH] = { 0 }; //�ļ���|�ļ���·��
		_stprintf_s(szSubPath, _T("%s\\%s"), szOrigPath, findData.cFileName);
		//��ʱ�൱�� Ŀ¼\\�ļ���|�ļ�
		//�ж��Ƿ����ļ���
		if (findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) //���ļ���	
		{		
			DelteFolder(szSubPath); //�ݹ����
			RemoveDirectory(szSubPath); //ɾ�����ļ���
		}
		else //���ļ� 
		{
			//��ȡ�ж�����
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
				Extern_DlgMain->m_list_2.SetItemText(0, 2, _T("��ɾ��"));
			}
			else
			{
				Extern_DlgMain->m_list_2.SetItemText(0, 2, _T("δɾ��"));
			}
		}
	}
	FindClose(hFind);
	return true;
}


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


// CTmpFolderCleanerDlg �Ի���



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


// CTmpFolderCleanerDlg ��Ϣ�������

BOOL CTmpFolderCleanerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	Extern_DlgMain = this;

	m_list_1.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	m_list_1.InsertColumn(0, _T("ID"), 0, 80 );
	m_list_1.InsertColumn(1, _T("��ʱĿ¼"), 0, 652);

	m_list_2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	m_list_2.InsertColumn(0, _T("ID"), 0, 80);
	m_list_2.InsertColumn(1, _T("�ļ�·��"), 0, 560);
	m_list_2.InsertColumn(2, _T("ɾ��״̬"), 0, 98);

	
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTmpFolderCleanerDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTmpFolderCleanerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTmpFolderCleanerDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	DelteFolder(PszTempArray[0]);
	DelteFolder(PszTempArray[1]);
	if (STATICError == 32)
	{
		MessageBox(_T("��һ����������ʹ�ô��ļ��������޷����ʣ�"));
	}
	
}


void CTmpFolderCleanerDlg::PostNcDestroy()
{
	// TODO:  �ڴ����ר�ô����/����û���
	delete[] *PszTempArray;
	CDialogEx::PostNcDestroy();
}
