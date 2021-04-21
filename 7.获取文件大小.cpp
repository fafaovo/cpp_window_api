#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

void test06()
{
	/*DWORD GetFileSize(文件句柄,NULL) 返回的是字节 最大返回4GB*/
	/*当超过4G时，NULL就有用了,也是传入一个DWORD指针 他表示的是高32位*/
	HANDLE hFile = CreateFile(_T("F:\\测试\\空白文件.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwHeigtFileSize = 0;
		DWORD dwFileSize =  GetFileSize(hFile, &dwFileSize);

		/*将高32位左移32位,然后或上低32位，就得到一个longlong类型了*/
		LONGLONG lFileSize = ((LONGLONG)dwHeigtFileSize << 32) | dwFileSize;

		//将dwFileSize转换成字符串
		TCHAR szFileSize[128] = { 0 };
		_stprintf(szFileSize, _T("文件大小是: %d kb"), lFileSize / 1024);


		MessageBox(NULL, szFileSize, _T("tip"), MB_OK);	
		CloseHandle(hFile);
	}
	else
	{
		MessageBox(NULL, _T("文件打开失败"), _T("tip"), MB_OK);
	}

}

void test07()
{
	/*BOOL GetFileSizeEX(文件句柄,LARGE_INTEGER联合体指针)*/
	HANDLE hFile = CreateFile(_T("F:\\测试\\空白文件.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	LARGE_INTEGER filesize = { 0 };
	BOOL bRet = GetFileSizeEx(hFile, &filesize);
	if (bRet)
	{
		TCHAR szFileSize[128] = { 0 };
		/*filesize.QuadPart中的一个longlong类型*/
		_stprintf(szFileSize, _T("文件大小是: %d kb"), filesize.QuadPart / 1024);
		MessageBox(NULL, szFileSize, _T("tip"), MB_OK);
	}

	
	CloseHandle(hFile);
}


int WINAPI _tWinMain5(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test07();
	return 0;
}