#pragma once


// CFMTDialog �Ի���

class CFMTDialog : public CDialog
{
	DECLARE_DYNAMIC(CFMTDialog)

public:
	CFMTDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFMTDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	virtual void OnCancel();
	virtual void OnOK();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
};
