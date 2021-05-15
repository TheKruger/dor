#include <stdio.h>
#include "dor.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: dor <file or directory>\n");
    }
    else
    {
        const char* fname = argv[1];
        ShowDocument(fname);
    }
    return 0;
}