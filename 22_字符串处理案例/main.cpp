#include <string.h>
#include <stdio.h>
/*

    计算 str2子串 在 str1 出现的个数

*/

int calculate_str(char *str1, char *str2)
{
    int n = 0;
    char *s1 = str1;
    char *t = NULL;
    while(true)
    {
        t = strstr(s1, str2);
        if(t == NULL)
            break;
        else
        {
            n++;
            s1 = t+strlen(str2);  // 注意右边表达式
            t = NULL;
        }
    }

    return n;

}

int main(void)
{
    char str1[] = "heallohedadlloas1hellohelloadh21hello2elloh3ehellollohellohel2ohell1ohe23llohaellhello123ohadello";
    char str2[] = "hello";
    int number = calculate_str(str1, str2);
    printf("calc ret: %d\n", number);

    return 0;
}