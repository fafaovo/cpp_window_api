
// TmpFolderCleanerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CTmpFolderCleanerDlg �Ի���
class CTmpFolderCleanerDlg : public CDialogEx
{
// ����
public:
	CTmpFolderCleanerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TMPFOLDERCLEANER_DIALOG };

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
	// ��ʱ�ļ�Ŀ¼
	CListCtrl m_list_1;
	CListCtrl m_list_2;
};
