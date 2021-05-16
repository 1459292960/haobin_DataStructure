/*@date:2021-05-16
    链式队列创建、入队、出队、遍历、求长度等操作
@功能:
    
@目的:
    
*/


#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<stdbool.h>

// 定义节点
typedef struct Node{
    int data;
    struct Node * pNext;
}NODE,* PNODE;
// 定义链式队列
typedef struct Queue{
    PNODE pFront;
    PNODE pRear;
}QUEUE,* PQUEUE;
// 函数声明
void create_queue(PQUEUE);
void append_queue(PQUEUE ,int );
void traverse_queue(PQUEUE); // 队列遍历
int len_queue(PQUEUE); // 求链表长度
bool del_queue(PQUEUE,int * );

int main(void){
    QUEUE Q;
    int val;
    create_queue(&Q);
    append_queue(&Q,1);
    append_queue(&Q,2);
    append_queue(&Q,3);
    traverse_queue(&Q);
    printf("链表长度为%d\n",len_queue(&Q));
    if(del_queue(&Q,&val)){
        printf("出队成功!出队的元素为%d\n",val);
    }
    else{
        printf("出队失败！");
    }
    traverse_queue(&Q);    
    if(del_queue(&Q,&val)){
        printf("出队成功!出队的元素为%d\n",val);
    }
    else{
        printf("出队失败！");
    }
    traverse_queue(&Q);
    if(del_queue(&Q,&val)){
        printf("出队成功!出队的元素为%d\n",val);
    }
    else{
        printf("出队失败！");
    }
    traverse_queue(&Q);      
    return 0;
}

void create_queue(PQUEUE pQ){
    pQ->pFront = (PNODE)malloc(sizeof(NODE));
    if(NULL == pQ->pFront){
        printf("fail to create a node!\n");
        exit(-1);
    }
    pQ->pRear = pQ->pFront;
    pQ->pRear->pNext = NULL;
    return ; // 需要返回两个指针，所以直接返回结构体Q，包含两个指针
}
void append_queue(PQUEUE pQ,int val){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew){
        printf("fail to create a node!\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = NULL;
    pQ->pRear->pNext = pNew; // 新的节点挂在尾节点后面
    pQ->pRear = pNew; // 尾指针指向新的节点
    return ;
}
bool is_empty(PQUEUE pQ){
    if(pQ->pFront == pQ->pRear)
        return true;
    else return false;
}
void traverse_queue(PQUEUE pQ){
    if(is_empty(pQ)){
        printf("the queue is empty!\n");
        return;
    }
    PNODE p = pQ->pFront->pNext;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}
int len_queue(PQUEUE pQ){
    PNODE p = pQ->pFront->pNext;
    int len = 0;
    while(p != NULL){
        len++;
        p = p->pNext;
    }
    return len;
}

bool del_queue(PQUEUE pQ,int * pVal){
    if(is_empty(pQ)){
        printf("the queue is empty,fail to delete!\n");
        return false;
    }
    if(pQ->pFront->pNext == pQ->pRear){
        *pVal = pQ->pRear->data;
        free(pQ->pRear);
        pQ->pFront->pNext = NULL;
        pQ->pRear = pQ->pFront;
    }
    else{
        PNODE r = pQ->pFront->pNext; // 要删除的节点，只能从前端删除节点
        *pVal = r->data; // 出队的元素
        pQ->pFront->pNext = r->pNext;
        free(r);
        
    }
    return true;

}