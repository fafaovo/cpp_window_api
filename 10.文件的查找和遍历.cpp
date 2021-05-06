#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>


//�ļ�·�����ļ�����
BOOL EnumFiles(LPCTSTR lpszPath, LPCTSTR lpszType)
{
	TCHAR szPath[MAX_PATH] = { 0 };
	//MAX_PATH �����˱�������֧�ֵ��·����
	_stprintf(szPath, _T("%s\\%s"), lpszPath, lpszType);

	WIN32_FIND_DATA FindDate;
	

	HANDLE hFind = FindFirstFile(szPath, &FindDate);

	if (hFind == INVALID_HANDLE_VALUE) return FALSE;
	//�������ʧ��ֱ�ӷ��� INVALID_HANDLE_VALUE����ʧ�ܻ᷵�ص�ֵ

	BOOL bRet = FALSE;
	do
	{
		bRet = FindNextFile(hFind, &FindDate);
		if (!bRet) break;

		if ((FindDate.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) > 0)
		{
			cout << "Ŀ¼ ";
		}
		else
		{
			cout << "�ļ� ";
		}

		cout << FindDate.cFileName << endl;

	} while (bRet);
	return TRUE;
}

void test02()
{
	/*FindFirstFile(Ҫ���ҵ��ļ���֧��ͨ���,���������ļ�����LPWIN32_FIND_DATA)
	Ҫ���ҵ��ļ���֧��ͨ���: *.*�����ļ�
	����ֵ��һ��HANDLE���͵��ļ����������������ɺ�ʹ��FindClose�رվ��

	���� FindNextFile(�ļ�������������������ļ�����WIN32_FIND_DATA)
	���ڱ���Ŀ¼���ļ����жϵ�ǰĿ¼���Ƿ�����һ��Ŀ¼���ļ�
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