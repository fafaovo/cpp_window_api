#include <iostream>
using namespace std;
#include <Windows.h>
#include <tchar.h>

VOID test01()
{
	/*
	�����ļ�ָ��
	setFilePointer(�Ѵ򿪵��ļ����,��32λ��ֵ,��32λλ�Ƶ�ֵ��ָ��,��ʼλ��)
	��32λ��ָ��:����ΪNULL 
	��ʼλ��ȡֵ:FILE_BEGIN ��ͷ FILE_CURRENT �ӵ�ǰ�ļ�ָ�뿪ʼ FILE_END ���ļ�ĩβ��ʼ
	*/

	/*Ŀ¼�Ĵ���
	�������� CreateDirectory(Ŀ¼��·��,null);
	*/
	CreateDirectory(_T("F:\\����\\Ԥ����Ŀ¼"), NULL);

	/*ɾ��Ŀ¼ ֻ��ɾ�����ļ� Ҫɾ���ǿ���SHFileOperation
	RemoveDirectory(ɾ����·��);
	*/
	RemoveDirectory(_T("F:\\����\\Ԥ����Ŀ¼"));
}

int WINAPI _tWinMain1(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR ipCmdLine, int nCmdshow)
{
	test01();
	return 0;
}