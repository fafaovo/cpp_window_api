#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>
#pragma comment(lib, "Urlmon.lib")


int WINAPI _tWinMain1(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	/*�ļ����غ���:URLDownloadToFile(NULL,����url��ַ,���λ�ú�����,0,����״̬[�������ҪΪNULL])*/
	/*ִ���ļ�����:ShellExecuteEx(SHELLEXECUTEINFO����)*/
	HRESULT href = URLDownloadToFile(NULL, _T("https://i0.hdslb.com/bfs/vc/c1e19150b5d1e413958d45e0e62f012e3ee200af.png"),_T("F:\\123.png"), 0,NULL);
	//if (href == S_OK)
	//{
	//	MessageBox(NULL, _T("���سɹ�"), _T("Tip"), MB_OK);
	//}
	//else
	//{
	//	MessageBox(NULL, _T("����ʧ��"), _T("Tip"), MB_OK);
	//}

	//ʵ�����ṹ��
	SHELLEXECUTEINFO shellInfo = { 0 };
	//�����ֽ���,�ڲ�������ͨ������ֽ���ȷ����İ汾
	shellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	//�򿪷�ʽ ��·��
	shellInfo.lpVerb = _T("oepn");
	shellInfo.lpFile = _T("notepad.exe");
	//��ʾ��ʽ
	shellInfo.nShow = SW_SHOW;
	BOOL bret = ShellExecuteEx(&shellInfo);
	return 0;
}