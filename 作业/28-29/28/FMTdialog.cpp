// FMTdialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "28.h"
#include "FMTdialog.h"
#include "afxdialogex.h"
#include "28Dlg.h"


// CFMTdialog �Ի���

IMPLEMENT_DYNAMIC(CFMTdialog, CDialogEx)

CFMTdialog::CFMTdialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFMTdialog::IDD, pParent)
	, Edit_val_1(_T(""))
{

}

CFMTdialog::~CFMTdialog()
{
}

void CFMTdialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Edit_val_1);
}


BEGIN_MESSAGE_MAP(CFMTdialog, CDialogEx)
END_MESSAGE_MAP()


// CFMTdialog ��Ϣ�������


void CFMTdialog::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���
	UpdateData(TRUE);
	CMy28Dlg* Parent = (CMy28Dlg*)GetParent();
	Parent->SetDlgItemText(IDC_EDIT1, Edit_val_1);



	DestroyWindow();
	// CDialogEx::OnCancel();
}


void CFMTdialog::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	// DestroyWindow();
	// CDialogEx::OnOK();
	this->ShowWindow(SW_HIDE);
}


void CFMTdialog::PostNcDestroy()
{
	// TODO:  �ڴ����ר�ô����/����û���
	CDialogEx::PostNcDestroy();
}


BOOL CFMTdialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetDlgItemText(IDC_EDIT1, _T("����������"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
