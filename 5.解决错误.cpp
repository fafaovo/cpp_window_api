#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

/*
1.һ��������жϺ����Ƿ�ִ�гɹ�
2.һ��û�з���ֵ�ĺ�����ôһ�㶼��ִ�гɹ�
3.���Ҵ���ĺ���DWORD GetLastError(VOID)   
��ȡ����һ��ִ�еĺ����Ĵ���ֵ
΢���ṩ��api��������������ܻ�ȡ�� ��ȡ����ֵ����ͨ�� ����-�������
*/

VOID test04()
{
	BOOL bRet = DeleteFile(_T("F:\\123.txt"));
	if (bRet)
	{
		MessageBox(NULL, _T("ɾ���ɹ�"), _T("���Ǳ���"), MB_OK);
	}
	else
	{
		DWORD dwError = GetLastError();
		if (dwError == 2)
			//���ǲ��Ƽ�ʹ��2���Ƽ�ʹ�ú�
			//���Ҵ����ʹ�� Win32 Error Code
		{
			MessageBox(NULL, _T("�ļ�������"), _T("���Ǳ���"), MB_OK);
		}
		MessageBox(NULL, _T("ɾ��ʧ��"), _T("���Ǳ���"), MB_OK);
		
		

		
	}

	
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test04();
	system("pause");
	return 0;
}