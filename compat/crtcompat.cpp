#include <windows.h>
#include <sal.h>

extern "C"
int __cdecl _CrtDbgReportW(
    _In_ int _ReportType,
    _In_opt_z_ const wchar_t * _Filename,
    _In_ int _LineNumber,
    _In_opt_z_ const wchar_t * _ModuleName,
    _In_opt_z_ const wchar_t * _Format,
    ...)
{
    return 0;
}
