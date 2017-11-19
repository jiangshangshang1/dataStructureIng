#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<time.h>
using namespace std;
#define ERROR 0
#define OK 1
#define  MAXSIZE   1000

/*************************************
                ��̬����
���ݽṹ��ÿ������ڵ㶼��ֵ���α�.
�α��ʾ��һ���ڵ㣬�ڵ��Ϊ���ýڵ�ͱ��ýڵ�
��һ���ڵ�����ڵ㱣����
��һ���ڵ��α��ʾ���ýڵ���ʼλ��
���һ���ڵ��α��ʾ���ýڵ����ʼλ��
���ýڵ�����һ��Ԫ�ص��α�ָ��0����ʾĩβ��
*************************************/

typedef int Status, Elem;

typedef struct
{
    int data;
    int cur;

} Compent,StackLinkList[MAXSIZE];


/**********************************
         ��ʼ������
����ֵ�������ָ��
���ֵ��״̬��
���ܣ�  �����Խڵ���α�ָ���һ���ڵ�
 ***********************************/
Status initLink(StackLinkList space)
{
    int i;
    for (i =0; i<MAXSIZE-1; i++)
    {
        space[i].cur = i+1;

    }
    space[MAXSIZE-1].cur = 0;
    return OK;

}

/*********************************

/*********************************
         ���䱸�ÿռ�
����ֵ�������ָ��
���ֵ�����ýڵ���±�
���ܣ�  �����ýڵ�ķ������ʹ��
 *********************************/
Status mallocSpace (StackLinkList  space)
{
    int i ;
    i = space[0].cur;
    if(space[0].cur)
    {
        space[0].cur = space[i].cur;  //�����õ��ó�������һ���ڵ�����õ���һ��
        return i;
    }


}

/********
��ȡ���ýڵ�ĳ���
******/
Status getLength(StackLinkList space)
{
    int i =MAXSIZE-1;
    int j = 0;
    while(space[i].cur)
    {
        i = space[i].cur;
        j++;

    }
    return j;
}

/*********************************
          ����ֵ
����ֵ�������ָ�룬��ʼֵ����
���ֵ��״̬��
���ܣ�  Ϊ�����ʼָ�����������ֵ
 *********************************/
Status createValue(StackLinkList space,int num)
{
    srand(time(0));
    int i,mov = MAXSIZE-1;
    space[mov].cur = 1;
    for(i=0; i<num; i++)
    {
        mov = space[mov].cur;
        space[mov].data = rand()%100+1;
    }
    space[0].cur=space[mov].cur;
    space[mov].cur = 0;
    return OK;
}


/******************

��̬����Ĳ���

*******************/
Status insertList(StackLinkList space, int i, Elem e)
{
    int newJ,j,k;
    if (i<1 || i>getLength(space))
    {
        return ERROR;
    }

    j = MAXSIZE-1;
    newJ = mallocSpace(space);
    if(newJ)
    {
        space[newJ].data = e;
        for (int k =1; k<=i-1 ; k++)  //��λ��Ҫ����λ�õ�ǰһ��Ԫ��
        {
            j =space[j].cur;

        }
        space[newJ].cur = space[j].cur;  //�������cur�����ǰһ��λ�õ�cur��Ҳ����ǰһ��λ�õĺ�һ��λ�õĵ�ַ
        space[j].cur = newJ; //Ҫ����λ�õ�ǰһ��λ�ô�Ž�Ҫ��������ֵ��cur
        return OK;

    }
    return ERROR;
}

/**���յ���������**/

void freeSL(StackLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur  = k;
}

/******************

��̬�����ɾ��

*******************/

Status deletetList(StackLinkList space, int i)
{
    int j,k;
    k =MAXSIZE-1;
    if (i<1 || i>getLength(space))
    {
        return ERROR;
    }
    for (int j =1; j<=i-1 ; j++)  //��λ��Ҫɾ��λ�õ�ǰһ��Ԫ��
    {
        k =space[k].cur;

    }

    j = space[k].cur;

    space[k].cur = space[j].cur;

    freeSL(space,j);

    return OK;
}


/**********************************
          �������
����ֵ�������ָ��
���ֵ��״̬��
���ܣ�  �������ֵһһ���
 **********************************/
Status printLink(StackLinkList space)
{
    int mov = MAXSIZE-1;
    while(space[mov].cur)
    {
        mov = space[mov].cur;
        printf("[%d] ",space[mov].data);
    }
    printf("\n");
    return OK;
}
int main()
{
    int num,value,index;
    StackLinkList L;
    initLink(L);
    printf("[create]enter num:");
    scanf("%d",&num);
    createValue(L,num);
    printLink(L);

    printf("[insert]enter index:");
    scanf("%d",&index);
    printf("[insert]enter value:");
    scanf("%d",&value);
    insertList(L,index,value);
    printLink(L);

    printf("[delete]enter index:");
    scanf("%d",&index);
    deletetList(L,index);
    printLink(L);
    return 0;
}
