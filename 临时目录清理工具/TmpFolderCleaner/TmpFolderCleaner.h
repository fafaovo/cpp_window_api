
// TmpFolderCleaner.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTmpFolderCleanerApp: 
// �йش����ʵ�֣������ TmpFolderCleaner.cpp
//

class CTmpFolderCleanerApp : public CWinApp
{
public:
	CTmpFolderCleanerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTmpFolderCleanerApp theApp;