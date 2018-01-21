#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
typedef struct Qnode
{
    char data;
    struct Qnode * next;
} Qnode;

typedef struct Qnode * QueuePrt;

typedef struct Queue
{
    QueuePrt front,rear;
} LinkQueue;


/*创建队列*/
void createQueue(LinkQueue  *  q)
{
    q->front = q->rear = (QueuePrt)malloc(sizeof(Qnode));  //主要操作对头
    if(!q->front)
    {
        exit(0);

    }

    q->front->next = NULL;


}

/*插入队列*/

void getInQueue(LinkQueue  *  q,char e )
{

    QueuePrt p ;
    p = (QueuePrt)malloc(sizeof(Qnode));
    if(p == NULL)
    {
        exit(0);

    }

    p->data=e;
    p->next=NULL;
    q->rear->next = p;
    q->rear = p;





}
/*出队列*/

void getOutQueue(LinkQueue  *  q, char * e )
{
    QueuePrt p ;
    if(q->front == q->rear)
    {
        return;

    }
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p)
    {
        q->rear == q->front;

    }

    cout<<*e;
    free(p);


}


/*销毁队列*/
void destoryQ(LinkQueue * q)
{

    while(q->front)
    {
        q->rear = q->front->next;
        free(q->front);

        q->front= q->rear;
    }
}



int main()
{

    LinkQueue l ;
    createQueue(&l);
    char c;
    char a;
    printf("请输入字符按#结束\n");
    while(true)
    {


        scanf("%c",&c);
        getInQueue(&l,c);
        if(c == '#')
        {
            break;

        }

    }

    while(a != '#')
    {
        getOutQueue(&l,&a);

    }


    return 0;
}
