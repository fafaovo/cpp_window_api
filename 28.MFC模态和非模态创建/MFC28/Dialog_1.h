#pragma once


// Dialog_1 �Ի���

class Dialog_1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog_1)

public:
	Dialog_1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialog_1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
