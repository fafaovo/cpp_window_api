// FMTDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC28.h"
#include "FMTDialog.h"
#include "afxdialogex.h"


// CFMTDialog �Ի���

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


// CFMTDialog ��Ϣ�������


void CFMTDialog::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	DestroyWindow();
}


void CFMTDialog::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���
	DestroyWindow();
	// CDialog::OnCancel(); �����ģ̬�����ٷ���
}


void CFMTDialog::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	DestroyWindow();
	// CDialog::OnOK();
}

// ��Ϊǰ��new��,������Ҫdelete��
void CFMTDialog::PostNcDestroy()
{
	// TODO:  �ڴ����ר�ô����/����û���
	delete this;
	CDialog::PostNcDestroy();
}


BOOL CFMTDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetDlgItemText(IDC_EDIT1,_T("�ÿ���"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
