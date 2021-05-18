#include <windows.h>
#include <tchar.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("tip");

//第五步：窗口函数中处理窗口消息
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("hello world!");

	switch (uMsg)
	{
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
		500, 300,
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

	/////在这里可以创建子窗口或者控件/////

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