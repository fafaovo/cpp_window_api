#pragma once


// Dialog_1 对话框

class Dialog_1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog_1)

public:
	Dialog_1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dialog_1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
