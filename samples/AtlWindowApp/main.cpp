#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>

#include "resource.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

class CMyExeModule : public ATL::CAtlExeModuleT<CMyExeModule>
{
};
CMyExeModule g_my_exe;

//////////////////////////////////////////////////////////////////////////////////////////////////

class CMainWindow : public CWindowImpl<CMainWindow, CWindow, CFrameWinTraits>
{
protected:
    INT m_x = CW_USEDEFAULT;
    INT m_y = CW_USEDEFAULT;
    INT m_cx = 600;
    INT m_cy = 400;

public:
    static ATL::CWndClassInfo& GetWndClassInfo()
    {
        DWORD style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
        static ATL::CWndClassInfo wc =
        {
            {
                sizeof(WNDCLASSEX), style, StartWindowProc, 0, 0, NULL,
                LoadIcon(_AtlBaseModule.GetModuleInstance(), MAKEINTRESOURCE(IDI_MAINICON)),
                LoadCursor(NULL, IDC_ARROW),
                (HBRUSH)(COLOR_3DFACE + 1),
                NULL, TEXT("AtlWindowApp"), NULL
            },
            NULL, NULL, IDC_ARROW, TRUE, 0, TEXT("")
        };
        return wc;
    }

    CMainWindow();
    virtual ~CMainWindow();

    HWND Create(HWND hwndParent = NULL)
    {
        RECT rc = { m_x, m_y, m_x + m_cx, m_y + m_cy };
        DWORD style = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
        DWORD exstyle = WS_EX_WINDOWEDGE;
        return CWindowImpl::Create(hwndParent, rc, TEXT("AtlWindowApp"), style, exstyle);
    }

    VOID ResetSettings();
    BOOL LoadSettings();
    BOOL SaveSettings();

    BEGIN_MSG_MAP(CMainWindow)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_MOVE, OnMove)
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

    LRESULT OnMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        if (!m_hWnd || IsIconic() || IsZoomed())
            return 0;

        RECT rc;
        GetWindowRect(&rc);
        m_x = rc.left;
        m_y = rc.top;
        return 0;
    }

    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        if (!m_hWnd || IsIconic() || IsZoomed())
            return 0;

        RECT rc;
        GetWindowRect(&rc);
        m_cx = rc.right - rc.left;
        m_cy = rc.bottom - rc.top;
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

VOID CMainWindow::ResetSettings()
{
    m_x = CW_USEDEFAULT;
    m_y = CW_USEDEFAULT;
    m_cx = 600;
    m_cy = 400;
}

BOOL CMainWindow::LoadSettings()
{
    ResetSettings();

    CRegKey appKey;
    LONG error;

    error = appKey.Open(HKEY_CURRENT_USER, TEXT("Software\\ReactOS\\AtlWindowApp"));
    if (error)
        return FALSE;

    DWORD dwValue, cbValue;

    cbValue = sizeof(dwValue);
    error = appKey.QueryValue(TEXT("x"), NULL, &dwValue, &cbValue);
    if (!error)
        m_x = dwValue;

    cbValue = sizeof(dwValue);
    error = appKey.QueryValue(TEXT("y"), NULL, &dwValue, &cbValue);
    if (!error)
        m_y = dwValue;

    cbValue = sizeof(dwValue);
    error = appKey.QueryValue(TEXT("cx"), NULL, &dwValue, &cbValue);
    if (!error)
        m_cx = dwValue;

    cbValue = sizeof(dwValue);
    error = appKey.QueryValue(TEXT("cy"), NULL, &dwValue, &cbValue);
    if (!error)
        m_cy = dwValue;

    // TODO: Load settings

    return TRUE;
}

BOOL CMainWindow::SaveSettings()
{
    CRegKey companyKey, appKey;
    LONG error;

    error = companyKey.Create(HKEY_CURRENT_USER, TEXT("Software\\ReactOS"));
    if (error)
        return FALSE;

    error = appKey.Create(companyKey, TEXT("AtlWindowApp"));
    if (error)
        return FALSE;

    appKey.SetDWORDValue(TEXT("x"), m_x);
    appKey.SetDWORDValue(TEXT("y"), m_y);
    appKey.SetDWORDValue(TEXT("cx"), m_cx);
    appKey.SetDWORDValue(TEXT("cy"), m_cy);

    // TODO: Save settings

    return TRUE;
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
    mainWnd.LoadSettings();

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

    mainWnd.SaveSettings();

    return (INT)msg.wParam;
}
