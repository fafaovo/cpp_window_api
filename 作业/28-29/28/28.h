
// 28.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once


#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy28App: 
// �йش����ʵ�֣������ 28.cpp
//

class CMy28App : public CWinApp
{
public:
	CMy28App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy28App theApp;