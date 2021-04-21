#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

void test05()
{
	/*CreateFile(·������дȨ�ޣ�����ģʽ����ȫ������)���ļ����ߴ����ļ�*/
	/*��дȨ��:0 ��Ȩ�� GENERIC_READ ֻ�� GENERIC_WRITE ֻд ����|*/
	/*����ģʽ:0 ��ռ*/
	/*��ȫ������:NULL Ĭ��*/

	/*����һ���µĿհ��ļ�*/
	//HANDLE hFile = CreateFile(_T("F:\\����\\�հ��ļ�.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	/*·�� ��дȨ�� ����ģʽ[�ڲ����������˶��ܶ�] ��ȫ������NULLĬ�� ����ͬ�����������ļ� �ļ�����������û���������Ե� ģ��*/
	/*��һ���Ѿ����ڵ��ļ� CREATE_ALWAYS --> OPEN_EXISTING */
	//HANDLE hFile = CreateFile(_T("F:\\����\\�հ��ļ�.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	/*���ļ������򿪣�û���򴴽�һ��  OPEN_EXISTING --> OPEN_ALWAYS */
	HANDLE hFile = CreateFile(_T("F:\\����\\�հ��ļ�.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	/*INVALID_HANDLE_VALUE �ļ���ʧ�ܷ���ֵ ��Ч���*/
	if (hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("�ļ��򿪳ɹ�"), _T("tip"), MB_OK);
		/*�ر��ļ� CloseHandle �رվ��*/
		CloseHandle(hFile);
	}
	else
	{
		MessageBox(NULL, _T("�ļ���ʧ��"), _T("tip"), MB_OK);
	}
	;
}


int WINAPI _tWinMain4(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test05();
	return 0;
}