#include <iostream>
using namespace std;
#include <tchar.h>
#include <Windows.h>
#include "atlbase.h"
#include "atlstr.h"
#include <string>

//窄字节 char* p;
//Unicode宽字节 wchar_t *p;
//通用类型 TCHAR *p;

//WideCharToMultiByte 宽字节转换成窄字节
//MultiByteToWideChar 窄字节转换成宽字节
/*
MultiByteToWideChar
代码页:针对窄字节 CP_ACP默认本地语言的代码页
默认值:0
窄字节
窄字节的字符串长度:如果写-1这个函数按照字符串处理


*/

//窄转换成宽
wchar_t* cctry_a2w(char* p_a)
{
	//第一遍执行用于返回需要的宽字节的空间大小
	int need_w_char = MultiByteToWideChar(CP_ACP, 0, p_a, -1, NULL, 0);
	if (need_w_char <= 0) return NULL;
	
	wchar_t* p_w = new wchar_t[need_w_char];
	wmemset(p_w, 0, need_w_char);

	MultiByteToWideChar(CP_ACP, 0, p_a, -1, p_w, need_w_char);
	return p_w;
}
//宽转换成窄
char* cctry_w2a(wchar_t* p_w)
{
	//第一遍执行用于返回需要的宽字节的空间大小
	int need_w_char = WideCharToMultiByte(CP_ACP, 0, p_w, -1, NULL, 0,NULL,NULL);
	if (need_w_char <= 0) return NULL;

	char* p_a = new char[need_w_char];
	WideCharToMultiByte(CP_ACP, 0, p_w, -1, p_a, need_w_char, NULL, NULL);

	return p_a;
}


int main1(int argc, char* argv[])
{
	char* p_a = "12345转换开始";

	//窄转换成宽
	wchar_t* p_www = cctry_a2w(p_a);

	char* p_aaa = cctry_w2a(p_www);

	delete[] p_www;
	delete[] p_aaa;
	
	//ATL也有提供宏CA2W CW2A CT2W CT2A
	//窄->宽
	CA2W a2wObj(p_a);
	wchar_t* p_wwww = (wchar_t*)a2wObj;
	//宽->窄
	CW2A w2aObj(p_wwww);
	char* p_aaaa = (char*)w2aObj;

	//通用类型
	CT2A t2aObj(p_wwww);
	char* p_aaaaa = (char*)t2aObj;

	//char* 转换成string 
	string s_a = p_aaaaa;
	//string转换成char*
	char c[20];
	strcpy_s(c, 20,s_a.c_str());

	return 0;
}
