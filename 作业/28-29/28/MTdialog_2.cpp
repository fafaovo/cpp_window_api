// MTdialog_2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "28.h"
#include "MTdialog_2.h"
#include "afxdialogex.h"
#include "28Dlg.h"


// CMTdialog_2 �Ի���

IMPLEMENT_DYNAMIC(CMTdialog_2, CDialogEx)

CMTdialog_2::CMTdialog_2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMTdialog_2::IDD, pParent)
{

}

CMTdialog_2::~CMTdialog_2()
{
}

void CMTdialog_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMTdialog_2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMTdialog_2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMTdialog_2 ��Ϣ�������


void CMTdialog_2::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CString str;
	//GetDlgItemText(IDC_EDIT1, str);
	//CDigMain->m_edit_1_or_2 = str;
	CDigMain->m_edit_1_or_2 = _T("���VC��վ");
}


BOOL CMTdialog_2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetDlgItemText(IDC_EDIT1, CDigMain->m_edit_1_or_2);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
