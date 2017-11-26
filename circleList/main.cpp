#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<time.h>

#define OK 1
#define ERROR 0

using namespace std;
struct node
{

    int data ;
    struct node * next;

} node;
typedef struct node * cirList;


//依次从后面c创建
cirList create( )
{
    int i, length = 0, data = 0;
    cirList pTail = NULL, p_new = NULL,pHead=NULL;
    pHead = (cirList)malloc(sizeof(node));

    if (NULL == pHead)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }

    pHead->data = 0;
    pHead->next = pHead;
    pTail = pHead;

    printf("请输入要创建链表的长度：");
    scanf("%d", &length);

    for (i=1; i<length+1; i++)
    {
        p_new = (cirList)malloc(sizeof(node));

        if (NULL == p_new)
        {
            printf("内存分配失败！\n");
            exit(EXIT_FAILURE);
        }

        printf("请输入第%d个节点的元素值：", i);
        scanf("%d", &data);

        p_new->data = data;

        p_new->next = pHead;    //这里一定是pHead，因为最后一个节点总是指着头节点
        pTail->next = p_new;
        pTail = p_new;
    }

    return pHead;
}





/***************

 循环链表的插入

***************/
int insertCirList(cirList clist, int n, int e)
{

    cirList p,q;
    p= clist;
    int i;
    int j=1;

    if (n<j&&!p)
    {
        return ERROR;
    }


    while (p &&n>j)
    {
        j++;
        p = p->next;
    }

    q = (cirList)malloc(sizeof(node));
    q->data= e;
    q->next =p->next;
    p ->next= q;

}


//获得链表长度
int getListLength(cirList L)
{
    cirList p_index;
    p_index = L->next;
    int count=0;
    while(p_index!=L)
    {
        count++;
        p_index =p_index->next;

    }
    return count;


}



/***************

 循环链表的删除

***************/
void deleteList(cirList L,int n)
{

    cirList p,q;
    p = L;


    int j  = 1;
    if(n<0 || n> getListLength(L))
    {
        cout<<"输入有误"<<endl;
        return;
    }

    if(j>n)
    {
        printf("输入有误");
        return ;
    }



    while(j <n)
    {
        p=p->next;
        j++;
    }



    q = p->next;
    p->next  = q->next;
    delete q ;
    q =NULL;





}



//遍历输出
void printList(cirList L)
{


    cirList p;
    p = L->next;


    while (p != L)
    {
        cout<<p->data<<"\n";
        p = p->next;
    }


}



int main()
{
    cirList  head  = create();
    printList(head);
    insertCirList(head,2,3);
    printf("插入后的 节点 :\n");
    printList(head);
    deleteList(head,1);
    printf("删除后的 节点 :\n");
    printList(head);
    return 0;
}
