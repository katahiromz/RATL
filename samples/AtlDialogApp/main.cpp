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

class CMainWindow : public CDialogImpl<CMainWindow, CWindow>
{
public:
    enum { IDD = IDD_MAIN };
    CMainWindow();
    virtual ~CMainWindow();

    VOID ResetSettings();
    BOOL LoadSettings();
    BOOL SaveSettings();

    BEGIN_MSG_MAP(CMainWindow)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        MESSAGE_HANDLER(WM_COMMAND, OnCommand)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAINICON));
        HICON hIconSm = (HICON)LoadImage(
            GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAINICON), IMAGE_ICON,
            GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), 0);
        SendMessage(WM_SETICON, ICON_BIG, (LPARAM)hIcon);
        SendMessage(WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);
        return 0;
    }

    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        return 0;
    }

    BOOL OnOK()
    {
        // TODO: Do something
        return TRUE;
    }

    LRESULT OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
    {
        switch (LOWORD(wParam))
        {
        case IDOK:
            if (OnOK())
            {
                EndDialog(IDOK);
            }
            break;
        case IDCANCEL:
            EndDialog(IDCANCEL);
            break;
        }
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
    // TODO: Reset settings
}

BOOL CMainWindow::LoadSettings()
{
    ResetSettings();

    CRegKey appKey;
    LONG error;

    error = appKey.Open(HKEY_CURRENT_USER, TEXT("Software\\ReactOS\\AtlDialogApp"));
    if (error)
        return FALSE;

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

    error = appKey.Create(companyKey, TEXT("AtlDialogApp"));
    if (error)
        return FALSE;

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

    if (mainWnd.DoModal(NULL, 0) == IDOK)
    {
        // TODO: Do something
    }

    mainWnd.SaveSettings();

    return 0;
}
