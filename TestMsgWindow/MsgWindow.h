/********************************************************************
	created:	2014/01/08   11:28
	filename: 	MsgWindow.h
	file ext:	h
	author:		JackyFu
	WebSite:    http://www.fusijie.com
	blog:		http://blog.csdn.net/jackystudio
	QQ:			754505629
	E-mail:		Geek.Jacky@Gmail.com
	
	purpose:	��QQ�������½ǵ�������ΪMFC�棬��ֲ��Win32�档ԭ����http://blog.csdn.net/cometnet/article/details/7854345
*********************************************************************/
#pragma once

// CMsgWindow

#define WM_CONTROLCLICK WM_APP+106

class CMsgWindow : public CWnd
{
	DECLARE_DYNAMIC(CMsgWindow)

public:
	CMsgWindow();
	virtual ~CMsgWindow();

	// ��������
	BOOL Create(HWND hWndParent,LPCTSTR lpWindowName,int nWidth=250,int nHeight=180);

	// ��ʾ����
	void Show();

	// ����Ƥ��(λͼ��Դ����,�������ı���ɫ)
	BOOL SetSkin(LPCTSTR lpBitmapName,COLORREF CaptionColor=0x000000);

	// �������ű��⡢���ݡ�����
	BOOL SetMsg(LPCTSTR lpNewsTitle,LPCTSTR lpNewsContent,LPCTSTR lpNewsURL="");

	// �����Զ��ر�,���Ϊ��,������Ӻ󴰿��Զ��ر�
	void SetAutoClose(BOOL bAutoClose);

private:
	#define NCT_CLOSE	0
	#define NCT_VIEW	1
	#define NCT_TITLE	2
	#define NCT_CONTENT	3

	typedef struct tagNEWSCONTROL
	{
		CString		strText;
		int			nType;
		int			x;
		int			y;
		int			nWidth;
		int			nHeight;
		RECT		Rect;
	}NEWSCONTROL, *LPNEWSCONTROL;
	LPNEWSCONTROL m_pControls;
	int m_nControlCount;

	HCURSOR m_hArrowCursor;
	HCURSOR m_hHandCursor;
	HCURSOR m_hCurCursor;

	HICON m_hAppSmallIcon;

	HDC m_hSkinDC;
	HDC m_hCacheDC;
	HBITMAP m_hSkinBitmap;
	HBITMAP m_hSkinOldBitmap;
	HBITMAP m_hCacheBitmap;	
	HBITMAP m_hCacheOldBitmap;
	HFONT m_hFont;
	HFONT m_hBoldFont;
	COLORREF m_CaptionColor;
	int m_nHoverIndex;
	int m_nDownIndex;
	BOOL m_bAutoClose;
	BOOL m_bTracking;
	CString m_strURL;

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnControlClick(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual void PostNcDestroy();

private:
	void CreateControl(LPNEWSCONTROL pControl,int nType,int x,int y,int nWidth,int nHeight,CString strText="");
	BOOL DrawWindowEx();
	BOOL DrawWindow();
	void DrawButton(HDC hDC,LPNEWSCONTROL pControl);
	void DrawStatic(HDC hDC,LPNEWSCONTROL pControl);
	void DrawNineRect(HDC hdcDest,RECT DestRect,RECT SrcRect,RECT NineRect,UINT crTransparent=0xFF00FF);
	RECT CreateRect(LONG left,LONG top,LONG right,LONG bottom);
	BOOL IsWindow();
	int ControlFromPoint(LPARAM lParam);
	int ControlFromPoint(POINT pt);
	void SetCursor(HCURSOR hCursor);
};


