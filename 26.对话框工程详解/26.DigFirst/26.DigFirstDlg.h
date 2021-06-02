
// 26.DigFirstDlg.h : 头文件
//

#pragma once


// CMy26DigFirstDlg 对话框
class CMy26DigFirstDlg : public CDialog
{
// 构造
public:
	CMy26DigFirstDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY26DIGFIRST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();  // 对话框初始化函数
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//自己定义的
public:
	int m_Time;
};
