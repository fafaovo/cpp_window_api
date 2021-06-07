// Dialog_1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC28.h"
#include "Dialog_1.h"
#include "afxdialogex.h"


// Dialog_1 对话框

IMPLEMENT_DYNAMIC(Dialog_1, CDialogEx)

Dialog_1::Dialog_1(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dialog_1::IDD, pParent)
{

}

Dialog_1::~Dialog_1()
{
}

void Dialog_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog_1, CDialogEx)
END_MESSAGE_MAP()


// Dialog_1 消息处理程序


BOOL Dialog_1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(IDC_EDIT1, _T("欢迎来到模态对话框！"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
