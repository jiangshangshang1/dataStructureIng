#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
using namespace std;

/**结构体节点*/


typedef struct Node
{
    float data;
    struct Node * next;

} Node;

typedef struct Node * LinkedList;

/**头插法**/  //头插和尾插需要创建头节点指向整个链表
void qian_create(LinkedList * head, int n)
{

    srand(time(0));
    LinkedList p;
    int j;
    //创建头节点
    * head = (LinkedList)malloc(sizeof(Node));
    (*head)->next = NULL;

    for (int i=0; i<n; i++)
    {
        p = (LinkedList)malloc(sizeof( Node));
        p->data=rand()%100+1;
        p->next = (*head)->next;
        (*head)->next = p;

    }


}

/**尾插法*/  //借助节点标记
void end_create(LinkedList * head, int n)
{
    srand(time(0));
    LinkedList p, q;
    * head = (LinkedList)malloc(sizeof(Node));
    (*head)->next = NULL;
    q = * head;
    for (int i =0; i<n; i++)
    {
        p = (LinkedList)malloc(sizeof( Node));
        p->data=rand()%100+1;


        //重要
        p->next = q->next;
        q->next = p;
        q = p;

    }
}

/**输出链表**/
void printLinkList(LinkedList headNode)
{
    LinkedList p;

    p = headNode->next;
    while(p != NULL)
    {
        cout<<p->data<<endl;
        p=p->next;

    }



}

/**插入**/

void insert_list (LinkedList L, int n, int e)
{
    LinkedList p,q ;
    p = L;
    int j = 1;
    while(p&&j<n )
    {
        p = p->next;
        j++;

    }


    if (!p || j>n)
    {
        cout<<"EROOR INSERT POSITION"<<endl;
    }

    q = (LinkedList) malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;

}





/**删除**/


void delete_list (LinkedList L,int n)  //插入和删除不用创建头节点，传指针类型。
{
    LinkedList p,q;
    p = L;
    int j=1;
    while (p && j<n)
    {
        p = p->next;
        j++;
    }

    if(!p && j>n)
    {
        cout<<"INPUT ERROR"<<endl;
    }

    q = p->next;
    p->next = q->next;
    free(q);



}

void excuteAddOrDeleteAndPrint(LinkedList la)
{
    int e;
    int n;
    cout <<"是否继续操作 ,1-是 or 2-否"<<endl;
    int select ;
    scanf("%d",&select);
    if (select == 1)
    {
        printf("2--插入操作\n");
        printf("3--删除操作\n");
        int insertOrDelete;
        scanf("%d",&insertOrDelete);
        if (insertOrDelete == 2 )
        {
            printf("请输入插入的值和插入的位置,输入俩个后按enter");
            scanf("%d",&e);
            scanf("%d",&n);
            insert_list(la,n,e);
            printLinkList(la);
        }
        else if (insertOrDelete == 3)
        {
            printf("请输入删除的位置，按enter");
            scanf("%d",&n);
            delete_list(la,n);
            printLinkList(la);

        }

        else
        {
            cout<<"INPUT ERROR"<<endl;
        }


    }

}



int main()
{


    LinkedList la,lb;
    int switchId;
    int n;
    int e;

    printf("1--头插法创建链表，可以进行操作，并且可以输出\n");
    printf("5--尾插法创建链表，可以进行操作，并且可以输出\n");
    printf("0--退出\n");
    scanf("%d",&switchId);

    switch(switchId)
    {
    case 1://头插法
        cout<<"请输入创建链表节点个数"<<endl;
        printf("n=");
        scanf("%d",&n);
        qian_create(&la,n);
        printLinkList(la);
        excuteAddOrDeleteAndPrint(la);
        break;

    case 5://尾插法
        cout<<"请输入创建链表节点个数"<<endl;
        printf("n=");
        scanf("%d",&n);
        end_create(&la,n);
        printLinkList(la);
        excuteAddOrDeleteAndPrint(la);
        break;
    case 0:
        return 0;
    default:
        cout<<"Input ERROR"<<endl;

    }

    return 0;
}
