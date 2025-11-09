/*
    由于是以文本模式打开文件，因此仅适用于 txt文本文件的拷贝
*/
#include <stdio.h>

int copy_file(FILE* fp1, FILE* fp2)
{
    char c;
    int ret = 0;
    if(fp1 && fp2)
    {
    
        while(1)
        {
            c = fgetc(fp1);
            if (feof(fp1))
                break;
            fputc(c, fp2);
        }
    }
    else
    {
        ret = -1;
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
    char *src_file = argv[1];
    char *dst_file = argv[2];

    FILE* src_fp = fopen(src_file,"r");
    FILE* dst_fp = fopen(dst_file,"w");
    int ret = copy_file(src_fp, dst_fp);
    if(!ret)
        printf("copy file success\n");

    if(src_fp)
        fclose(src_fp);

    if(dst_fp)
        fclose(dst_fp);
    return 0;
}
