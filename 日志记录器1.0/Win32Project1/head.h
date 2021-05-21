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


//双链表
typedef struct ListNode1
{
	CString date;
	CString time;
	struct ListNode1* next;
	struct ListNode1* prev;
}MyListNode, *LPMyListNode;


//创建节点
LPMyListNode createNode(CString data, CString time);
//初始化
LPMyListNode ListInit();
//头插
void pushFornta(LPMyListNode pHead, CString data, CString time);
//尾删
void popFornta(LPMyListNode pHead);