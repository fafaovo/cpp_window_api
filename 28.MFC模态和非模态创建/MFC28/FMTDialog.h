#pragma once


// CFMTDialog 对话框

class CFMTDialog : public CDialog
{
	DECLARE_DYNAMIC(CFMTDialog)

public:
	CFMTDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFMTDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	virtual void OnCancel();
	virtual void OnOK();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
};
