
// MFC28Dlg.h : ͷ�ļ�
//

#pragma once
#include "FMTDialog.h"

// CMFC28Dlg �Ի���
class CMFC28Dlg : public CDialog
{
// ����
public:
	CMFC28Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC28_DIALOG };

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


public:
	// ��Ϊ�����ĳ�Ա�����ķ�ģ̬�Ի���Ķ���
	CFMTDialog FMTdig;
	CFMTDialog* Pdig_1;
};
