
// 26.DigFirstDlg.h : ͷ�ļ�
//

#pragma once


// CMy26DigFirstDlg �Ի���
class CMy26DigFirstDlg : public CDialog
{
// ����
public:
	CMy26DigFirstDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY26DIGFIRST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();  // �Ի����ʼ������
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//�Լ������
public:
	int m_Time;
	//��������
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	virtual void OnCancel();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};
