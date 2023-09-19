#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <tchar.h>
#include <stdio.h>

#include <atlbase.h>
#include <atlsimpcoll.h>    // for CSimpleArray

#include "resource.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

class CMyExeModule : public ATL::CAtlExeModuleT<CMyExeModule>
{
};
CMyExeModule g_my_exe;

//////////////////////////////////////////////////////////////////////////////////////////////////

void print_array(const CSimpleArray<INT>& array)
{
    printf("# = %d\n", array.GetSize());

    for (INT i = 0; i < array.GetSize(); ++i)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

extern "C"
int main(int argc, char **argv)
{
    CSimpleArray<INT> array;
    array.Add(3);
    array.Add(4);
    array.Add(5);
    print_array(array);
    return 0;
}
