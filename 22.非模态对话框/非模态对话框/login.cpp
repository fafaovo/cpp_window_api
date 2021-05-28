#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"

INT_PTR WINAPI DialogProc1(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	//照搬消息处理 但是关闭函数不一样  DestroyWindow
	switch (uMsg)
	{
		//对话框初始化的消息是WM_INITDIALOG 模态和非模态都适用 
	case WM_INITDIALOG:
	{


	}
		break;
	case WM_COMMAND:
	{
					   UINT nCtrIID = LOWORD(wParam);
					   UINT nCode = HIWORD(wParam);
					   if (nCode == BN_CLICKED)
					   {
						   if (nCtrIID == IDCANCEL)
						   {
							   //取消按钮和右上角的X按钮
							   int iRet = MessageBox(NULL, _T("你确定要关闭吗"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //此处的IDOK和确定按钮是同一个
							   {
								   DestroyWindow(hwndDIg);
							   }
						   }
					   }
					   return TRUE; //在对话框中处理了消息最好return true
	}
		break;
	default:
		break;
	}
	return FALSE;
}

INT_PTR WINAPI DialogProc2(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	//照搬消息处理 但是关闭函数不一样  DestroyWindow
	switch (uMsg)
	{
		//对话框初始化的消息是WM_INITDIALOG 模态和非模态都适用 
	case WM_INITDIALOG:
	{


	}
		break;
	case WM_COMMAND:
	{
					   UINT nCtrIID = LOWORD(wParam);
					   UINT nCode = HIWORD(wParam);
					   if (nCode == BN_CLICKED)
					   {
						   if (nCtrIID == IDCANCEL)
						   {
							   //取消按钮和右上角的X按钮
							   int iRet = MessageBox(NULL, _T("你确定要关闭吗"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //此处的IDOK和确定按钮是同一个
							   {
								   EndDialog(hwndDIg, 888);
							   }
						   }
					   }
					   return TRUE; //在对话框中处理了消息最好return true
	}
		break;
	default:
		break;
	}
	return FALSE;
}

INT_PTR WINAPI DialogProc(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	//照搬消息处理 但是关闭函数不一样  DestroyWindow
	switch (uMsg)
	{
		//对话框初始化的消息是WM_INITDIALOG 模态和非模态都适用 
	case WM_INITDIALOG:
	{
						 

	}
		break;
	case WM_COMMAND:
	{
					   UINT nCtrIID = LOWORD(wParam);
					   UINT nCode = HIWORD(wParam);
					   if (nCode == BN_CLICKED)
					   {
						   if (nCtrIID == IDC_BUTTON1)
						   {
							   //创建模态 执行位置,对话框标识符,父窗口,处理函数的指针[没写,所以先传他自己吧]
							   DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG_CHILD), hwndDIg, DialogProc2);
						   }
						   else if (nCtrIID == IDC_BUTTON2)
						   {
							   //创建非模态
							   HWND a = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG_CHILD), hwndDIg, DialogProc1);
							   ShowWindow(a, SW_SHOW);
						   }
						   else if (nCtrIID == IDCANCEL)
						   {
							   //取消按钮和右上角的X按钮
							   int iRet = MessageBox(NULL, _T("你确定要关闭吗"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //此处的IDOK和确定按钮是同一个
							   {
								   DestroyWindow(hwndDIg);
								   //给msg消息循环发送一个退出码
								   PostQuitMessage(888);
							   }
						   }
					   }
					   return TRUE; //在对话框中处理了消息最好return true
	}
		break;
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//跟模态对话框[DialogBox]基本一致，但是非模态对话框不会堵塞,所以需要个循环
	HWND hWndDig = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	ShowWindow(hWndDig, SW_SHOW); //显示窗口

	//并且让他消息循环
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//消息的转换
		TranslateMessage(&msg);
		//消息分发
		DispatchMessage(&msg);
	}

	//在使用模态对话框时一般为子窗口 不需要加消息循环也不需要加 PostQuitMessage();
	return 0;
}