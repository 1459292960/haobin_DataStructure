/* @date: 2020-09-07 19:07:20
@功能:
    队列初始化、入队、出队、遍历、判断空、判断满
@目的:
    对队列底层编程了解
*/


# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct QUEUE
{
    int * pBase;
    int front;
    int rear;

}QUEUE;
void init(QUEUE *);
bool en_queue(QUEUE *,int ); // 入队
bool is_full(QUEUE *);
void traverse(QUEUE *);
bool out_queue(QUEUE *,int *);
int main (void)
{
    QUEUE Q;
    int val;
    init(&Q);
    en_queue(&Q,1);
    en_queue(&Q,2);
    en_queue(&Q,3);
    en_queue(&Q,4);
    en_queue(&Q,5);
    en_queue(&Q,6);
    traverse(&Q);
   if(out_queue(&Q,&val))
        printf("出队成功，出队的元素是%d\n",val);
    else
    {
        printf("出队失败！\n");
    }
    traverse(&Q);
    

    return 0;
}
void init(QUEUE * pQ)
{
    pQ->pBase=(int *)malloc(sizeof(int)*6);
    if (pQ->pBase == NULL)
    {
        printf("内存分配失败！");
        exit(-1);
    }
    else
    {
        pQ->front=0;
        pQ->rear=0;
    }
    

    return;
}
bool is_full(QUEUE * pQ)
{
    if ((pQ->rear+1)%6 == pQ->front )
        return true;
    else
        {
            return false;
        }
        
}
bool en_queue(QUEUE * pQ,int val)
{
    if (is_full(pQ))
    {
        printf("队列已满！\n");
       return false;
    }
    else
    {
        pQ->pBase[pQ->rear]=val;
        pQ->rear=(pQ->rear+1)%6; // rear代表有效元素的下一个位置
        return true;

    }

    
}
bool is_empty(QUEUE * pQ)
{
    if (pQ->rear == pQ->front)
        return true;
    else
    {
        return false;
    }
    
}
// 队列，是一种“先进先出”数据存储结构,遍历也从开头遍历
void traverse(QUEUE * pQ)
{
    if (is_empty(pQ))
        exit(-1);
    else
    {
        int q=pQ->front;
        while (pQ->rear !=q)
        {
            printf("%d ",pQ->pBase[q]);
            q=(q+1)%6;
        }
        printf("\n");

    }
    return ;
}
// 遍历
bool out_queue(QUEUE * pQ,int * pVal)
{
    if (is_empty(pQ))
        return false;
    else
    {
        *pVal=pQ->pBase[pQ->front];
        pQ->front=(pQ->front+1)%6;
        return true;
    }
}

/*@在VScode中的输出：
---------------------------------
队列已满！
1 2 3 4 5 
出队成功，出队的元素是1
2 3 4 5 
---------------------------------
@总结：
    1. 队列是以后操作受限的链表，只能在头部删除尾部插入，因此插入删除不能指定位置
    2.遍历操作从头部开始更容易
*/
