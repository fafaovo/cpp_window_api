#include <windows.h>
#include <tchar.h>
#include <commctrl.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("tip");

//ȫ��������ť�Ŀؼ�ID
UINT IDC_BUTTON_1 = 201;
UINT IDC_BUTTON_2 = 202;
UINT IDC_BUTTON_3 = 203;
UINT IDC_BUTTON_4 = 204;
UINT IDC_EDIT_1 = 301;
UINT IDC_LIST_1 = 401;
//������Ϊ��̬�����ں���ִ�����Żᱻ����
static int index = 1;
UINT line = 0;  //��
UINT column = 0;  //��
HWND EDIT = NULL;
HWND hListCtrl = NULL;

/*HDN_ITEMCLICK �����ͷ NM_CLICK �������  NM_CLICK������WM_NOTIFY*/

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
			HWND hButton3 = CreateWindow(WC_BUTTON, _T("������Ϣ"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 0, 60, 80, 40, hWnd, (HMENU)IDC_BUTTON_3, NULL, NULL);
			HWND hButton4 = CreateWindow(WC_BUTTON, _T("ɾ����Ϣ"), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 80, 60, 80, 40, hWnd, (HMENU)IDC_BUTTON_4, NULL, NULL);

			EDIT = CreateWindow(WC_EDIT, _T("���Ǳ༭��"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 160, 20, 200, 200, hWnd, (HMENU)IDC_EDIT_1, NULL, NULL);

			//LVS_REPORT ������ʽ  LVS_SHOWSELALWAYS һֱ��ʾѡ�� 

			hListCtrl = CreateWindow(WC_LISTVIEW, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 360, 20, 400, 200, hWnd, (HMENU)IDC_LIST_1, NULL, NULL);
			//LVS_EX_FULLROWSELECT��������ѡ��  LVS_EX_GRIDLINES �����ʽ LVS_EX_CHECKBOXES ��ѡ��
			ListView_SetExtendedListViewStyle(hListCtrl, LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);


			/*������ؼ������� Ҫ�����о���Ҫ��������Ϣ
			����� ����Ϣ ��һ�У�
			*/
			LVCOLUMN colInfo = { 0 };
			//��Ч�ĳ�Ա ��� �ı�
			colInfo.mask |= LVCF_WIDTH | LVCF_TEXT | LVCF_FMT;
			colInfo.cx = 100;
			colInfo.pszText = _T("��0��");
			colInfo.fmt = LVCFMT_LEFT;
			/*SendMessage(hListCtrl, LVM_INSERTCOLUMN, 0,(LPARAM)&colInfo);*/

			//΢���װ�ĺ�
			ListView_InsertColumn(hListCtrl, 0, &colInfo);

			LVCOLUMN colInfo_2 = { 0 };
			//��Ч�ĳ�Ա ��� �ı�
			colInfo_2.mask |= LVCF_WIDTH | LVCF_TEXT;
			colInfo_2.cx = 100;
			colInfo_2.pszText = _T("��1��");
			SendMessage(hListCtrl, LVM_INSERTCOLUMN, 1, (LPARAM)&colInfo_2);
			colInfo_2.pszText = _T("��2��");
			SendMessage(hListCtrl, LVM_INSERTCOLUMN, 2, (LPARAM)&colInfo_2);
			colInfo_2.pszText = _T("��3��");
			SendMessage(hListCtrl, LVM_INSERTCOLUMN, 3, (LPARAM)&colInfo_2);


			//��������ø����� ��� �� �� ���õ�����
			
			/*ListView_SetItemText(hListCtrl, 1, 1, _T("�ڶ���"));*/
			//listview_getitemcount
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
				//BN_CLICKED��ť������ʱ
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
						//��ȡ����е����� ���ھ�� �ؼ�ID ������ ��������С
						//GetDlgItemText(hWnd, IDC_EDIT_1, mytext, 256);
						//���Ҳ�ܻ�ȡ��
						GetWindowText(EDIT, mytext, 256);

						//��ȡ�б��ж�����
						int countrow = ListView_GetItemCount(hListCtrl);
						//�Ȳ����е���Ϣ
						LV_ITEM row_item = { 0 };
						row_item.mask |= LVIF_TEXT;
						row_item.pszText = mytext;
						row_item.iItem = countrow;
						int column = ListView_InsertItem(hListCtrl, &row_item);

						//�������е���
						ListView_SetItemText(hListCtrl, column, 1, mytext);
						ListView_SetItemText(hListCtrl, column, 2, mytext);
						ListView_SetItemText(hListCtrl, column, 3, mytext);
						//MessageBox(NULL, mytext, _T("tip"), MB_OK);
					}
					if (nCtrIID == IDC_BUTTON_3)
					{
						ListView_SetItemText(hListCtrl, line, column, _T("��һ��"));
						column++;
						if (column == 4)
						{
							line = 0;
							line++;
							
						}			
					}
					if (nCtrIID == IDC_BUTTON_4)
					{
						//ɾ�����һ��
						int countrow = ListView_GetItemCount(hListCtrl);
						ListView_DeleteItem(hListCtrl, countrow-1);
						//ɾ����һ��
						//ListView_DeleteItem(hListCtrl, 0);
					}
						

				}
		}
		break;
	case WM_NOTIFY:
		//��������Ϣ
	{
		NMHDR* pNmHdr = (NMHDR*)lParam;
		if (pNmHdr->idFrom == IDC_LIST_1)
			//�жϿؼ�ID
		{
			if (pNmHdr->code == NM_CLICK)
				//�ж�Ϊ����¼�
			{
				LPNMLISTVIEW ipnmitem = (LPNMLISTVIEW)lParam;

				TCHAR szText[128] = { 0 };
				_stprintf(szText,_T("������� %d ��, %d ��"), ipnmitem->iItem, ipnmitem->iSubItem);
				MessageBox(NULL, szText, _T("tip"), MB_OK);
			}
			
		}
		if (pNmHdr->code == HDN_ENDTRACK)
			//������ק����ʱ			
		{
			HWND hListHeader = ListView_GetHeader(hListCtrl);
			if (hListHeader == pNmHdr->hwndFrom)
				//�ж�����������һ����̬����
			{
				LPNMLISTVIEW ipnmitem = (LPNMLISTVIEW)lParam;
				//��ȡ�еĿ��
				int width = ListView_GetColumnWidth(hListCtrl, ipnmitem->iItem);

				TCHAR szText[128] = { 0 };
				_stprintf(szText, _T("�� %d �еĿ���� %d "), ipnmitem->iItem, width);
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