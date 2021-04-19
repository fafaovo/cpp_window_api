#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>
#pragma comment(lib, "Urlmon.lib")


int WINAPI _tWinMain1(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	/*文件下载函数:URLDownloadToFile(NULL,下载url地址,存放位置和名称,0,监视状态[如果不需要为NULL])*/
	/*执行文件函数:ShellExecuteEx(SHELLEXECUTEINFO对象)*/
	HRESULT href = URLDownloadToFile(NULL, _T("https://i0.hdslb.com/bfs/vc/c1e19150b5d1e413958d45e0e62f012e3ee200af.png"),_T("F:\\123.png"), 0,NULL);
	//if (href == S_OK)
	//{
	//	MessageBox(NULL, _T("下载成功"), _T("Tip"), MB_OK);
	//}
	//else
	//{
	//	MessageBox(NULL, _T("下载失败"), _T("Tip"), MB_OK);
	//}

	//实例化结构体
	SHELLEXECUTEINFO shellInfo = { 0 };
	//传入字节数,内部函数会通过这个字节数确定你的版本
	shellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	//打开方式 打开路径
	shellInfo.lpVerb = _T("oepn");
	shellInfo.lpFile = _T("notepad.exe");
	//显示方式
	shellInfo.nShow = SW_SHOW;
	BOOL bret = ShellExecuteEx(&shellInfo);
	return 0;
}