/* @date: 2020-09-08 20:52:42
@功能:
    实现最简单的链式二叉树
@目的:
    了解链式二叉树如何实现
*/


# include <stdio.h>
# include <stdlib.h> // 或者 malloc.h

typedef struct BTNode
{
    char data;
    struct BTNode * pLchild;
    struct BTNode * pRchild;
}BTNODE,*PBTNODE;

PBTNODE CreateBTree (void);
void PreTraverse(PBTNODE); // 先序
void InTraverse(PBTNODE); // 中序
void PostTraverse (PBTNODE); // 后序
int main (void)
{
    PBTNODE pT=CreateBTree();
    PreTraverse(pT);
    printf("\n");
    InTraverse(pT);
    printf("\n");
    PostTraverse(pT);
    printf("\n");
    return 0;
}
// 构造一个链式二叉树
PBTNODE CreateBTree(void)
{
    PBTNODE pA = (PBTNODE)malloc(sizeof(BTNODE));
    PBTNODE pB = (PBTNODE)malloc(sizeof(BTNODE));
    PBTNODE pC = (PBTNODE)malloc(sizeof(BTNODE));
    PBTNODE pD = (PBTNODE)malloc(sizeof(BTNODE));
    PBTNODE pE = (PBTNODE)malloc(sizeof(BTNODE));
    pA->data='A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild =NULL;
    pD->pLchild = NULL;
    pD->pRchild=pE;
    pE->pLchild =pE->pRchild=NULL;
    return pA;

}
void PreTraverse (PBTNODE pT)
{
    /*
    伪算法：
        先访问根结点；
        再先序访问左子树；
        再先序访问右子树；
    */
   if (NULL != pT) // 必须使用if 语句判断pT是否为空，否则递归调用时pT为NULL，此时pT->data不存在，会导致出错
    {
    printf("%c",pT->data);
    if (NULL != pT->pLchild)
        PreTraverse(pT->pLchild);
    if (NULL != pT->pRchild)
        PreTraverse(pT->pRchild);
    }
    return;
}
void InTraverse (PBTNODE pT)
{
    /*
    伪算法：
        
        先中序访问左子树；
        再访问根结点；
        再中序访问右子树；
    */
   if (NULL != pT)
    {
    
    if (NULL != pT->pLchild)
        InTraverse(pT->pLchild);
    printf("%c",pT->data);
    if (NULL != pT->pRchild)
        InTraverse(pT->pRchild);
    }
    return;
}
void PostTraverse (PBTNODE pT)
{
    /*
    伪算法：
        
        先后序访问左子树；
        再后序访问右子树；
        访问根结点；
    */
   if (NULL != pT)
    {
    
    if (NULL != pT->pLchild)
        PostTraverse(pT->pLchild);
    if (NULL != pT->pRchild)
        PostTraverse(pT->pRchild);
    printf("%c",pT->data);
    }
    return;
}

/*@在VScode中的输出：
---------------------------------
ABCDE
BADEC  
BEDCA
---------------------------------
@总结：

*/
