#include "head.h"


//窗口类名称

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("不知道有啥用的程序");
//控件id创建
UINT IDC_BUTTON_1 = 301;
UINT IDC_BUTTON_2 = 302;
UINT IDC_BUTTON_3 = 303;
UINT IDC_EDIT_1 = 401;
UINT IDC_LIST_1 = 501;
//全局控件
HWND EDIT = NULL;
HWND hListCtrl = NULL;
//行数
UINT IDC_Column = 0;
UINT IDC_Line = 0;
//建立个双链表存储东西
LPMyListNode S;




//第五步：窗口函数中处理窗口消息
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("我也不知道这个有啥用!");

	switch (uMsg)
	{
	case WM_CREATE:  	//组件的创建
	{
		//按钮
		HWND button1 = CreateWindow(WC_BUTTON, _T("添加日志"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 0, 420, 80, 40, hWnd, (HMENU)IDC_BUTTON_1, NULL, NULL);
		HWND button2 = CreateWindow(WC_BUTTON, _T("删除日志"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 80, 420, 80, 40, hWnd, (HMENU)IDC_BUTTON_2, NULL, NULL);
		HWND button3 = CreateWindow(WC_BUTTON, _T("保存日志"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 400, 420, 80, 40, hWnd, (HMENU)IDC_BUTTON_3, NULL, NULL);
		//编辑框
		EDIT = CreateWindow(WC_EDIT, _T("请输入一些文字"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 0, 340, 482, 80, hWnd, (HMENU)IDC_EDIT_1, NULL, NULL);
		//静态框
		hListCtrl = CreateWindow(WC_LISTVIEW, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 0, 40, 482, 300, hWnd, (HMENU)IDC_LIST_1, NULL, NULL);
		ListView_SetExtendedListViewStyle(hListCtrl, LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		//设置静态框的第一行
		LVCOLUMN colInfo = { 0 };
		colInfo.mask |= LVCF_WIDTH | LVCF_TEXT;
		colInfo.cx = 320;
		colInfo.pszText = _T("日志");
		ListView_InsertColumn(hListCtrl, 0, &colInfo);
		colInfo.cx = 130;
		colInfo.pszText = _T("时间");
		ListView_InsertColumn(hListCtrl, 1, &colInfo);

		
		

	}
		break;
	case WM_COMMAND:  	//按钮的创建
	{
		UINT nCtrIID = LOWORD(wParam);
		UINT nCode = HIWORD(wParam);
		//BN_CLICKED按钮被按下时
		if (nCode == BN_CLICKED)
		{
			if (nCtrIID == IDC_BUTTON_1)
			{
				TCHAR mytext[50] = { 0 };
				GetWindowText(EDIT,mytext,256); //获取编辑框的文字
				//获取列表有多少行
				int countrow = ListView_GetItemCount(hListCtrl);
				LV_ITEM row_item = { 0 };
				row_item.mask |= LVIF_TEXT;
				row_item.pszText = mytext;
				row_item.iItem = 0;
				ListView_InsertItem(hListCtrl, &row_item);

				//获取时间
				TCHAR nowtime[50] = { 0 };
				struct tm *p;
				time_t now;
				time(&now);
				p = localtime(&now);
				_stprintf(nowtime, _T("%d/%d/%d %d:%d:%d"), p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
				
				ListView_SetItemText(hListCtrl, 0, 1, nowtime);	
		
				//头插
				pushFornta(S, mytext, nowtime);
			}
			if (nCtrIID == IDC_BUTTON_2)
			{
				int countrow = ListView_GetItemCount(hListCtrl);
				ListView_DeleteItem(hListCtrl, countrow - 1);

				//尾删
				popFornta(S);
			}
			if (nCtrIID == IDC_BUTTON_3)
			{
				LPMyListNode cur = S->next;
				if (cur == S)
				{
					MessageBox(NULL, _T("莫得东西保存"), _T("tip"), MB_OK);
				}
				else
				{
					HANDLE hFilea = CreateFile(_T("include.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
					if (hFilea == INVALID_HANDLE_VALUE)
					{
						MessageBox(NULL, _T("文件打开失败"), _T("tip"), MB_OK);
					}
					else
					{
						CString num = _T("日志如下:\n");
						while (cur != S)
						{
							num += cur->date + _T("\t") + cur->time + _T("\n");
							cur = cur->next;
						}
						num += _T("还没写保存呢");
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
	//第一步 注册窗口类
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	//窗口类处理函数用于处理窗口信息
	wcex.lpfnWndProc = WindowProc;
	//窗口类名称
	wcex.lpszClassName = szWindowClass;
	//注册窗口类名称
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("注册窗口类失败"), _T("Tip"), NULL);
		return 1;
	}
	//第二步 创建窗口d
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
		MessageBox(NULL, _T("创建窗口失败！"), _T("Tip"), NULL);
		return 1;
	}

	//第三步 显示窗口
	ShowWindow(hWnd, nCmdShow);
	//第四步 开始消息循环
	MSG msg = { 0 };
	while (GetMessage(&msg,NULL,0,0))
	{
		//消息转换
		TranslateMessage(&msg);
		//消息分发
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}