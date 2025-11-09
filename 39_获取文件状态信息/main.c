#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
    struct stat buf;
    int ret = stat("39_获取文件状态信息.vcxproj", &buf);  // 成功返回0，否则返回 -1
    if(ret)
    {
        perror("stat:");
        return ret;
    }
    printf("buf.st_size: %d\n", buf.st_size);
    return 0;
}
