#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

/*
1.一般情况下判断函数是否执行成功
2.一般没有返回值的函数那么一般都会执行成功
3.查找错误的函数DWORD GetLastError(VOID)   
获取到上一个执行的函数的错误值
微软提供的api函数错误基本都能获取到 获取到的值可以通过 工具-错误查找
*/

VOID test04()
{
	BOOL bRet = DeleteFile(_T("F:\\123.txt"));
	if (bRet)
	{
		MessageBox(NULL, _T("删除成功"), _T("这是标题"), MB_OK);
	}
	else
	{
		DWORD dwError = GetLastError();
		if (dwError == 2)
			//但是不推荐使用2，推荐使用宏
			//查找错误宏使用 Win32 Error Code
		{
			MessageBox(NULL, _T("文件不存在"), _T("这是标题"), MB_OK);
		}
		MessageBox(NULL, _T("删除失败"), _T("这是标题"), MB_OK);
		
		

		
	}

	
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test04();
	system("pause");
	return 0;
}