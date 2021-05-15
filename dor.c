#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "dor.h"

int FileExists(const char* fname)
{
    if (access(fname, F_OK) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ShowDocument(const char* fname)
{
    if (FileExists(fname))
    {
        const char* ext = ".dor";
        const char* docfile;
        strcat(docfile, fname);
        strcat(docfile, ext);
        if (FileExists(docfile))
        {
            FILE *fptr;
            fptr = fopen(docfile, "r");
            char* c = fgetc(fptr);
            while (c != EOF)
            {
                printf("%c", c);
                c = fgetc(fptr);
            }
            printf("\n");
            fclose(fptr);
        }
        else
        {
            printf("Documentation not exists for '%s'.\n", fname);
        }
    }
    else
    {
        printf("File or directory '%s' not exists.\n", fname);
    }
}

