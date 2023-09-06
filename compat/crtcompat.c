#include <windows.h>

int __cdecl __imp__CrtDbgReport(int reportType, const char *filename, int linenumber, const char *moduleName, const char *format, ...)
{
    return 0;
}

int __cdecl __imp__CrtDbgReportW(int reportType, const wchar_t *filename, int linenumber, const wchar_t *moduleName, const wchar_t *format, ...)
{
    return 0;
}
