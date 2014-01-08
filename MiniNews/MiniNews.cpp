// MiniNews.cpp : ����Ӧ�ó������ڵ㡣
// Download by http://www.codefans.net

#include "stdafx.h"
#include "MiniNews.h"
#include "NewsWindow.h"

CNewsWindow NewsWindow;
BOOL InitNews();

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine,int nCmdShow)
{

	if(!InitNews())
		return 0;


	// ����Ϣѭ��:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}
BOOL InitNews()
{
	LPCTSTR lpNewsTitle		= _T("�������ű���");
	LPCTSTR lpNewsContent	= _T("������������,���ǿƼ���չ���޹�˾(��������)���Ŷ�����վ����������������飬���о���ḻ�Ŀ����Ŷӡ�Ϊ���ṩרҵ����վ���衢��������ȷ���");
	LPCTSTR lpNewsURL		= _T("");

	NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_QQ));
	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_WANGWANG));
	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_XUNLEI),0xFFFFFF);
	if(!NewsWindow.Create(_T("������������")))
		return FALSE;

	NewsWindow.SetNews(lpNewsTitle,lpNewsContent,lpNewsURL);
	NewsWindow.Show();
	NewsWindow.SetMainWindow();
	return TRUE;
}