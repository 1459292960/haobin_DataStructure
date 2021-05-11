/*@date:2021-04-29
    添加判断删除节点、插入节点的操作，难点
@功能:
    实现链表的创建、遍历、判断是否为空、计算链表的长度、删除节点、插入节点
@目的:
    
*/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h> // bool类型头文件
typedef struct Node{
    int num;
    struct Node * pNext;
}NODE,* PNODE;
PNODE creatList(void){
    int len = 0;
    int val;

    PNODE pHead = (PNODE)malloc(sizeof(NODE)); // 创建一个头节点
    if(pHead == NULL){
        printf("creat list failed!");
        exit(-1);
    }
    PNODE pTail = (PNODE)malloc(sizeof(NODE));
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
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;        

    }
    return pHead;
}

void traverse_list(PNODE p){
    p = p->pNext;
    while(NULL != p){
        printf("%d ",p->num);
        p = p->pNext;
    }
    printf("\n");
    return;
}
bool is_empty(PNODE p){
    if(NULL == p->pNext)
        return true;
    else
        return false;
}
int length_list(PNODE p){
    int len = 0;
    p = p->pNext;
    while(p != NULL){
        len++;
        p = p->pNext;
    }
    return len;
}
void sort_list(PNODE pHead){
    int t,i,j;
    PNODE p,q;
    int len = length_list(pHead);
    // 注意不可
    //     for(int i = 0,p = pHead->pNext; i < len-1; i++,p = p->pNext){
    // 这样p也会被定义为int 类型
    for(i = 0,p = pHead->pNext; i < len-1; i++,p = p->pNext){
        for(j = i+1,q = p->pNext; j < len; j++,q = q->pNext){
            if(p->num > q->num){
                t = p->num;// a[i];
                p->num = q->num;// a[i] = a[j];
                q->num = t;// a[j] = t;

            }
        }
    }
    return;
}
bool insert_list(PNODE pHead,int pos,int val){
    int i = 0;
    PNODE p = pHead; // 这样赋值一下，下面用p进行操作，是为了更容易理解
    while(NULL != p && i < pos-1){
        p = p->pNext;
        ++i;
    }
    if(i > pos-1 || NULL == p){
        return false;
    }
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew){
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    pNew->num = val;
    pNew->pNext = p->pNext;
    p->pNext = pNew;
    // PNODE q = p->pNext;
    // p->pNext = pNew;
    // pNew->pNext = q;
    return true;
}
bool delete_list(PNODE pHead,int pos ,int * val){
    int i = 0;
    PNODE p=pHead;
    while(i < pos-1 &&NULL != p->pNext){
        p = p->pNext;
        ++i;
    }
    if(i > pos-1 || NULL == p->pNext)
        return false;
    PNODE q = p->pNext;
    *val = q->num;
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;
    return true;
}
int main(void){
    int val = 0;
    PNODE p = creatList();
    traverse_list(p);

    if(is_empty(p))
        printf("链表为空！\n");
    else
        printf("链表不为空！\n");
    printf("链表的长度为%d\n",length_list(p));
    sort_list(p);
    printf("排序之后的列表输出：\n");
    traverse_list(p);

    insert_list(p,3,33);
    printf("插入节点后链表：\n");
    traverse_list(p);
    delete_list(p,3,&val);
    printf("删除节点后链表：\n");
    traverse_list(p);
    printf("删除的值为：%d\n",val);
    return 0;
}