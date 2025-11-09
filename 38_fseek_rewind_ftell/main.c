#include <stdio.h>

#define FILE_NAME "./38_fseek_rewind_ftell.txt"
void test_fseek_rewind_ftell()
{
    char buf[] = "helloworld666777888";
    FILE *fp = fopen(FILE_NAME, "wb");
    if(!fp)
    {
        perror("fopen:");
        return -1;
    }
    fputs(buf, fp);
    
    long byte = ftell(fp);
    printf("初始位置：%ld\n", byte);

    // 此时文件指针在文件末尾
    // 移动文件指针到 666 之前
    fseek(fp, -9, SEEK_CUR);  // 由于当前文件指针在文件末尾，因此从末尾向前移动 9个字节
    fputs("222", fp);  // 将 666 修改为 222
    fflush(fp);
    
    // 使用rewind将文件指针重置到文件开头
    rewind(fp);

    // 使用 SEEK_END 移动文件指针到 222 之前
    fseek(fp, -9 ,SEEK_END);
    fputs("and", fp);  // 将 222 修改为 and
    fflush(fp);

    // 使用 SEEK_SET 移动文件指针到 222 之前
    fseek(fp, 10, SEEK_SET);
    fputs("999", fp);  // 将 and 修改为 999
    fflush(fp);

    // 增大文件尺寸
    fseek(fp, 63, SEEK_END);  // 先将文件指针到末尾
    fputc('\0', fp);  // 64 个字节数，值都为 0x0
    
    if(fp)
    {
        fflush(fp);
        fclose(fp);
    }
}
int main(void)
{

    test_fseek_rewind_ftell();

    return 0;
}
