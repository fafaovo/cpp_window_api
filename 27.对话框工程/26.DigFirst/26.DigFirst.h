
// 26.DigFirst.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy26DigFirstApp: 
// �йش����ʵ�֣������ 26.DigFirst.cpp
//

class CMy26DigFirstApp : public CWinApp
{
public:
	CMy26DigFirstApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CMy26DigFirstApp theApp;