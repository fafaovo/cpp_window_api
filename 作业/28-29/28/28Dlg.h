
// 28Dlg.h : ͷ�ļ�
//

#pragma once
#include "MTdialog.h"
#include "FMTdialog.h"

// CMy28Dlg �Ի���
class CMy28Dlg : public CDialog
{
// ����
public:
	CMy28Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY28_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

public:
	CMTdialog* MTDig;
	CFMTdialog* FMTDig;
	CString m_Edit_1;
	CString m_edit_1_or_2;

};

extern CMy28Dlg * CDigMain;