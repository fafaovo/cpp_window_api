#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

void test05()
{
	/*CreateFile(路径，读写权限，共享模式，安全描述符)打开文件或者创建文件*/
	/*读写权限:0 无权限 GENERIC_READ 只读 GENERIC_WRITE 只写 可用|*/
	/*共享模式:0 独占*/
	/*安全描述符:NULL 默认*/

	/*创建一个新的空白文件*/
	//HANDLE hFile = CreateFile(_T("F:\\测试\\空白文件.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	/*路径 读写权限 共享模式[在操作中其他人都能读] 安全描述符NULL默认 无论同名都创建新文件 文件属性正常的没有其他属性的 模板*/
	/*打开一个已经存在的文件 CREATE_ALWAYS --> OPEN_EXISTING */
	//HANDLE hFile = CreateFile(_T("F:\\测试\\空白文件.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	/*有文件正常打开，没有则创建一个  OPEN_EXISTING --> OPEN_ALWAYS */
	HANDLE hFile = CreateFile(_T("F:\\测试\\空白文件.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	/*INVALID_HANDLE_VALUE 文件打开失败返回值 无效句柄*/
	if (hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("文件打开成功"), _T("tip"), MB_OK);
		/*关闭文件 CloseHandle 关闭句柄*/
		CloseHandle(hFile);
	}
	else
	{
		MessageBox(NULL, _T("文件打开失败"), _T("tip"), MB_OK);
	}
	;
}


int WINAPI _tWinMain4(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test05();
	return 0;
}