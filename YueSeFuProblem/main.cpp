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

����ѭ������Ĵ���

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
        printf("�ڴ����ʧ��");
        return 0;
    }

    head->data = 0;
    head->next = head;
    tail =  head;

    printf("����������ĳ���");
    scanf("%d",&j);
    for(int i = 1 ; i<=j; i++)
    {
        q = (listOne)malloc(sizeof(node));
        if(NULL == q)
        {
            printf("�ڴ����ʧ��");
            return 0 ;
        }
        printf("�������%d���ڵ��Ԫ��ֵ��", i);
        scanf("%d", &k);
        q->data = k;
        q->next=head;
        tail->next =q;
        tail = q;
    }

    return head;
}

/************
ɱ������3����

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

    //ɾ��ͷ�ڵ�
    pp->next = L->next;
    delete L;
    pp = pp->next;

    //��������ڽڵ� ����ɱ��
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
