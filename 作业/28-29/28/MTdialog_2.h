#pragma once


// CMTdialog_2 �Ի���

class CMTdialog_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CMTdialog_2)

public:
	CMTdialog_2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMTdialog_2();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
