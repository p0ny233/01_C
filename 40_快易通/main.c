#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _dict
{
    char *key;      // 生词，为了节省内存，用多少分配多少，避免浪费
    char *content;  // 生词意思
    struct _dict *next;  // 下一个节点
}DICT;
void* __cdecl my_malloc(size_t size)
{
    void* ptr = NULL;

    ptr = malloc(size);
    if(ptr == NULL)
        perror("malloc:");
    return ptr;
}

// 重写malloc
void* (*origin_malloc)(size_t) = malloc;

//malloc = my_malloc;

int dict_init(DICT** dict)
{
    char buf[1024] = {0};
    FILE *fp = fopen("./dict.txt",  "r");
    if(!fp)
    {
        perror("fopen:");
        return -1;
    }
    // 先建立带头结点的单链表
    DICT* LinkList_Node = (DICT*)my_malloc(sizeof(DICT));
    if(LinkList_Node == NULL)
        return -1;
    memset(LinkList_Node, NULL, sizeof(DICT));
    DICT* pre_node = LinkList_Node;

    while(1)
    {
        
        fgets(buf, 1024, fp);
        if (feof(fp))  // feof返回true 到达文件末尾
            break;
        DICT* cur_node = (DICT*)my_malloc(sizeof(DICT));
        if(cur_node == NULL)
            return -1;
        memset(cur_node, NULL, sizeof(DICT));
        char *key = malloc(strlen(buf) + 1);
        if (key == NULL)
            return -1;
        cur_node->key = key;
        buf[strlen(buf) -1] = '\0';
        strcpy(cur_node->key, buf+1);

        memset(buf, 0, sizeof(buf));
        fgets(buf, 1024, fp);
        char* content = malloc(strlen(buf) + 1);
        if(content == NULL)
            return -1;
        buf[strlen(buf) - 1] = '\0';
        cur_node->content = content;
        strcpy(cur_node->content, buf);
        pre_node->next = cur_node;         // 节点链接
        pre_node = cur_node;
        
    }


    *dict = LinkList_Node;
    return 0;
}

void search_for_dict(DICT* LinkList_Node)
{
    
    bool found = false;
    char word[512] = {NULL};
    while(1)
    {
        DICT* tmp = LinkList_Node;
        printf("请输入单词: ");
        scanf("%s", word);
        while(tmp->next != NULL)
        {
            if(tmp->key && !strcmp(word, tmp->key))
            {
                found = true;
                break;
            }

            tmp = tmp->next;
        }
        if(found)
            printf("content: %s\n", tmp->content);
        else
        {
            printf("not found\n");
        }
    }
}

void printLinkList(DICT* LinkList_Node)
{
    
    while(LinkList_Node->next != NULL)
    {
        printf("key: %s\n", LinkList_Node->key);
        printf("content: %s\n", LinkList_Node->content);
        LinkList_Node = LinkList_Node->next;
    }
}

int main(void)
{
    int ret = 0;
    DICT *dict = NULL;
    if (dict_init(&dict))
        return -1;
    
    //printLinkList(dict);
    search_for_dict(dict);

    return 0;
}