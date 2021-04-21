#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

class Student
{
public:
	int age;
	char sex;
	char name[32];
};


/*文件写入 BOOL WriteFile(文件句柄,写入数据的首地址,写入数据的长度DWORD,实际上写入的数据量的指针,异步操作一般传NULL)*/
void test08()
{
	
	HANDLE hFile = CreateFile(_T("F:\\测试\\空白文件.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("文件打开失败"), _T("tip"), MB_OK);
		return;
	}

	/*BOOL WriteFile(文件句柄,写入数据的首地址,写入数据的长度DWORD,实际上写入的数据量的指针,异步操作一般传NULL)*/
	int num = 123;
	DWORD dwRealWrite = 0;
	BOOL bRet = WriteFile(hFile, &num, sizeof(num), &dwRealWrite,NULL);

	char ch = 'q';
	//BOOL bRet = WriteFile(hFile, &ch, sizeof(ch), &dwRealWrite, NULL);

	char szText[] = "helloworld你好世界";
	//BOOL bRet = WriteFile(hFile, &szText, sizeof(szText), &dwRealWrite, NULL);

	Student stu;
	stu.age = 20;
	stu.sex = 'm';
	strcpy(stu.name, "张三");

	BOOL bRet = WriteFile(hFile, &stu, sizeof(stu), &dwRealWrite, NULL);

	if (bRet)
	{
		MessageBox(NULL, _T("数据写入成功"),_T("tip"), NULL);
	}
	else
	{
		MessageBox(NULL, _T("数据写入失败"), _T("tip"), NULL);
	}
	CloseHandle(hFile);
}

/*文件读取 BOOL ReadFile(文件句柄,读取数据的首地址,要读的字节数,实际读取的字节数,NULL)*/
void test09()
{
	HANDLE hFile = CreateFile(_T("F:\\测试\\空白文件.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("文件打开失败"), _T("tip"), MB_OK);
		return;
	}
	DWORD dwRealWrite = 0;
	Student stu;
	BOOL bRet = ReadFile(hFile, &stu, sizeof(stu), &dwRealWrite, NULL);
	if (bRet)
	{
		MessageBox(NULL,_T("写入成功"), _T("tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL,_T("写入失败"), _T("tip"), MB_OK);
	}
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test09();
	return 0;
}