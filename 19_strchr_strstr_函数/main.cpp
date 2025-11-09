#include <stdio.h>
#include <string.h>
/*
    在s1中查找s2字符串 出现的位置，如果找到则返回其对应的地址，否则返回NULL
*/
char *my_strstr(char* s1, char* s2)
{
    int i = 0;
    bool cmp_ret = false;
    while(*(s1 + i) != '\0')
    {
        cmp_ret = false;
        if(*(s1 + i) == *s2)  // 当第一个字符相等时
        {
            int i2 = 0;
            while(*(s2 + i2) != '\0')
            {
                if(*(s1 + i + i2) - *(s2 + i2))
                {
                    cmp_ret = true;
                    break;
                }
                i2++;
            }
            if((*(s2 + i2) == '\0') && !cmp_ret)
            {
                return s1 + i;
            }
        }
        i++;
    }
    return NULL;
}


/*
    在s 字符数组中查找字符ch出现的位置，如果找到则返回其对应的地址，否则返回NULL
*/
char *my_strchr(char* s, char ch)
{
    char *ret;
    int i = 0;
    while(*(s + i) != '\0')
    {
        if(*(s + i) == ch)
        {
            return s + i;
        }
        i++;
    }
    return NULL;
}

/***********************************************************************************************/

int main(void)
{
    char s1[] = "hellworldaabcbcqqqleo";
    char s2[] = "abc";
    // 模拟库函数
    char * ptr = my_strstr(s1, s2);
    char * p1 = my_strchr(s1, 'q');
    printf("0x%x, %s\n", ptr, ptr);
    printf("0x%x, %s\n", p1, p1);
    putchar('\n');
    // 调用库函数
    ptr = strstr(s1, s2);
    p1 = strchr(s1, 'q');
    printf("0x%x, %s\n", ptr, ptr);
    printf("0x%x, %s\n", p1, p1);
    return 0;
}

/*
0xa80ffb92, abcbcqqqleo
0xa80ffb97, qqqleo

0xa80ffb92, abcbcqqqleo
0xa80ffb97, qqqleo

D:\cpp_code\bxg\01_C\x64\Debug\19_strchr_strstr_函数.exe (进程 9280)已退出，代码为 0。
*/