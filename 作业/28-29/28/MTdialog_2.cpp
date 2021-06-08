// MTdialog_2.cpp : 实现文件
//

#include "stdafx.h"
#include "28.h"
#include "MTdialog_2.h"
#include "afxdialogex.h"
#include "28Dlg.h"


// CMTdialog_2 对话框

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


// CMTdialog_2 消息处理程序


void CMTdialog_2::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//CString str;
	//GetDlgItemText(IDC_EDIT1, str);
	//CDigMain->m_edit_1_or_2 = str;
	CDigMain->m_edit_1_or_2 = _T("你好VC驿站");
}


BOOL CMTdialog_2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(IDC_EDIT1, CDigMain->m_edit_1_or_2);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
