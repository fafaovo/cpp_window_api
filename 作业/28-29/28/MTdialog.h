#pragma once


// CMTdialog 对话框

class CMTdialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMTdialog)

public:
	CMTdialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMTdialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
};
