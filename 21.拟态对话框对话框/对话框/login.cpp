#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"

//WINAPI 调用约定
INT_PTR WINAPI DialogProc(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	return 0;
}