#pragma once


// CFMTdialog �Ի���

class CFMTdialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFMTdialog)

public:
	CFMTdialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFMTdialog();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void OnOK();
	virtual void PostNcDestroy();
public:
	virtual BOOL OnInitDialog();
	CString Edit_val_1;
};
