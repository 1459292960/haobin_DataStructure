/* @date: 2020-09-05 21:15:14
@功能:
    动态栈：本质上是一个操作受限的链表（只能尾部增加或者删除节点）
@目的:

*/


# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE,*PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;

void init(PSTACK); // 初始化
void push(PSTACK,int ); // 压栈
void traverse(PSTACK); // 遍历
bool pop(PSTACK,int *); // 弹出
void clear(PSTACK); // 清空
int main (void)
{
    STACK S;
    int val;
    init(&S);
    push(&S,1);
    push(&S,2);
    push(&S,3);
    traverse(&S);
    // clear(&S);
    // traverse(&S);
    if( pop(&S,&val))
    printf("出栈成功，出栈的元素是%d\n",val);
    else
    {
        printf("出栈失败！\n");
    }
    
    // traverse(&S);

    return 0;
}
void init(PSTACK pS)
{   
    pS->pTop=(PNODE)malloc(sizeof(NODE));
    if (pS->pTop == NULL)
    {
        printf("分配内存失败！\n");
        exit(-1);
    }
    pS->pBottom=pS->pTop;
    pS->pTop->pNext = NULL;
    return ;
} 
// 压栈
void push(PSTACK pS,int val)
{   
    PNODE pNew = (PNODE)malloc(sizeof(NODE)); // pNew的类型为struct Node *类型，是一个结构体指针变量，
                                                                                                    // 里面存放的是一个结构体变量的地址
    if (pNew == NULL)
    {
        printf("Fail to generate a node !\n");
        exit(-1);
    }
    pNew->data=val;
    // t=pNew->pNext; // 这里p->pNext还是一个垃圾值
    pNew->pNext=pS->pTop;
    pS->pTop=pNew;


    return ;    
}
void traverse(PSTACK pS)
{
    PNODE p=pS->pTop;
    while(p->pNext !=NULL)
    {
        printf("%d ",p->data);
        p=p->pNext;

    }
    printf("\n");
    return ;
}
bool is_empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
        return true;
    else
    {
        return false;
    }
    
    
}
bool pop(PSTACK pS,int * pval)
{
    if (is_empty(pS)) // pS本身存放的就是S的地址
        return false;
    else
    {
        PNODE t=pS->pTop; // 先将要删除的节点地址保存起来，不然呆会要删的时候找不到该节点
        *pval=t->data;
        pS->pTop=pS->pTop->pNext;
        free(t); // 在VScode中，释放后的节点，其成员值也被删除了
        
        t=NULL;// 为了防止还通过指针变量t访问到已经释放的节点，将t的内容置为空
    }
    

    return true ;
}
void clear (PSTACK pS)
{  
     if (is_empty(pS))
        return ;
    else
    {
            
        PNODE p,q;
        p=pS->pTop;
        q=NULL;
        while(p!=pS->pBottom)
        {
            q=p->pNext;
            free(p);
            p=q;

        }
        pS->pTop=pS->pBottom;
    }

    return;
}
