// Dialog_1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC28.h"
#include "Dialog_1.h"
#include "afxdialogex.h"


// Dialog_1 �Ի���

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


// Dialog_1 ��Ϣ�������


BOOL Dialog_1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetDlgItemText(IDC_EDIT1, _T("��ӭ����ģ̬�Ի���"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
