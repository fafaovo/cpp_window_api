
// TmpFolderCleanerDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"



// CTmpFolderCleanerDlg 对话框
class CTmpFolderCleanerDlg : public CDialogEx
{
// 构造
public:
	CTmpFolderCleanerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TMPFOLDERCLEANER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 临时文件目录
	CListCtrl m_list_1;
	CListCtrl m_list_2;
	afx_msg void OnBnClickedButton1();
	TCHAR *PszTempArray[2]; //temp路径
	virtual void PostNcDestroy();
	DWORD STATICError;  //删除失败返回值
};

extern CTmpFolderCleanerDlg* Extern_DlgMain;