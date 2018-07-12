#include <iostream>
#include <stdlib.h>
#include<stdio.h>
typedef enum {Link, Thread} pointerTag;

typedef struct BithrNode
{
    char data;
    struct BithrNode * lchild, * rchild;
    pointerTag ltag;
    pointerTag rtag;

} BithrNode, *BithrTree;

using namespace std;

BithrTree pre;
//创建二叉树
createTree(BithrTree *T)
{
    char c ;
    scanf("%c", &c);
    if (' ' == c)
    {
        *T = NULL;

    }
    else
    {
        * T =  (BithrNode * )malloc(sizeof(BithrNode));
        (*T) ->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}

//中序遍历线索化
midOrder (BithrTree  T)
{
    if (T)
    {
        midOrder (T->lchild); //递归做孩子

        //节点处理
        if (!T->lchild)
        {
            T->ltag = Thread;
            T->lchild =  pre;

        }
        if (!pre->rchild)
        {


            pre ->rtag = Thread;
            pre->rchild = T;
        }
        pre = T;

        midOrder (T->rchild);

    }

}

//加入头节点
InorderThreading(BithrTree * p, BithrTree T)
{
    *p = (BithrTree)malloc(sizeof(BithrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p) ->rchild = *p;
    if(!T)
    {
        (*p) ->lchild = *p;

    }
    else
    {
        (*p) ->lchild = T;
        pre = *p;
        midOrder(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;

    }


}

//非递归中序访问树节点
void InorderTraverse(BiThree T)
{
    BiThree p;
    p = T->lchild;
    while(p!=T)
    {
        while(p->ltag = = Link)
        {
            p = p->lchild;

        }
        visit(p->data);
        while(p->rtag == Thread && p->rchild != T )
        {
            p = p ->rchild;
            visit(p->data);

        }
        p = p->rchild;
    }

}


int main()
{
    BithrTree P,T = NULL;
    createTree (&T);
    InorderThreading(&P, T);
    cout << "Hello world!" << endl;
    return 0;
}
