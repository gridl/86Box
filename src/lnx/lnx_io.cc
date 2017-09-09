#include <stdio.h>
#include <unistd.h>
#include "lnx_io.h"

FILE* _wfopen(const wchar_t *fn, const wchar_t *mode)
{
        return fopen((const char*)fn, (const char*)mode);
}

int _wremove(const wchar_t* path)
{
        return remove((const char*)path);
}

int _wchdir(const wchar_t* path)
{
        return chdir((const char*) path);
}
