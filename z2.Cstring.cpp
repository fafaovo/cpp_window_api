#include <iostream>
using namespace std;
#include <tchar.h>
#include <Windows.h>
#include "atlbase.h"
#include "atlstr.h"

/*
CString操作
trim 去除空格
reverse 进行首尾颠倒
upper 全部大写
lower 全部小写
right 返回字符串中结尾的指定字符
span_including 返回包含指定字符串中任意一个字符的子串
span_excluding 返回不包含指定字符串中任意一个字符的子串
format 格式化字符串
replace 替换字符串的指定字符
stricmp 不区分大小写进行比较
*/


int main(int argc, char* argv[])
{
	TCHAR * a = _T("裂开了");
	CString str = _T("123456");
	str = a;
	str += _T("666");
	CString right = str.Right(2);
	CString sub = str.SpanIncluding(_T("6"));

	str.Format(_T("hello %s%d"), _T("你好世界"), 123);
	return 0;
}