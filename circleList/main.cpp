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


//���δӺ���c����
cirList create( )
{
    int i, length = 0, data = 0;
    cirList pTail = NULL, p_new = NULL,pHead=NULL;
    pHead = (cirList)malloc(sizeof(node));

    if (NULL == pHead)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    pHead->data = 0;
    pHead->next = pHead;
    pTail = pHead;

    printf("������Ҫ��������ĳ��ȣ�");
    scanf("%d", &length);

    for (i=1; i<length+1; i++)
    {
        p_new = (cirList)malloc(sizeof(node));

        if (NULL == p_new)
        {
            printf("�ڴ����ʧ�ܣ�\n");
            exit(EXIT_FAILURE);
        }

        printf("�������%d���ڵ��Ԫ��ֵ��", i);
        scanf("%d", &data);

        p_new->data = data;

        p_new->next = pHead;    //����һ����pHead����Ϊ���һ���ڵ�����ָ��ͷ�ڵ�
        pTail->next = p_new;
        pTail = p_new;
    }

    return pHead;
}





/***************

 ѭ������Ĳ���

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


//���������
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

 ѭ�������ɾ��

***************/
void deleteList(cirList L,int n)
{

    cirList p,q;
    p = L;


    int j  = 1;
    if(n<0 || n> getListLength(L))
    {
        cout<<"��������"<<endl;
        return;
    }

    if(j>n)
    {
        printf("��������");
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



//�������
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
    printf("������ �ڵ� :\n");
    printList(head);
    deleteList(head,1);
    printf("ɾ����� �ڵ� :\n");
    printList(head);
    return 0;
}
