#pragma once
#include <windows.h>
#include <tchar.h>
#include <CommCtrl.h>
#include <time.h>
#include <iostream>
using namespace std;
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1
#include "atlbase.h"
#include "atlstr.h"


//˫����
typedef struct ListNode1
{
	CString date;
	CString time;
	struct ListNode1* next;
	struct ListNode1* prev;
}MyListNode, *LPMyListNode;


//�����ڵ�
LPMyListNode createNode(CString data, CString time);
//��ʼ��
LPMyListNode ListInit();
//ͷ��
void pushFornta(LPMyListNode pHead, CString data, CString time);
//βɾ
void popFornta(LPMyListNode pHead);