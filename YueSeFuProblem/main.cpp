#include <iostream>

#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<time.h>

using namespace std;


struct node
{

    int data;
    struct node * next;
} node;

typedef struct node * listOne;


/********

单项循环链表的创建

*********/
listOne createList()
{
    int j=0;
    int k=0;
    listOne head = NULL;
    listOne tail = NULL;
    listOne q = NULL;
    head = (listOne)malloc(sizeof(node));
    if(NULL ==head)
    {
        printf("内存分配失败");
        return 0;
    }

    head->data = 0;
    head->next = head;
    tail =  head;

    printf("请输入链表的长度");
    scanf("%d",&j);
    for(int i = 1 ; i<=j; i++)
    {
        q = (listOne)malloc(sizeof(node));
        if(NULL == q)
        {
            printf("内存分配失败");
            return 0 ;
        }
        printf("请输入第%d个节点的元素值：", i);
        scanf("%d", &k);
        q->data = k;
        q->next=head;
        tail->next =q;
        tail = q;
    }

    return head;
}

/************
杀死数到3的人

************/
void kill(listOne L)
{

    listOne pp = L->next;
    listOne temp;
    int m =3;

    while(pp->next!=L)
    {
        pp = pp->next;
    }

    //删除头节点
    pp->next = L->next;
    delete L;
    pp = pp->next;

    //当链表存在节点 继续杀人
    while(pp->next!=pp)
    {

        for (int i =1; i<m; i++)
        {
            temp = pp;
            pp = pp->next;

        }
        printf("%d\n",pp->data);
        temp ->next = pp->next;

        delete pp;
        pp = temp->next;


    }


    printf("%d\n",pp->data);
    delete pp;

}

//main
int main()
{

    listOne p = createList();
    kill(p);
    return 0;
}
