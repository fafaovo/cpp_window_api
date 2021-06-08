#pragma once


// CFMTdialog 对话框

class CFMTdialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFMTdialog)

public:
	CFMTdialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFMTdialog();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void OnOK();
	virtual void PostNcDestroy();
public:
	virtual BOOL OnInitDialog();
	CString Edit_val_1;
};
