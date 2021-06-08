#pragma once


// CMTdialog_2 对话框

class CMTdialog_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CMTdialog_2)

public:
	CMTdialog_2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMTdialog_2();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
