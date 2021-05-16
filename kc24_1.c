/*@date:2021-04-29

@功能:
    实现链表的创建和遍历
@目的:
    
*/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node * pNext;
}NODE,* PNODE;
PNODE creatList(void){
    int len = 0;
    int val;

    PNODE pHead = (PNODE)malloc(sizeof(NODE)); // 创建一个头指针，指向头节点
    if(pHead == NULL){
        printf("creat list failed!");
        exit(-1);
    }
    PNODE pTail = (PNODE)malloc(sizeof(NODE)); // 创建一个尾指针，指向尾节点
    pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入节点的个数：");
    scanf("%d",&len);
    for(int i = 0; i < len; i++){
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL){
            printf("creat list failed!");
            exit(-1);
        }
        printf("请输入第%d个节点的值：",i+1);
        scanf("%d",&val);
        pNew->num = val;
        pTail->pNext = pNew; // 新创建的节点挂在尾节点后面
        pNew->pNext = NULL;
        pTail = pNew;        

    }
    return pHead;
}

void traverse_list(PNODE p){
    p = p->pNext; // 指向首节点
    while(NULL != p){
        printf("%d ",p->num);
        p = p->pNext;
    }
    printf("\n");
    return;
}
int main(void){
    PNODE p = creatList();
    traverse_list(p);
    return 0;
}