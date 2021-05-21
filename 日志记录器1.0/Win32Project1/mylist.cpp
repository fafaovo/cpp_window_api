#include "head.h"




//�����ڵ�
LPMyListNode createNode(CString data, CString time)
{
	LPMyListNode newNode = new MyListNode;
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->date = data;
	newNode->time = time;
	return newNode;
}
//��ʼ��
LPMyListNode ListInit()
{
	LPMyListNode pHead = createNode(_T(""), _T(""));
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}


//ͷ��
void pushFornta(LPMyListNode pHead, CString data, CString  time)
{
	LPMyListNode newNode = createNode(data, time);
	newNode->next = pHead;
	newNode->prev = pHead->prev;
	pHead->prev->next = newNode;
	pHead->prev = newNode;
	pHead = newNode;
}

//βɾ
void popFornta(LPMyListNode pHead)
{
	if (pHead->next == pHead)
	{
		return;
	}
	LPMyListNode cur = pHead->prev;
	LPMyListNode curprev = cur->prev;
	curprev->next = pHead;
	pHead->prev = curprev;
	free(cur);
}

