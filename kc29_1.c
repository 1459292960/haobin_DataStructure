/* @date: 2020-09-04 21:15:36
@功能:
    完成一个链表的基本功能：生成、遍历、判断是否为空、求链表长度、排序、插入、删除
@目的:
    对链表实现的底层了解
*/


# include <stdio.h>
# include <malloc.h>
# include <stdlib.h> // exit()方法
# include <stdbool.h> // true false

typedef struct Node
{
    int data;
    struct Node * pNext;

}NODE,*PNODE; // NODE 等价于 struct Node, PNODE 等价于 struct Node *

//函数声明
PNODE create_list(void); // 每条语句都需要以;结束
void traverse_list(PNODE pHead);
bool is_empty(PNODE ); // 判断链表是否为空
int length_list(PNODE pHead); // 求链表的长度
void sort_list(PNODE pHead); // 排序
bool insert_list(PNODE pHead,int pos,int val);
bool delete_list(PNODE pHead,int pos,int * pVal);

int main (void)
{   
    int val;
    PNODE pHead = NULL; // 定义一个结构体指针变量，并将其内容清空
    pHead = create_list(); // 创建一个非循环单链表，并将该链表的首地址赋给pHead
    traverse_list(pHead);
    if(is_empty(pHead))
        printf("链表为空！\n");
    printf("链表的长度为%d\n",length_list(pHead));
    sort_list(pHead);
    traverse_list(pHead);
    insert_list(pHead,2,100);
    traverse_list(pHead);
    delete_list(pHead,2,&val);
    printf("val = %d\n",val);
    traverse_list(pHead);
    return 0;
}
// 生成一个单链表
PNODE create_list(void)
{
    int len;
    int i;
    int val;
    printf("请输入您需要生成的链表节点的个数：len=");
    scanf("%d",&len);
    PNODE pHead=(PNODE)malloc(sizeof(NODE)); // 操作系统分配一个不存放有效数据的头节点
                                                                                                    // pHead中存放该内存的第一个字节的地址，但是指向整个结构体变量
    if (NULL == pHead) // 分配内存失败
    {
        printf("Fail to generate node!\n");
        exit(-1);
    }
    PNODE pTail = pHead; // pTail 永远指向最后一个节点
    pTail->pNext=NULL; // 将头节点指针域清空
    for (i=0;i<len;i++)
    {

        printf("please enter the %dth value for the node:",i+1);
        scanf("%d",&val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("Fail to generate node!\n");
            exit(-1);
        }
        pNew->data =val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail =pNew;

    }
    return pHead;
  
}
// 将链表输出
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext; // p指向第一个有效节点
    while (p != NULL)
    {
        printf("%d ",p->data);
        p=p->pNext;
    }
    printf("\n");
    return;
}
bool  is_empty(PNODE pHead)
{

    if (pHead->pNext == NULL)
        return true;
    else
    {
        return false;
    }
    
}
int length_list(PNODE pHead)
{

    int cnt=0;
    PNODE p=pHead->pNext;
    while(p !=NULL)
    {
        cnt++;
        p=p->pNext;
    }
    return cnt;
}
// 升序排序
void sort_list(PNODE pHead)
{
    int len=length_list(pHead);
    PNODE p,q;
    int i,j,t;

    for (p=pHead->pNext;p->pNext != NULL;p=p->pNext)  // p指向首节点
        for(q=p->pNext;q != NULL;q=q->pNext)  // q指向首节点的下一个节点
        {
            if (p->data>q->data)
            {
                t=p->data;
                p->data=q->data;//a[i]=a[j];
                q->data=t;//a[j]=t;
            }
        }
}
bool insert_list(PNODE pHead,int pos,int val)
{
    int i=0;
    PNODE p=pHead;
    while (NULL != p && i<pos-1)
    {
        p=p->pNext;
        ++i;
    }
    if (i>pos-1 || NULL == p)
        return false;
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("动态分配内存失败！\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q=p->pNext; // 将原先第pos个节点的地址保存在q，如果原先链表只有pos-1个节点，那么就将NULL赋给q
    p->pNext=pNew; // 将新生成的节点挂在pos-1个节点上
    pNew->pNext=q; // 将原先的第pos个节点挂在新生成的节点上
    return true;

}
// 删除第pos个节点，pos从1开始
bool delete_list(PNODE pHead,int pos,int * pVal)
{

    int i=0;
    PNODE p=pHead;
    while (NULL != p->pNext && i<pos-1)
    {
        p=p->pNext;
        ++i;
    }
    if (i>pos-1 || NULL ==p->pNext) //NULL == p->pNext避免错误：类似只有两个有效节点，却删除第三个节点
                                                                    // ？i > pos-1避免了什么样的错误
        return false;
    PNODE q=p->pNext; // 将第pos个节点的地址赋给q 
    *pVal = q->data;

    p->pNext=p->pNext->pNext;// 将第pos+1个节点挂在第第pos-1个节点上，即原先第pos+1个节点变为第pos个节点
    free(q); // 释放第pos个节点
    q=NULL; // q所指向的结构体变量释放之后，代表将那段内存的使用权限还给操作系统，但那段内存还存着数，
                    // q如果还指向那段已经不属于本程序的那段内存的话，就“越界”了
    return true;

}