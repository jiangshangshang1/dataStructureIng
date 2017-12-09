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

//˫��ѭ������Ĵ���
nodeLink create()
{

    int n;
    printf("������Ҫ����������ĸ���\t");
    scanf("%d",&n);
    nodeLink   head ;
    nodeLink   p;
    nodeLink   q;
    head = (nodeLink)malloc(sizeof(node));

    if(NULL==head)
    {
        printf("�ڴ����ʧ��");
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

//��ӡ����
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


/***********˫��ѭ���������************/
int insertLink(nodeLink head)
{

    nodeLink   p;
    nodeLink   q;

    int pos,newdata;
    printf("������Ҫ�����λ��");
    scanf("%d",&pos);
    printf("������Ҫ�����ֵ");
    scanf("%d",&newdata);

    ///����ʡȥ���쳣case���ж�,ֻ����������½���  �Լ����Լ��ϡ� ���ɺ�ϰ�� ��Ҫ���ҹ���

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

    printf("�����\n");
    printLink(head);



    return 1;

}

//ɾ�� ˼���� ��������ʱ��ԭ�� ʡȥ��ɾ���Ͳ����λ���쳣case !


int main()
{
    nodeLink head = create();
    printf("����ǰ\n");
    printLink(head);
    insertLink(head);

    return 0;
}
