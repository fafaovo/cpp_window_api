
// DriveThiefDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CDriveThiefDlg �Ի���
class CDriveThiefDlg : public CDialog
{
// ����
public:
	CDriveThiefDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DRIVETHIEF_DIALOG };

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
	BOOL GetMaxSpaceDisk(TCHAR* pszDisk,int nDiskBuffLength); //��ȡϵͳ�洢�ռ������̷�
	CListBox LIst_Copy_Type;   //�������ļ�����
	CEdit EDIT_ROUTE_1;    //����·����edit
public:
	CString m_strSavePath;  //·��
};
