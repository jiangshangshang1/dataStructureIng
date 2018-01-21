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


/*��������*/
void createQueue(LinkQueue  *  q)
{
    q->front = q->rear = (QueuePrt)malloc(sizeof(Qnode));  //��Ҫ������ͷ
    if(!q->front)
    {
        exit(0);

    }

    q->front->next = NULL;


}

/*�������*/

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
/*������*/

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


/*���ٶ���*/
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
    printf("�������ַ���#����\n");
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
