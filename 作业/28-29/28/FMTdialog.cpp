// FMTdialog.cpp : 实现文件
//

#include "stdafx.h"
#include "28.h"
#include "FMTdialog.h"
#include "afxdialogex.h"
#include "28Dlg.h"


// CFMTdialog 对话框

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


// CFMTdialog 消息处理程序


void CFMTdialog::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	UpdateData(TRUE);
	CMy28Dlg* Parent = (CMy28Dlg*)GetParent();
	Parent->SetDlgItemText(IDC_EDIT1, Edit_val_1);



	DestroyWindow();
	// CDialogEx::OnCancel();
}


void CFMTdialog::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类
	// DestroyWindow();
	// CDialogEx::OnOK();
	this->ShowWindow(SW_HIDE);
}


void CFMTdialog::PostNcDestroy()
{
	// TODO:  在此添加专用代码和/或调用基类
	CDialogEx::PostNcDestroy();
}


BOOL CFMTdialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(IDC_EDIT1, _T("请输入文字"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
