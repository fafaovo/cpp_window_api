#include <iostream>
using namespace std;
#include <tchar.h>
#include <Windows.h>
#include "atlbase.h"
#include "atlstr.h"

/*
CString����
trim ȥ���ո�
reverse ������β�ߵ�
upper ȫ����д
lower ȫ��Сд
right �����ַ����н�β��ָ���ַ�
span_including ���ذ���ָ���ַ���������һ���ַ����Ӵ�
span_excluding ���ز�����ָ���ַ���������һ���ַ����Ӵ�
format ��ʽ���ַ���
replace �滻�ַ�����ָ���ַ�
stricmp �����ִ�Сд���бȽ�
*/


int main(int argc, char* argv[])
{
	TCHAR * a = _T("�ѿ���");
	CString str = _T("123456");
	str = a;
	str += _T("666");
	CString right = str.Right(2);
	CString sub = str.SpanIncluding(_T("6"));

	str.Format(_T("hello %s%d"), _T("�������"), 123);
	return 0;
}