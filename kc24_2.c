/* @date: 2021-05-10 22:04:38
@功能:
    链表的创建和遍历编程练习
@目的:

*/


#include <stdio.h>
#include<malloc.h>
#include<stdlib.h> // exit函数

// 定义一个结构体复合数据类型
typedef struct node{
    int data;
    struct node * pNext;
}NODE,* PNODE;

PNODE create_list(void){
    int len = 0;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL){
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    PNODE pTail = (PNODE)malloc(sizeof(NODE));
    pTail = pHead;
    pTail->pNext = NULL;
    printf("请输入您想要创建链表的长度：");
    scanf("%d",&len);
    for(int i = 0; i < len; i++){
        int val = 0;
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL){
            printf("动态内存分配失败！\n");
            exit(-1);
        }
        printf("请输入第%d个节点的值：",i+1);
        scanf("%d",&val); 
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;       
    }
    return pHead;
}
// 遍历链表
void traverse_list(PNODE pHead){
    PNODE p = pHead;
    p = p->pNext; // p指向首节点
    while(NULL != p){
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
    return; 
}

int main(void){
    PNODE pHead = create_list();
    traverse_list(pHead);
    return 0;
}
