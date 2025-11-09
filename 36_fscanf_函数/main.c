// 以指定的格式从文件中读取数据
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int year;
    int month;
    int day;
    char *file_path = "D:/cpp_code/bxg/01_C/35_fprintf_函数/test_fprintf.txt";
    FILE *fp = fopen(file_path,"r");
    if(!fp)
    {
        perror("fopen:");
        return -1;
    }

    fscanf(fp, "%04d:%02d:%02d", &year, &month, &day);
    
    printf("%04d:%02d:%02d", year, month, day);

    return 0;
}