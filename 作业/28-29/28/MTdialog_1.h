#pragma once


// CMTdialog_1 �Ի���

class CMTdialog_1 : public CDialogEx
{
	DECLARE_DYNAMIC(CMTdialog_1)

public:
	CMTdialog_1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMTdialog_1();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
