#include "head.h"


//����������

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("��֪����ɶ�õĳ���");
//�ؼ�id����
UINT IDC_BUTTON_1 = 301;
UINT IDC_BUTTON_2 = 302;
UINT IDC_BUTTON_3 = 303;
UINT IDC_EDIT_1 = 401;
UINT IDC_LIST_1 = 501;
//ȫ�ֿؼ�
HWND EDIT = NULL;
HWND hListCtrl = NULL;
//����
UINT IDC_Column = 0;
UINT IDC_Line = 0;
//������˫����洢����
LPMyListNode S;




//���岽�����ں����д�������Ϣ
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("��Ҳ��֪�������ɶ��!");

	switch (uMsg)
	{
	case WM_CREATE:  	//����Ĵ���
	{
		//��ť
		HWND button1 = CreateWindow(WC_BUTTON, _T("�����־"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 0, 420, 80, 40, hWnd, (HMENU)IDC_BUTTON_1, NULL, NULL);
		HWND button2 = CreateWindow(WC_BUTTON, _T("ɾ����־"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 80, 420, 80, 40, hWnd, (HMENU)IDC_BUTTON_2, NULL, NULL);
		HWND button3 = CreateWindow(WC_BUTTON, _T("������־"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 400, 420, 80, 40, hWnd, (HMENU)IDC_BUTTON_3, NULL, NULL);
		//�༭��
		EDIT = CreateWindow(WC_EDIT, _T("������һЩ����"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 0, 340, 482, 80, hWnd, (HMENU)IDC_EDIT_1, NULL, NULL);
		//��̬��
		hListCtrl = CreateWindow(WC_LISTVIEW, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 0, 40, 482, 300, hWnd, (HMENU)IDC_LIST_1, NULL, NULL);
		ListView_SetExtendedListViewStyle(hListCtrl, LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		//���þ�̬��ĵ�һ��
		LVCOLUMN colInfo = { 0 };
		colInfo.mask |= LVCF_WIDTH | LVCF_TEXT;
		colInfo.cx = 320;
		colInfo.pszText = _T("��־");
		ListView_InsertColumn(hListCtrl, 0, &colInfo);
		colInfo.cx = 130;
		colInfo.pszText = _T("ʱ��");
		ListView_InsertColumn(hListCtrl, 1, &colInfo);

		
		

	}
		break;
	case WM_COMMAND:  	//��ť�Ĵ���
	{
		UINT nCtrIID = LOWORD(wParam);
		UINT nCode = HIWORD(wParam);
		//BN_CLICKED��ť������ʱ
		if (nCode == BN_CLICKED)
		{
			if (nCtrIID == IDC_BUTTON_1)
			{
				TCHAR mytext[50] = { 0 };
				GetWindowText(EDIT,mytext,256); //��ȡ�༭�������
				//��ȡ�б��ж�����
				int countrow = ListView_GetItemCount(hListCtrl);
				LV_ITEM row_item = { 0 };
				row_item.mask |= LVIF_TEXT;
				row_item.pszText = mytext;
				row_item.iItem = 0;
				ListView_InsertItem(hListCtrl, &row_item);

				//��ȡʱ��
				TCHAR nowtime[50] = { 0 };
				struct tm *p;
				time_t now;
				time(&now);
				p = localtime(&now);
				_stprintf(nowtime, _T("%d/%d/%d %d:%d:%d"), p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
				
				ListView_SetItemText(hListCtrl, 0, 1, nowtime);	
		
				//ͷ��
				pushFornta(S, mytext, nowtime);
			}
			if (nCtrIID == IDC_BUTTON_2)
			{
				int countrow = ListView_GetItemCount(hListCtrl);
				ListView_DeleteItem(hListCtrl, countrow - 1);

				//βɾ
				popFornta(S);
			}
			if (nCtrIID == IDC_BUTTON_3)
			{
				LPMyListNode cur = S->next;
				if (cur == S)
				{
					MessageBox(NULL, _T("Ī�ö�������"), _T("tip"), MB_OK);
				}
				else
				{
					HANDLE hFilea = CreateFile(_T("include.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
					if (hFilea == INVALID_HANDLE_VALUE)
					{
						MessageBox(NULL, _T("�ļ���ʧ��"), _T("tip"), MB_OK);
					}
					else
					{
						CString num = _T("��־����:\n");
						while (cur != S)
						{
							num += cur->date + _T("\t") + cur->time + _T("\n");
							cur = cur->next;
						}
						num += _T("��ûд������");
						DWORD dwRealWrite = 0;
						MessageBox(NULL, num, _T("tip"), MB_OK);
						
					}
					CloseHandle(hFilea);
				}
				

			}
		}
	}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	S = ListInit();
	//��һ�� ע�ᴰ����
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	//�����ദ�������ڴ�������Ϣ
	wcex.lpfnWndProc = WindowProc;
	//����������
	wcex.lpszClassName = szWindowClass;
	//ע�ᴰ��������
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("ע�ᴰ����ʧ��"), _T("Tip"), NULL);
		return 1;
	}
	//�ڶ��� ��������d
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		500, 200,
		500, 500,
		NULL, NULL,
		hInstance,
		NULL
		);
	if (!hWnd)
	{
		MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("Tip"), NULL);
		return 1;
	}

	//������ ��ʾ����
	ShowWindow(hWnd, nCmdShow);
	//���Ĳ� ��ʼ��Ϣѭ��
	MSG msg = { 0 };
	while (GetMessage(&msg,NULL,0,0))
	{
		//��Ϣת��
		TranslateMessage(&msg);
		//��Ϣ�ַ�
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}