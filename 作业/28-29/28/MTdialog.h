#pragma once


// CMTdialog �Ի���

class CMTdialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMTdialog)

public:
	CMTdialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMTdialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
};
