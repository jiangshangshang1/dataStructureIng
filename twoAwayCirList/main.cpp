#include <iostream>

#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<time.h>

using namespace std;


struct node
{
    int data;
    node * next;
    node * prior;


} node;


typedef struct node * nodeLink;

//双向循环链表的创建
nodeLink create()
{

    int n;
    printf("请输入要创建的链表的个数\t");
    scanf("%d",&n);
    nodeLink   head ;
    nodeLink   p;
    nodeLink   q;
    head = (nodeLink)malloc(sizeof(node));

    if(NULL==head)
    {
        printf("内存分配失败");
        exit(1);

    }

    head->data =0;
    head->prior=NULL;
    head->next=NULL;

    p = head;
    for(int i=1; i<=n; i++)
    {

        q = (nodeLink)malloc(sizeof(node));
        q->data = i;


        q->prior = p;
        q->next = p->next;
        p->next = q;

        p = q;

    }

    p->next = head->next;
    head->next->prior = p;
    return head;

}

//打印链表
void printLink(nodeLink head)
{
    nodeLink L =head->next;


    do
    {

        cout<<L->data<<endl;
        L = L->next;

    }
    while(L !=head->next);
}


/***********双向循环链表插入************/
int insertLink(nodeLink head)
{

    nodeLink   p;
    nodeLink   q;

    int pos,newdata;
    printf("请输入要插入的位置");
    scanf("%d",&pos);
    printf("请输入要插入的值");
    scanf("%d",&newdata);

    ///这里省去了异常case的判断,只在正常情况下进行  自己可以加上。 养成好习惯 不要像我哈！

    nodeLink L =head->next;

    for(int i=1; i<pos-1; i++)
    {
        L=L->next;
    }


    q = (nodeLink)malloc(sizeof(node));
    q->data =newdata;
    q->next = L->next;
    L->next->prior = q;
    L->next = q;
    q->prior = L;

    printf("插入后\n");
    printLink(head);



    return 1;

}

//删除 思想差不多 这里由于时间原因 省去了删除和插入的位置异常case !


int main()
{
    nodeLink head = create();
    printf("插入前\n");
    printLink(head);
    insertLink(head);

    return 0;
}
