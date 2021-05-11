/* @date: 2021-05-10 22:04:38
@功能:
    链表的创建、遍历、翻转编程练习
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
// 链表翻转
void rev_List(PNODE pHead);
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
    rev_List(pHead);
    printf("翻转之后的链表:\n");
    traverse_list(pHead);
    return 0;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// PNODE reverseList(PNODE pHead)
// {
//     if (pHead == NULL) {
//         return NULL;
//     }
//     PNODE pre = pHead->pNext;
//     PNODE cur = pHead->pNext->pNext;
//     PNODE temp = NULL;
//     while (cur != NULL) {
//         // temp记录的是cur的next指针，这个很重要
//         temp = cur->pNext;
//         // 拆除原有的指向关系
//         cur->pNext = pre;
//         // pre和cur后移
//         pre = cur;
//         cur = temp;
//     }
//     // 最后记得head->next要置空
//     head->pNext = NULL;

//     return pre;
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// PNODE reverseList(PNODE head)
// {
//     // head要放前面，否则head为空的话会有语法问题
//     if (head == NULL || head->pNext == NULL) {
//         return head;
//     }
    
//     PNODE nextNode = head->pNext;
//     // newhead的意义在于记录返回值，在后续的处理中并没有用到head
//     PNODE newhead = reverseList(nextNode);
//     nextNode->pNext = head;
//     // 每次都要置空，否则的话，否则3->next->next = 3;也就是把5的值被3给覆盖掉了，链表会大乱
//     head->pNext = NULL;     
//     return newhead;
// }

/* 翻转链表
    头插法：用两个结构体指针先指向第一个和第二个节点，
    从首节点开始遍历链表,依次将各节点挂在头节点后面。
*/
void rev_List(PNODE pHead){
    PNODE p = pHead->pNext; // 指向首节点
    PNODE q ; // 指向第二个节点
    pHead->pNext = NULL;
    while(p){
        q = p->pNext;
        p->pNext = pHead->pNext;
        pHead->pNext = p;
        p = q;
        
    }
    return;
}
