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
//����������
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

//�������������
midOrder (BithrTree  T)
{
    if (T)
    {
        midOrder (T->lchild); //�ݹ�������

        //�ڵ㴦��
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

//����ͷ�ڵ�
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

//�ǵݹ�����������ڵ�
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
