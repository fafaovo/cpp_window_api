
// DriveThief.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDriveThiefApp: 
// �йش����ʵ�֣������ DriveThief.cpp
//

class CDriveThiefApp : public CWinApp
{
public:
	CDriveThiefApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDriveThiefApp theApp;