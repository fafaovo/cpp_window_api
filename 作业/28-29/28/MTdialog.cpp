// MTdialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "28.h"
#include "MTdialog.h"
#include "afxdialogex.h"


// CMTdialog �Ի���

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


// CMTdialog ��Ϣ�������


void CMTdialog::PostNcDestroy()
{
	// TODO:  �ڴ����ר�ô����/����û���

	CDialogEx::PostNcDestroy();
}
