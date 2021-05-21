#include <iostream>
using namespace std;
#include <tchar.h>
#include <Windows.h>
#include "atlbase.h"
#include "atlstr.h"
#include <string>

//խ�ֽ� char* p;
//Unicode���ֽ� wchar_t *p;
//ͨ������ TCHAR *p;

//WideCharToMultiByte ���ֽ�ת����խ�ֽ�
//MultiByteToWideChar խ�ֽ�ת���ɿ��ֽ�
/*
MultiByteToWideChar
����ҳ:���խ�ֽ� CP_ACPĬ�ϱ������ԵĴ���ҳ
Ĭ��ֵ:0
խ�ֽ�
խ�ֽڵ��ַ�������:���д-1������������ַ�������


*/

//խת���ɿ�
wchar_t* cctry_a2w(char* p_a)
{
	//��һ��ִ�����ڷ�����Ҫ�Ŀ��ֽڵĿռ��С
	int need_w_char = MultiByteToWideChar(CP_ACP, 0, p_a, -1, NULL, 0);
	if (need_w_char <= 0) return NULL;
	
	wchar_t* p_w = new wchar_t[need_w_char];
	wmemset(p_w, 0, need_w_char);

	MultiByteToWideChar(CP_ACP, 0, p_a, -1, p_w, need_w_char);
	return p_w;
}
//��ת����խ
char* cctry_w2a(wchar_t* p_w)
{
	//��һ��ִ�����ڷ�����Ҫ�Ŀ��ֽڵĿռ��С
	int need_w_char = WideCharToMultiByte(CP_ACP, 0, p_w, -1, NULL, 0,NULL,NULL);
	if (need_w_char <= 0) return NULL;

	char* p_a = new char[need_w_char];
	WideCharToMultiByte(CP_ACP, 0, p_w, -1, p_a, need_w_char, NULL, NULL);

	return p_a;
}


int main1(int argc, char* argv[])
{
	char* p_a = "12345ת����ʼ";

	//խת���ɿ�
	wchar_t* p_www = cctry_a2w(p_a);

	char* p_aaa = cctry_w2a(p_www);

	delete[] p_www;
	delete[] p_aaa;
	
	//ATLҲ���ṩ��CA2W CW2A CT2W CT2A
	//խ->��
	CA2W a2wObj(p_a);
	wchar_t* p_wwww = (wchar_t*)a2wObj;
	//��->խ
	CW2A w2aObj(p_wwww);
	char* p_aaaa = (char*)w2aObj;

	//ͨ������
	CT2A t2aObj(p_wwww);
	char* p_aaaaa = (char*)t2aObj;

	//char* ת����string 
	string s_a = p_aaaaa;
	//stringת����char*
	char c[20];
	strcpy_s(c, 20,s_a.c_str());

	return 0;
}
