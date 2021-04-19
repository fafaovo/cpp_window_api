#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>
#pragma comment(lib, "Urlmon.lib")

void test01()
{
	/*DeleteFile(文件名 指针)文件删除*/
	BOOL bRet = DeleteFile(_T("F:\\123.png"));
	if (bRet)
	{
		MessageBox(NULL, _T("删除成功"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("删除失败"), _T("Tip"), MB_OK);
	}
	//课后作业:如何删除有只读属性的
}

void test02()
{
	/*CopyFile(源文件路径,目标路径,BOOL)文件拷贝*/
	/*BOOL传递TRUE如果目标文件存在不拷贝 返回false  传递FALSE 如果目标文件以存在，则覆盖*/
	BOOL bRet = CopyFile(_T("F:\\465.txt"), _T("F:\\测试\\465.txt"), FALSE);
	if (bRet)
	{
		MessageBox(NULL, _T("拷贝成功"), _T("这是标题"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("拷贝失败"), _T("这是标题"), MB_OK);
	}
}

void test03()
{
	/*MoveFile文件移动*/
	/*
	BOOL MoveFile(
	LPCTSTR IpExstingFileName,   //源文件路径
	LPCTSTR IpNewFileName		 //目标文件路径
	)
	*/
	MoveFile(_T("F:\\465.txt"), _T("F:\\测试\\465.txt"));
}

int WINAPI _tWinMain2(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test03();
	return 0;
}