#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

VOID test01()
{
	/*
	设置文件指针
	setFilePointer(已打开的文件句柄,低32位的值,高32位位移的值的指针,起始位置)
	高32位的指针:可以为NULL 
	起始位置取值:FILE_BEGIN 从头 FILE_CURRENT 从当前文件指针开始 FILE_END 从文件末尾开始
	*/

	/*目录的创建
	布尔类型 CreateDirectory(目录的路径,null);
	*/
	CreateDirectory(_T("F:\\测试\\预创建目录"), NULL);

	/*删除目录 只能删除空文件 要删除非空用SHFileOperation
	RemoveDirectory(删除的路径);
	*/
	RemoveDirectory(_T("F:\\测试\\预创建目录"));
}

int WINAPI _tWinMain1(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test01();
	return 0;
}