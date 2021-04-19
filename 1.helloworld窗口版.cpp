#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>


/*winMain相当于main*/
/*参数(当前程序的实例句柄,上一个程序的实例句柄,命令行参数)*/
/*需求修改字符集改为多字节
左转字符串宽窄函数前两节
*/
/*
int WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, char* ipCmdLine, int nshowCmd)
{
//提示框函数:MessageBox(窗口句柄,字符串, 标题，提示框的按钮 | 图标)
MessageBox(NULL, _T("HwqelloWorld"), _T("我是标题"), MB_YESNO | MB_ICONASTERISK);
return 0;
}
*/