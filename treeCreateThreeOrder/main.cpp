#include <iostream>
#include <stdlib.h>
using namespace std;

typedef  char ElemType;
typedef struct BiTNode
{
    ElemType  data;
    struct BiTNode * left, *right;

} BiTNode,*BiTree;

//����һ�Ŷ�����
createBitTree(BiTree * tree)
{
    ElemType ch;
    cin>>ch;

    if (ch == '#')
    {
        * tree = NULL;

    }
    else
    {
        *tree = (BiTree)malloc(sizeof(BiTNode));

        (*tree)->data = ch;
        createBitTree(&(*tree)->left);
        createBitTree(&(*tree)->right);

    }

}

void visit(ElemType ch, int level )
{
    cout<<ch<<"λ�ڵ�"<<level<<"��";


}

//�ݹ鷽ʽǰ������������
void preOrderTree( BiTree T, int level)
{
    if (T == NULL)
    {
        return;

    }
    visit(T->data, level);
    preOrderTree(T->left, level+1);
    preOrderTree(T->right, level+1);

}

//�ݹ鷽ʽ��������������
void midOrderTree( BiTree T, int level)
{
    if (T == NULL)
    {
        return;

    }

    midOrderTree(T->left, level+1);
    visit(T->data, level);
    midOrderTree(T->right, level+1);

}


//�ݹ鷽ʽ��������������
void afterOrderTree( BiTree T, int level)
{
    if (T == NULL)
    {
        return;

    }

    afterOrderTree(T->left, level+1);
    afterOrderTree(T->right, level+1);
    visit(T->data, level);

}




int main()
{
    int level =1;
    BiTree T = NULL;
    createBitTree(&T);
    midOrderTree(T,level);

    return 0;
}
