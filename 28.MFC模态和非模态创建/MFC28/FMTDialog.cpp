// FMTDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC28.h"
#include "FMTDialog.h"
#include "afxdialogex.h"


// CFMTDialog 对话框

IMPLEMENT_DYNAMIC(CFMTDialog, CDialog)

CFMTDialog::CFMTDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFMTDialog::IDD, pParent)
{

}

CFMTDialog::~CFMTDialog()
{
}

void CFMTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFMTDialog, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CFMTDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CFMTDialog 消息处理程序


void CFMTDialog::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	DestroyWindow();
}


void CFMTDialog::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	DestroyWindow();
	// CDialog::OnCancel(); 这个是模态的销毁方法
}


void CFMTDialog::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类
	DestroyWindow();
	// CDialog::OnOK();
}

// 因为前面new了,所以需要delete掉
void CFMTDialog::PostNcDestroy()
{
	// TODO:  在此添加专用代码和/或调用基类
	delete this;
	CDialog::PostNcDestroy();
}


BOOL CFMTDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(IDC_EDIT1,_T("好卡啊"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
