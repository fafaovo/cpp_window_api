#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"

INT_PTR WINAPI DialogProc1(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	//�հ���Ϣ���� ���ǹرպ�����һ��  DestroyWindow
	switch (uMsg)
	{
		//�Ի����ʼ������Ϣ��WM_INITDIALOG ģ̬�ͷ�ģ̬������ 
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
							   //ȡ����ť�����Ͻǵ�X��ť
							   int iRet = MessageBox(NULL, _T("��ȷ��Ҫ�ر���"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //�˴���IDOK��ȷ����ť��ͬһ��
							   {
								   DestroyWindow(hwndDIg);
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

INT_PTR WINAPI DialogProc2(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	//�հ���Ϣ���� ���ǹرպ�����һ��  DestroyWindow
	switch (uMsg)
	{
		//�Ի����ʼ������Ϣ��WM_INITDIALOG ģ̬�ͷ�ģ̬������ 
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
							   //ȡ����ť�����Ͻǵ�X��ť
							   int iRet = MessageBox(NULL, _T("��ȷ��Ҫ�ر���"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //�˴���IDOK��ȷ����ť��ͬһ��
							   {
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

INT_PTR WINAPI DialogProc(HWND hwndDIg, UINT uMsg, WPARAM wParam, LPARAM iparam)
{
	//�հ���Ϣ���� ���ǹرպ�����һ��  DestroyWindow
	switch (uMsg)
	{
		//�Ի����ʼ������Ϣ��WM_INITDIALOG ģ̬�ͷ�ģ̬������ 
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
							   //����ģ̬ ִ��λ��,�Ի����ʶ��,������,��������ָ��[ûд,�����ȴ����Լ���]
							   DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG_CHILD), hwndDIg, DialogProc2);
						   }
						   else if (nCtrIID == IDC_BUTTON2)
						   {
							   //������ģ̬
							   HWND a = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG_CHILD), hwndDIg, DialogProc1);
							   ShowWindow(a, SW_SHOW);
						   }
						   else if (nCtrIID == IDCANCEL)
						   {
							   //ȡ����ť�����Ͻǵ�X��ť
							   int iRet = MessageBox(NULL, _T("��ȷ��Ҫ�ر���"), _T("tip"), MB_OKCANCEL);
							   if (iRet == IDOK) //�˴���IDOK��ȷ����ť��ͬһ��
							   {
								   DestroyWindow(hwndDIg);
								   //��msg��Ϣѭ������һ���˳���
								   PostQuitMessage(888);
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
	//��ģ̬�Ի���[DialogBox]����һ�£����Ƿ�ģ̬�Ի��򲻻����,������Ҫ��ѭ��
	HWND hWndDig = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	ShowWindow(hWndDig, SW_SHOW); //��ʾ����

	//����������Ϣѭ��
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//��Ϣ��ת��
		TranslateMessage(&msg);
		//��Ϣ�ַ�
		DispatchMessage(&msg);
	}

	//��ʹ��ģ̬�Ի���ʱһ��Ϊ�Ӵ��� ����Ҫ����Ϣѭ��Ҳ����Ҫ�� PostQuitMessage();
	return 0;
}