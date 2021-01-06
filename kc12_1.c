/* @date: 2020-09-04 21:18:59
@功能:
    完成一个线性表(连续存储数组)的基本功能：生成（初始化）、遍历、判断是否为空、判断是否为满、追加、插入、删除
@目的:
    了解顺序表的底层实现
*/


# include <stdio.h> // 标准输入输出函数 
# include <malloc.h> // malloc函数
#include <stdlib.h> // exit()方法
# include <stdbool.h> // 包含bool类型：true\ false等

// 定义了一个结构体符合数据类型
struct Arr
{
    int len; // 数组的长度
    int cnt; // 有效元素的个数
    int * pBase; //存放数组第一个字节的地址 
};
// 函数前置申明
void init_arr(struct Arr *,int );
void show_arr(struct Arr *);
bool  is_empty(struct Arr *);
bool is_full(struct Arr *);
bool append_arr(struct Arr *,int );
bool delete_arr(struct Arr *,int pos,int * pval);
bool insert_arr(struct Arr * pArr,int pos,int val); // 规定pos的值从1开始，
                                                                                                // 数组元素下标（从0开始）和第几个元素（从1开始）均可以指代位置，
                                                                                                // 具体使用哪一个就要在技术文档中说明
void sort_arr(struct Arr *);

int main (void)
{   int val;
    struct Arr arr;// 定义了一个结构体变量
    init_arr(&arr,6);
    show_arr(&arr);
    append_arr(&arr,11);
    append_arr(&arr,-2);
    append_arr(&arr,-13);
    append_arr(&arr,4);
    append_arr(&arr,5);
    append_arr(&arr,6);
    append_arr(&arr,7);
    append_arr(&arr,8);
    show_arr(&arr);
    // delete_arr(&arr,5,&val);
    // show_arr(&arr);
    // insert_arr(&arr,4,99);
    // show_arr(&arr);
    // sort_arr(&arr);
    //  show_arr(&arr);
    return 0;
}
// 冒泡法排序
void sort_arr(struct Arr * pArr)
{   
    int i,j,t;
    for (i=0;i < pArr->cnt-1;i++)
        for(j=0;j < pArr->cnt-1-i;j++)
        {

            if (pArr->pBase[j]>pArr->pBase[j+1])
            {
                t=pArr->pBase[j];
                pArr->pBase[j]=pArr->pBase[j+1];
                pArr->pBase[j+1]=t;
            }
        }
    return ;    
}
// 在指定位置插入一个元素，起始位置为1
bool insert_arr(struct Arr * pArr,int pos,int  val)
{
    int i;
    if (pos<1 || pos>pArr->cnt+1)
        return false;
    else if (is_full(pArr))
        return false;
    else
    {
        for (i =pArr->cnt;i>=pos;i--)
        {
            pArr->pBase[i]=pArr->pBase[i-1];
        }
        pArr->pBase[i]=val;
        pArr->cnt++;
    }
    return true;
}
bool delete_arr(struct Arr * pArr,int pos, int * pval) // 规定第一个元素的位置为1
{   int i;
    if (is_empty(pArr))
        return false; // 空数组，删除不成功
    if (pos<1 || pos >pArr->cnt)
        return false; // 指定的位置不存在或者没有元素，删除不成功
    *pval=pArr->pBase[pArr->cnt-1];
    for (i=pos;i < pArr->cnt;i++)
            pArr->pBase[i-1]=pArr->pBase[i];
    pArr->cnt--;
    return true;
}
void init_arr(struct Arr * parr,int len)
{
    parr->pBase = (int *)malloc(sizeof(int)*len); // pBase代表动态内存分配所形成数组的数组名
    if (NULL == parr->pBase)
    {   printf("数组分配不成功！\n");
        exit(-1);
    }
    else
    {
        parr->len = len;
        parr->cnt = 0; // 初始化，还没有给数组赋值，所有有效元素个数为0
    }
    
    return ;
}
// 判断数组是否为空
bool is_empty(struct Arr * pArr)
{
    if (0 == pArr->cnt)
        return true;
    else 
        return false;
}
// 输出数组
void show_arr(struct Arr * pArr)
{   int i;
    if (is_empty(pArr))
        printf("数组为空！\n");

    else
    {
        for (i=0;i<pArr->cnt;i++)
            printf("%d ",pArr->pBase[i]);
            printf("\n");
    }
    
    return ;

}
// 判断数组是否为空
bool is_full(struct Arr * pArr)
{
    if (pArr->cnt == pArr->len )
        return true;
    else 
        return false;
}
// 给数组追加元素
bool append_arr(struct Arr * pArr,int  val)
{   
    if (is_full(pArr))
    {
        printf("列表已满，追加失败！\n");
        return false;
    }  
    else
    {
        pArr->pBase[pArr->cnt]=val;

    }
    (pArr->cnt)++; //有效数据加1
    return true;
}