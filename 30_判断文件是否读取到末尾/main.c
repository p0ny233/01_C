#include <stdio.h>

// 直接使用EOF(-1)来判断是否读取到文件末尾是错误的，假如写入 -1，fgetc读取到-1就直接结束了
void read_err(FILE* fp)
{
    char ch;
    while((ch = fgetc(fp)) != EOF)
        printf("0x%x ", ch);

    printf("\nread_err end 0x%x , eof value: %d\n", ch, feof(fp));
    // read_err end 0xffffffff , eof value: 0

}

// 使用 feof来检测是否读取到文件末尾，而不是只单纯判断读取的文件内容
void read_success(FILE* fp)
{
    char ch;
    while(ch = fgetc(fp))
    {
        if(feof(fp) != 0)
            break;
        printf("0x%x ", ch);

    }
    printf("\nread_success end 0x%x , eof value: %d\n", ch, feof(fp));

}

int main(void)
{
    FILE* fp = fopen("./b.txt", "w+");
    if(fp == NULL)
    {
        perror("fopen:");
        return -1;
    }

    printf("fopen: success\n");

    fputc('a', fp);
    fputc(-1, fp);
    fputc(-2, fp);
    fputc(-3, fp);
    fflush(fp);
    rewind(fp);

    //read_err(fp);
    read_success(fp);

    if(fp)
        fclose(fp);
    return 0;
}