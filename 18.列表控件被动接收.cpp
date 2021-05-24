#include <windows.h>
#include <tchar.h>
#include <commctrl.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("tip");

//全部变量按钮的控件ID
UINT IDC_BUTTON_1 = 201;
UINT IDC_BUTTON_2 = 202;
UINT IDC_BUTTON_3 = 203;
UINT IDC_BUTTON_4 = 204;
UINT IDC_EDIT_1 = 301;
UINT IDC_LIST_1 = 401;
//必须作为静态变量在函数执行完后才会被保存
static int index = 1;
UINT line = 0;  //行
UINT column = 0;  //列
HWND EDIT = NULL;
HWND hListCtrl = NULL;

/*HDN_ITEMCLICK 点击表头 NM_CLICK 点击内容  NM_CLICK依赖于WM_NOTIFY*/

//第五步：窗口函数中处理窗口消息 窗口句柄 消息号
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	TCHAR buttonindex[128] = { 0 };

	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("hello world!");

	switch (uMsg)
	{
		/*第二种创建组件的位置*/
	case WM_CREATE:
		{	
			//指定注册窗口类,窗口标题.窗口样式(子窗口，下压式按钮，可见的),XY,宽高，父窗口，菜单|控件的ID(方便操作)，实例句柄，参数	
			HWND hButton1 = CreateWindow(WC_BUTTON, _T("单击次数"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 0, 20, 80, 40, hWnd, (HMENU)IDC_BUTTON_1, NULL, NULL);
			HWND hButton2 = CreateWindow(WC_BUTTON, _T("获取文字"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 80, 20, 80, 40, hWnd, (HMENU)IDC_BUTTON_2, NULL, NULL);
			HWND hButton3 = CreateWindow(WC_BUTTON, _T("发送消息"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 0, 60, 80, 40, hWnd, (HMENU)IDC_BUTTON_3, NULL, NULL);
			HWND hButton4 = CreateWindow(WC_BUTTON, _T("删除消息"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 80, 60, 80, 40, hWnd, (HMENU)IDC_BUTTON_4, NULL, NULL);

			EDIT = CreateWindow(WC_EDIT, _T("我是编辑框"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 160, 20, 200, 200, hWnd, (HMENU)IDC_EDIT_1, NULL, NULL);

			//LVS_REPORT 报表样式  LVS_SHOWSELALWAYS 一直显示选中 

			hListCtrl = CreateWindow(WC_LISTVIEW, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 360, 20, 400, 200, hWnd, (HMENU)IDC_LIST_1, NULL, NULL);
			//LVS_EX_FULLROWSELECT设置整行选中  LVS_EX_GRIDLINES 表格样式 LVS_EX_CHECKBOXES 勾选框
			ListView_SetExtendedListViewStyle(hListCtrl, LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);


			/*给报表控件插入列 要插入列就需要给他发消息
			（句柄 发消息 那一列）
			*/
			LVCOLUMN colInfo = { 0 };
			//生效的成员 宽度 文本
			colInfo.mask |= LVCF_WIDTH | LVCF_TEXT | LVCF_FMT;
			colInfo.cx = 100;
			colInfo.pszText = _T("第0列");
			colInfo.fmt = LVCFMT_LEFT;
			/*SendMessage(hListCtrl, LVM_INSERTCOLUMN, 0,(LPARAM)&colInfo);*/

			//微软封装的宏
			ListView_InsertColumn(hListCtrl, 0, &colInfo);

			LVCOLUMN colInfo_2 = { 0 };
			//生效的成员 宽度 文本
			colInfo_2.mask |= LVCF_WIDTH | LVCF_TEXT;
			colInfo_2.cx = 100;
			colInfo_2.pszText = _T("第1列");
			SendMessage(hListCtrl, LVM_INSERTCOLUMN, 1, (LPARAM)&colInfo_2);
			colInfo_2.pszText = _T("第2列");
			SendMessage(hListCtrl, LVM_INSERTCOLUMN, 2, (LPARAM)&colInfo_2);
			colInfo_2.pszText = _T("第3列");
			SendMessage(hListCtrl, LVM_INSERTCOLUMN, 3, (LPARAM)&colInfo_2);


			//用这个设置更方便 句柄 行 列 设置的文字
			
			/*ListView_SetItemText(hListCtrl, 1, 1, _T("第二行"));*/
			//listview_getitemcount
		}	
		break;
		/*到此结束*/
		/*按钮点击事件创建*/
	case WM_COMMAND:
		{
				//获取控件ID 
				//wParam：低字节位表示ID号，高字节位表示控件通知，
				//lParam：中保存了控件的句柄。
				UINT nCtrIID = LOWORD(wParam);
				UINT nCode = HIWORD(wParam);
				//BN_CLICKED按钮被按下时
				if (nCode == BN_CLICKED)
				{
					if (nCtrIID == IDC_BUTTON_1)
					{
						_stprintf(buttonindex, _T("点击%d次"), index++);
						MessageBox(NULL, buttonindex, _T("tip"), MB_OK);
					}
						
					if (nCtrIID == IDC_BUTTON_2)
					{
						TCHAR mytext[256] = { 0 };
						//获取句柄中的内容 窗口句柄 控件ID 缓存区 缓存区大小
						//GetDlgItemText(hWnd, IDC_EDIT_1, mytext, 256);
						//这个也能获取到
						GetWindowText(EDIT, mytext, 256);

						//获取列表有多少行
						int countrow = ListView_GetItemCount(hListCtrl);
						//先插入行的信息
						LV_ITEM row_item = { 0 };
						row_item.mask |= LVIF_TEXT;
						row_item.pszText = mytext;
						row_item.iItem = countrow;
						int column = ListView_InsertItem(hListCtrl, &row_item);

						//插入这行的列
						ListView_SetItemText(hListCtrl, column, 1, mytext);
						ListView_SetItemText(hListCtrl, column, 2, mytext);
						ListView_SetItemText(hListCtrl, column, 3, mytext);
						//MessageBox(NULL, mytext, _T("tip"), MB_OK);
					}
					if (nCtrIID == IDC_BUTTON_3)
					{
						ListView_SetItemText(hListCtrl, line, column, _T("第一行"));
						column++;
						if (column == 4)
						{
							line = 0;
							line++;
							
						}			
					}
					if (nCtrIID == IDC_BUTTON_4)
					{
						//删除最后一行
						int countrow = ListView_GetItemCount(hListCtrl);
						ListView_DeleteItem(hListCtrl, countrow-1);
						//删除第一行
						//ListView_DeleteItem(hListCtrl, 0);
					}
						

				}
		}
		break;
	case WM_NOTIFY:
		//处理被动消息
	{
		NMHDR* pNmHdr = (NMHDR*)lParam;
		if (pNmHdr->idFrom == IDC_LIST_1)
			//判断控件ID
		{
			if (pNmHdr->code == NM_CLICK)
				//判断为点击事件
			{
				LPNMLISTVIEW ipnmitem = (LPNMLISTVIEW)lParam;

				TCHAR szText[128] = { 0 };
				_stprintf(szText,_T("点击的是 %d 行, %d 列"), ipnmitem->iItem, ipnmitem->iSubItem);
				MessageBox(NULL, szText, _T("tip"), MB_OK);
			}
			
		}
		if (pNmHdr->code == HDN_ENDTRACK)
			//窗口拖拽结束时			
		{
			HWND hListHeader = ListView_GetHeader(hListCtrl);
			if (hListHeader == pNmHdr->hwndFrom)
				//判断你点击的是哪一个静态窗口
			{
				LPNMLISTVIEW ipnmitem = (LPNMLISTVIEW)lParam;
				//获取列的宽度
				int width = ListView_GetColumnWidth(hListCtrl, ipnmitem->iItem);

				TCHAR szText[128] = { 0 };
				_stprintf(szText, _T("第 %d 列的宽度是 %d "), ipnmitem->iItem, width);
				MessageBox(NULL, szText, _T("tip"), MB_OK);

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
	//第一步：注册窗口类，指定窗口类的名称与窗口回调函数
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	//处理窗口的消息队列，这个是个地址
	wcex.lpfnWndProc = WindowProc;
	//窗口类名称
	wcex.lpszClassName = szWindowClass;

	//注册这个窗口类
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("注册窗口类失败"), _T("Tip"), NULL);
		return 1;
	}

	//第二步：创建窗口，指定注册窗口类，窗口标题，窗口的大小
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 400,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	if (!hWnd)
	{
		MessageBox(NULL, _T("创建窗口失败！"), _T("Tip"), NULL);
		return 1;
	}

	/////在这里可以创建子窗口或者控件 第一种方法/////

	//第三步：显示窗口 窗口句柄 显示状态
	ShowWindow(hWnd, nCmdShow);

	//第四步：开始消息循环
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//消息的转换
		TranslateMessage(&msg);
		//消息分发
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}