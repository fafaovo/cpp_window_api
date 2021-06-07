
// MFC28Dlg.h : 头文件
//

#pragma once
#include "FMTDialog.h"

// CMFC28Dlg 对话框
class CMFC28Dlg : public CDialog
{
// 构造
public:
	CMFC28Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC28_DIALOG };

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
	afx_msg void OnBnClickedButton2();


public:
	// 作为类对象的成员变量的非模态对话框的定义
	CFMTDialog FMTdig;
	CFMTDialog* Pdig_1;
};
