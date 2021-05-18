#include <windows.h>
#include <tchar.h>
#include <commctrl.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("tip");

//全部变量按钮的控件ID
UINT IDC_BUTTON_1 = 201;
UINT IDC_BUTTON_2 = 202;
UINT IDC_EDIT_1 = 301;
//必须作为静态变量在函数执行完后才会被保存
static int index = 1;


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
			HWND EDIT = CreateWindow(WC_EDIT, _T("我是编辑框"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 160, 20, 200, 200, hWnd, (HMENU)IDC_EDIT_1, NULL, NULL);
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
						//窗口句柄 控件ID 缓存区 缓存区大小
						GetDlgItemText(hWnd, IDC_EDIT_1, mytext, 256);
						MessageBox(NULL, mytext, _T("tip"), MB_OK);
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