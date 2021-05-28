#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"
#define _CRT_SECURE_NO_WARNINGS 1

//WINAPI 调用约定
INT_PTR WINAPI DialogProc(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	switch (uMsg)
	{
		//对话框初始化的消息是WM_INITDIALOG 模态和非模态都适用
	case WM_INITDIALOG:
	{
						//通过lID获取窗口句柄
						HWND List_1 = GetDlgItem(hwndDIg, IDC_LIST1);
						//通过窗口句柄获得lID
						int List_1_lID = GetDlgCtrlID(List_1);
							
	}
		break;
	case WM_COMMAND:
	{
					   UINT nCtrIID = LOWORD(wParam);
					   UINT nCode = HIWORD(wParam);
					   if (nCode == BN_CLICKED)
					   {
						   if (nCtrIID == IDC_BUTTON4)
						   {
							   MessageBox(NULL, _T("按钮4被按下了"), _T("tip"), MB_OK);
						   }
						   else if (nCtrIID == IDC_BUTTON5)
						   {
							   MessageBox(NULL, _T("按钮5被按下了"), _T("tip"), MB_OK);
						   }
						   else if (nCtrIID == IDC_BUTTON6)
						   {
							   MessageBox(NULL, _T("按钮6被按下了"), _T("tip"), MB_OK);
						   }
						   else if (nCtrIID == IDCANCEL)
						   {
							   //取消按钮和右上角的X按钮
							   int iRet = MessageBox(NULL, _T("你确定要关闭吗"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //此处的IDOK和确定按钮是同一个
							   {
								   //此处的888会作为该[DialogBox]函数的返回值
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//如果点击取消按钮，此处返回值为888    EndDialog(hwndDIg, 888);
	int nRet = DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	return 0;
}