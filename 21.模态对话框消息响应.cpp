#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"
#define _CRT_SECURE_NO_WARNINGS 1

//WINAPI ����Լ��
INT_PTR WINAPI DialogProc(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	switch (uMsg)
	{
		//�Ի����ʼ������Ϣ��WM_INITDIALOG ģ̬�ͷ�ģ̬������
	case WM_INITDIALOG:
	{
						//ͨ��lID��ȡ���ھ��
						HWND List_1 = GetDlgItem(hwndDIg, IDC_LIST1);
						//ͨ�����ھ�����lID
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
							   MessageBox(NULL, _T("��ť4��������"), _T("tip"), MB_OK);
						   }
						   else if (nCtrIID == IDC_BUTTON5)
						   {
							   MessageBox(NULL, _T("��ť5��������"), _T("tip"), MB_OK);
						   }
						   else if (nCtrIID == IDC_BUTTON6)
						   {
							   MessageBox(NULL, _T("��ť6��������"), _T("tip"), MB_OK);
						   }
						   else if (nCtrIID == IDCANCEL)
						   {
							   //ȡ����ť�����Ͻǵ�X��ť
							   int iRet = MessageBox(NULL, _T("��ȷ��Ҫ�ر���"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //�˴���IDOK��ȷ����ť��ͬһ��
							   {
								   //�˴���888����Ϊ��[DialogBox]�����ķ���ֵ
								   EndDialog(hwndDIg, 888);
							   }   
						   }
					   }
					   return TRUE; //�ڶԻ����д�������Ϣ���return true
	}
		break;
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//������ȡ����ť���˴�����ֵΪ888    EndDialog(hwndDIg, 888);
	int nRet = DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	return 0;
}