#include <iostream>


#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<time.h>
using namespace std;


/*
ħ��ʦ��������ļ�飺һλħ��ʦ�ͳ�һ���˿��ƣ�
ħ��ʦȡ������13�ź��ң�
ϴ�ú󣬰����泯�¡�˵�����Ҳ����ƣ�
ֻ��һ������֪��ÿ������ʲô����ħ��ʦ������һ������һ���Ʒ�������������A��
ħ��ʦ������A�ŵ����ϣ���������������ƣ�
�ڶ�����1��2������һ���Ʒŵ�����Ƶ����棬���ڶ����Ʒ����������Ǻ���2��Ҳ�������������ϡ�
��������1��2��3��ǰ������Ʒŵ�����Ƶ����棬ȡ���������ƣ������Ǻ���3��
�������ν�13���Ʒ�����ȫ����׼ȷ������⣺ħ��ʦ�����Ƶ�ԭʼ˳����ʲô���ӵģ�
*/


struct  node
{
    int data;
    struct node * next;


} node;

typedef  struct node * musician;

//��������ѭ������
musician create()
{
    int j = 13;
    int k = 0;

    musician head =NULL;
    musician tail =NULL;
    musician q =NULL;
    head = (musician)malloc(sizeof(node));
    if(NULL ==head)
    {
        printf("�ڴ����ʧ��");
        return 0;
    }
    head->data =0;
    head->next=NULL;
    tail=head;


    for (int i =1; i<=12; i++)
    {
        q = (musician)malloc(sizeof(node));
        if(NULL == q)
        {
            printf("�ڴ����ʧ��");
            return 0;
        }

        q->data = 0;
        q->next = head;
        tail->next = q;
        tail = q;

    }

    return head;


}


/**********ħ��ʦ����********/
void musicianOrder(musician L)
{
    musician p  = NULL;
    p = L;
    p->data = 1;
    int countNumber = 2;
    int count = 0;
    while(1)
    {
        for (int i =0; i<countNumber; i++)
        {
            p =   p->next;
            //�ؼ��㷨 �����ʱλ�������� ѭ����-1  ������һ���ڵ㡣
            if(p->data!=0)
            {
                p->next;
                i--;
            }
        }

        if(p->data == 0)
        {
            p->data = countNumber;
            countNumber++;

        }

        if(countNumber == 14)
        {
            break;

        }

    }

    p = L;
    for (int i =1;i<=13;i++) {
        cout<<p->data<<endl;
        p = p->next;

    }



}


int main()
{
    musician p = create();
    musicianOrder(p);
    return 0;
}
