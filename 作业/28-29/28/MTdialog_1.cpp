// MTdialog_1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "28.h"
#include "MTdialog_1.h"
#include "afxdialogex.h"
#include "28Dlg.h"


// CMTdialog_1 �Ի���

IMPLEMENT_DYNAMIC(CMTdialog_1, CDialogEx)

CMTdialog_1::CMTdialog_1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMTdialog_1::IDD, pParent)
{

}

CMTdialog_1::~CMTdialog_1()
{
}

void CMTdialog_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMTdialog_1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMTdialog_1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMTdialog_1 ��Ϣ�������


void CMTdialog_1::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CString str;
	//GetDlgItemText(IDC_EDIT1, str);
	//CDigMain->m_edit_1_or_2 = str;
	CDigMain->m_edit_1_or_2 = _T("Hello cctry.com");
}


BOOL CMTdialog_1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetDlgItemText(IDC_EDIT1, CDigMain->m_edit_1_or_2);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
