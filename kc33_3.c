/*@date:2021-05-16

@功能:
    栈生成、压栈、遍历、出栈、清空，第二次练习
@目的:
    
*/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义一个节点
typedef struct Node{
    int data; // 数据域
    struct Node * pNext; // 指针域
}NODE,* PNODE;
// 定义一个栈：有两个指针就可以决定一个栈
typedef struct Stack{
    PNODE pTop;
    PNODE pBottom;
}STACK,* PSTACK;
// 函数声明
void init_stack(PSTACK);
void push_stack(PSTACK,int);
void traverse_stack(PSTACK); // 遍历输出栈
bool pop_stack(PSTACK,int *);
void clear_stack(PSTACK);

int main(void){
    STACK S; // 直接定义 PSTACK pS;会由于pS没有初始化而发生错误
    int val;
    init_stack(&S);
    push_stack(&S,1);
    push_stack(&S,3);
    push_stack(&S,8);
    traverse_stack(&S);
    if(pop_stack(&S,&val)){
        printf("元素出栈成功！\n");
        printf("出栈的元素为%d\n",val);
    }
    else{
        printf("元素出栈失败！\n");
    }
    traverse_stack(&S);
    clear_stack(&S);
    traverse_stack(&S);

    return 0;
}
// void init_stack(PSTACK pS)
// {   
//     pS->pTop=(PNODE)malloc(sizeof(NODE));
//     if (pS->pTop == NULL)
//     {
//         printf("分配内存失败！\n");
//         exit(-1);
//     }
//     pS->pBottom=pS->pTop;
//     pS->pTop->pNext = NULL;
//     return ;
// } 
void init_stack(PSTACK pS){
    pS->pBottom = (PNODE)malloc(sizeof(NODE));
    if(pS->pBottom == NULL){
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    pS->pTop = pS->pBottom;
    pS->pBottom->pNext = NULL;
    
    return ;
}
// 压栈
void push_stack(PSTACK pS,int val){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
    return ;
}

void traverse_stack(PSTACK pS){
    PNODE p = pS->pTop;
    // while(p!=pS->pBottom){
    //     printf("%d ",p->data);
    //     p = p->pNext;
    // }
    while(p->pNext!= NULL){
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
    return ;
}
bool pop_stack(PSTACK pS,int * pVal){
    if(pS->pTop == pS->pBottom){
        return false;
    }
    else{
        PNODE r = pS->pTop;
        *pVal = r->data; // 弹出的元素
        pS->pTop = r->pNext;
        free(r);
        return true;
    }

}
void clear_stack(PSTACK pS){
    while(pS->pTop != pS->pBottom){
        PNODE r = pS->pTop;
        pS->pTop = r->pNext;
        free(r);
    }
    return ;
}