// MTdialog.cpp : 实现文件
//

#include "stdafx.h"
#include "28.h"
#include "MTdialog.h"
#include "afxdialogex.h"


// CMTdialog 对话框

IMPLEMENT_DYNAMIC(CMTdialog, CDialogEx)

CMTdialog::CMTdialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMTdialog::IDD, pParent)
{

}

CMTdialog::~CMTdialog()
{
}

void CMTdialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMTdialog, CDialogEx)
END_MESSAGE_MAP()


// CMTdialog 消息处理程序


void CMTdialog::PostNcDestroy()
{
	// TODO:  在此添加专用代码和/或调用基类

	CDialogEx::PostNcDestroy();
}
