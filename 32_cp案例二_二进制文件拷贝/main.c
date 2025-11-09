/*
    以二进制模式打开文件
*/
#include <stdio.h>

int copy_file_with_bin(FILE *fp1, FILE *fp2)
{
    int ret = 0;
    char c;
    while(1)
    {
        c = fgetc(fp1);
        if (feof(fp1))
            break;
        fputc(c, fp2);
    }
    return ret;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("%s src_file dst_file", argv[0]);
        return -1;
    }

    FILE *src_fp = fopen(argv[1], "rb");
    FILE *dst_fp = fopen(argv[2], "wb");
    int ret = copy_file_with_bin(src_fp, dst_fp);
    if(ret != 0)
    {
        perror("copy:");
        return -1;
    }
    
    printf("copy file success\n");
    return 0;
}