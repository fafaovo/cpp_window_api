#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>


//文件路径和文件类型
BOOL EnumFiles(LPCTSTR lpszPath, LPCTSTR lpszType)
{
	TCHAR szPath[MAX_PATH] = { 0 };
	//MAX_PATH 定义了编译器所支持的最长路径名
	_stprintf(szPath, _T("%s\\%s"), lpszPath, lpszType);

	WIN32_FIND_DATA FindDate;
	

	HANDLE hFind = FindFirstFile(szPath, &FindDate);

	if (hFind == INVALID_HANDLE_VALUE) return FALSE;
	//如果调用失败直接返回 INVALID_HANDLE_VALUE调用失败会返回的值

	BOOL bRet = FALSE;
	do
	{
		bRet = FindNextFile(hFind, &FindDate);
		if (!bRet) break;

		if ((FindDate.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) > 0)
		{
			cout << "目录 ";
		}
		else
		{
			cout << "文件 ";
		}

		cout << FindDate.cFileName << endl;

	} while (bRet);
	return TRUE;
}

void test02()
{
	/*FindFirstFile(要查找的文件名支持通配符,遍历到的文件属性LPWIN32_FIND_DATA)
	要查找的文件名支持通配符: *.*所有文件
	返回值是一个HANDLE类型的文件搜索句柄，搜索完成后使用FindClose关闭句柄

	布尔 FindNextFile(文件搜索句柄，遍历到的文件属性WIN32_FIND_DATA)
	用于遍历目录或文件，判断当前目录下是否有下一个目录或文件
	*/
	EnumFiles(_T("F:\\"), _T("*.*"));

}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test02();
	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	EnumFiles(_T("D:\\"), _T("*.*"));
	return 0;
}