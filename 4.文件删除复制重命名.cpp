#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>
#pragma comment(lib, "Urlmon.lib")

void test01()
{
	/*DeleteFile(�ļ��� ָ��)�ļ�ɾ��*/
	BOOL bRet = DeleteFile(_T("F:\\123.png"));
	if (bRet)
	{
		MessageBox(NULL, _T("ɾ���ɹ�"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("ɾ��ʧ��"), _T("Tip"), MB_OK);
	}
	//�κ���ҵ:���ɾ����ֻ�����Ե�
}

void test02()
{
	/*CopyFile(Դ�ļ�·��,Ŀ��·��,BOOL)�ļ�����*/
	/*BOOL����TRUE���Ŀ���ļ����ڲ����� ����false  ����FALSE ���Ŀ���ļ��Դ��ڣ��򸲸�*/
	BOOL bRet = CopyFile(_T("F:\\465.txt"), _T("F:\\����\\465.txt"), FALSE);
	if (bRet)
	{
		MessageBox(NULL, _T("�����ɹ�"), _T("���Ǳ���"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("����ʧ��"), _T("���Ǳ���"), MB_OK);
	}
}

void test03()
{
	/*MoveFile�ļ��ƶ�*/
	/*
	BOOL MoveFile(
	LPCTSTR IpExstingFileName,   //Դ�ļ�·��
	LPCTSTR IpNewFileName		 //Ŀ���ļ�·��
	)
	*/
	MoveFile(_T("F:\\465.txt"), _T("F:\\����\\465.txt"));
}

int WINAPI _tWinMain2(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test03();
	return 0;
}