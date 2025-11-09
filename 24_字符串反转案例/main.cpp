#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char string[] = "abcdefghij";
    char *start = string;
    char *end = string + strlen(string) - 1;
    while(end - start > 0)
    {
        *start = *start ^ *end;
        *end = *start ^ *end;
        *start = *start ^ *end;
        start++;
        end--;

    }

    printf("[%s]\n", string);
    return 0;
}
/*
[jihgfedcba]
*/