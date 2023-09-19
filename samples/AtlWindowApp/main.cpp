#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

class CMyExeModule : public ATL::CAtlExeModuleT<CMyExeModule>
{
};
CMyExeModule g_my_exe;

//////////////////////////////////////////////////////////////////////////////////////////////////

class CMainWindow : public CWindowImpl<CMainWindow, CWindow, CFrameWinTraits>
{
public:
    DECLARE_WND_CLASS_EX(TEXT("AtlWindowApp"), CS_HREDRAW | CS_VREDRAW, COLOR_3DFACE)

    CMainWindow();
    virtual ~CMainWindow();

    HWND Create(HWND hwndParent = NULL)
    {
        RECT r = { 50, 50, 600, 400 };
        DWORD style = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
        DWORD exstyle = WS_EX_WINDOWEDGE;
        return CWindowImpl::Create(hwndParent, r, TEXT("AtlWindowApp"), style, exstyle);
    }

    BEGIN_MSG_MAP(CMainWindow)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
    END_MSG_MAP()

    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        return 0;
    }

    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        ::PostQuitMessage(0);
        return 0;
    }

    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        return 0;
    }

    LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        PAINTSTRUCT ps;
        if (HDC hDC = BeginPaint(&ps))
        {
            RECT rc;
            GetClientRect(&rc);

            ::MoveToEx(hDC, rc.left, rc.top, NULL);
            ::LineTo(hDC, rc.right, rc.bottom);

            ::MoveToEx(hDC, rc.right, rc.top, NULL);
            ::LineTo(hDC, rc.left, rc.bottom);

            UINT uFormat = DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOPREFIX;
            ::DrawText(hDC, TEXT("Hello, RATL"), -1, &rc, uFormat);

            EndPaint(&ps);
        }
        return 0;
    }
};

CMainWindow::CMainWindow()
{
}

CMainWindow::~CMainWindow()
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    InitCommonControls();

    CMainWindow mainWnd;
    HWND hMainWnd = mainWnd.Create();
    if (!hMainWnd)
        return 1;

    mainWnd.ShowWindow(nCmdShow);
    mainWnd.UpdateWindow();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (INT)msg.wParam;
}
