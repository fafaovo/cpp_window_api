
// DriveThiefDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CDriveThiefDlg 对话框
class CDriveThiefDlg : public CDialog
{
// 构造
public:
	CDriveThiefDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DRIVETHIEF_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	BOOL GetMaxSpaceDisk(TCHAR* pszDisk,int nDiskBuffLength); //获取系统存储空间最大的盘符
	CListBox LIst_Copy_Type;   //拷贝的文件类型
	CEdit EDIT_ROUTE_1;    //放置路径的edit
public:
	CString m_strSavePath;  //路径
};
