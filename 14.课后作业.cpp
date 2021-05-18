#include <windows.h>
#include <tchar.h>
#include <commctrl.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("tip");

//ȫ��������ť�Ŀؼ�ID
UINT IDC_BUTTON_1 = 201;
UINT IDC_BUTTON_2 = 202;
UINT IDC_EDIT_1 = 301;
//������Ϊ��̬�����ں���ִ�����Żᱻ����
static int index = 1;


//���岽�����ں����д�������Ϣ ���ھ�� ��Ϣ��
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	TCHAR buttonindex[128] = { 0 };

	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("hello world!");

	switch (uMsg)
	{
		/*�ڶ��ִ��������λ��*/
	case WM_CREATE:
		{	
			//ָ��ע�ᴰ����,���ڱ���.������ʽ(�Ӵ��ڣ���ѹʽ��ť���ɼ���),XY,��ߣ������ڣ��˵�|�ؼ���ID(�������)��ʵ�����������	
			HWND hButton1 = CreateWindow(WC_BUTTON, _T("��������"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 0, 20, 80, 40, hWnd, (HMENU)IDC_BUTTON_1, NULL, NULL);
			HWND hButton2 = CreateWindow(WC_BUTTON, _T("��ȡ����"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 80, 20, 80, 40, hWnd, (HMENU)IDC_BUTTON_2, NULL, NULL);
			HWND EDIT = CreateWindow(WC_EDIT, _T("���Ǳ༭��"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 160, 20, 200, 200, hWnd, (HMENU)IDC_EDIT_1, NULL, NULL);
		}	
		break;
		/*���˽���*/
		/*��ť����¼�����*/
	case WM_COMMAND:
		{
				//��ȡ�ؼ�ID 
				//wParam�����ֽ�λ��ʾID�ţ����ֽ�λ��ʾ�ؼ�֪ͨ��
				//lParam���б����˿ؼ��ľ����
				UINT nCtrIID = LOWORD(wParam);
				UINT nCode = HIWORD(wParam);
				if (nCode == BN_CLICKED)
				{
					if (nCtrIID == IDC_BUTTON_1)
					{
						_stprintf(buttonindex, _T("���%d��"), index++);
						MessageBox(NULL, buttonindex, _T("tip"), MB_OK);
					}
						
					if (nCtrIID == IDC_BUTTON_2)
					{
						TCHAR mytext[256] = { 0 };
						//���ھ�� �ؼ�ID ������ ��������С
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
	//��һ����ע�ᴰ���ָ࣬��������������봰�ڻص�����
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	//�����ڵ���Ϣ���У�����Ǹ���ַ
	wcex.lpfnWndProc = WindowProc;
	//����������
	wcex.lpszClassName = szWindowClass;

	//ע�����������
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("ע�ᴰ����ʧ��"), _T("Tip"), NULL);
		return 1;
	}

	//�ڶ������������ڣ�ָ��ע�ᴰ���࣬���ڱ��⣬���ڵĴ�С
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
		MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("Tip"), NULL);
		return 1;
	}

	/////��������Դ����Ӵ��ڻ��߿ؼ� ��һ�ַ���/////

	//����������ʾ���� ���ھ�� ��ʾ״̬
	ShowWindow(hWnd, nCmdShow);

	//���Ĳ�����ʼ��Ϣѭ��
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//��Ϣ��ת��
		TranslateMessage(&msg);
		//��Ϣ�ַ�
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}