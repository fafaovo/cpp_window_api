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


/*�ļ�д�� BOOL WriteFile(�ļ����,д�����ݵ��׵�ַ,д�����ݵĳ���DWORD,ʵ����д�����������ָ��,�첽����һ�㴫NULL)*/
void test08()
{
	
	HANDLE hFile = CreateFile(_T("F:\\����\\�հ��ļ�.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("�ļ���ʧ��"), _T("tip"), MB_OK);
		return;
	}

	/*BOOL WriteFile(�ļ����,д�����ݵ��׵�ַ,д�����ݵĳ���DWORD,ʵ����д�����������ָ��,�첽����һ�㴫NULL)*/
	int num = 123;
	DWORD dwRealWrite = 0;
	BOOL bRet = WriteFile(hFile, &num, sizeof(num), &dwRealWrite,NULL);

	char ch = 'q';
	//BOOL bRet = WriteFile(hFile, &ch, sizeof(ch), &dwRealWrite, NULL);

	char szText[] = "helloworld�������";
	//BOOL bRet = WriteFile(hFile, &szText, sizeof(szText), &dwRealWrite, NULL);

	Student stu;
	stu.age = 20;
	stu.sex = 'm';
	strcpy(stu.name, "����");

	BOOL bRet = WriteFile(hFile, &stu, sizeof(stu), &dwRealWrite, NULL);

	if (bRet)
	{
		MessageBox(NULL, _T("����д��ɹ�"),_T("tip"), NULL);
	}
	else
	{
		MessageBox(NULL, _T("����д��ʧ��"), _T("tip"), NULL);
	}
	CloseHandle(hFile);
}

/*�ļ���ȡ BOOL ReadFile(�ļ����,��ȡ���ݵ��׵�ַ,Ҫ�����ֽ���,ʵ�ʶ�ȡ���ֽ���,NULL)*/
void test09()
{
	HANDLE hFile = CreateFile(_T("F:\\����\\�հ��ļ�.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("�ļ���ʧ��"), _T("tip"), MB_OK);
		return;
	}
	DWORD dwRealWrite = 0;
	Student stu;
	BOOL bRet = ReadFile(hFile, &stu, sizeof(stu), &dwRealWrite, NULL);
	if (bRet)
	{
		MessageBox(NULL,_T("д��ɹ�"), _T("tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL,_T("д��ʧ��"), _T("tip"), MB_OK);
	}
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test09();
	return 0;
}