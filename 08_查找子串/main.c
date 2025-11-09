#include <stdio.h>
#include <stdbool.h>

int my_strstr(char* src, char* ts)
{
    char *begin = src;
    int pos = -1;
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    while(*src != '\0')
    {
        if(*src == *ts)
        {
            ptr1 = src;
            ptr2 = ts;
            while(*++ptr1 == *++ptr2); // 目的是让 指向子字符串的指针往后移动，如果指向 结束符 意味着子串所有字符全部进行了匹配
            if(*ptr2 == '\0')
            {
                pos = ptr1 - begin - strlen(ts);
                break;
            }
        }
        src++;
    }
    return pos;
}

int main(void)
{
    char str1[] = "abcasdasddncdnd1fasdasccdgrgrg123";
    char str2[] = "abcasdasddncdndnfasdasccdgrgrg123";
    char ts[] = "dnf";
    int pos1 = my_strstr(str1, ts);
    int pos2 = my_strstr(str2, ts);

    printf("pos1: %d\n", pos1);
    printf("pos2: %d\n", pos2);

    return 0;
}