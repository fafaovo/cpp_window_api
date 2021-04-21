#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

void test06()
{
	/*DWORD GetFileSize(�ļ����,NULL) ���ص����ֽ� ��󷵻�4GB*/
	/*������4Gʱ��NULL��������,Ҳ�Ǵ���һ��DWORDָ�� ����ʾ���Ǹ�32λ*/
	HANDLE hFile = CreateFile(_T("F:\\����\\�հ��ļ�.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwHeigtFileSize = 0;
		DWORD dwFileSize =  GetFileSize(hFile, &dwFileSize);

		/*����32λ����32λ,Ȼ����ϵ�32λ���͵õ�һ��longlong������*/
		LONGLONG lFileSize = ((LONGLONG)dwHeigtFileSize << 32) | dwFileSize;

		//��dwFileSizeת�����ַ���
		TCHAR szFileSize[128] = { 0 };
		_stprintf(szFileSize, _T("�ļ���С��: %d kb"), lFileSize / 1024);


		MessageBox(NULL, szFileSize, _T("tip"), MB_OK);	
		CloseHandle(hFile);
	}
	else
	{
		MessageBox(NULL, _T("�ļ���ʧ��"), _T("tip"), MB_OK);
	}

}

void test07()
{
	/*BOOL GetFileSizeEX(�ļ����,LARGE_INTEGER������ָ��)*/
	HANDLE hFile = CreateFile(_T("F:\\����\\�հ��ļ�.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	LARGE_INTEGER filesize = { 0 };
	BOOL bRet = GetFileSizeEx(hFile, &filesize);
	if (bRet)
	{
		TCHAR szFileSize[128] = { 0 };
		/*filesize.QuadPart�е�һ��longlong����*/
		_stprintf(szFileSize, _T("�ļ���С��: %d kb"), filesize.QuadPart / 1024);
		MessageBox(NULL, szFileSize, _T("tip"), MB_OK);
	}

	
	CloseHandle(hFile);
}


int WINAPI _tWinMain5(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test07();
	return 0;
}