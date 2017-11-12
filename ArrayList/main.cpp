#include <iostream>
#include <vector>
#include <stdio.h>
#define  maxSIze 20
using namespace std;

typedef int Status;


/**�������Ա�*/
typedef struct
{
    Status  data[maxSIze];
    int length;

} SqList ;


/**
*
*
*���Ա�Ĳ���,����Int  ,����Ϊ���Ա��ָ�룬�����λ�ã������ֵ
*/
Status ListInsert (SqList * L,int i,Status e)
{

    int k;
    if(L->length == maxSIze)
    {

        return 0;
    }

    if(i<1||i>L->length+1)
    {
        return 0;

    }

    if(i <= L->length)
    {
        for(k = L->length-1; k>= i-1; k--)
        {
            L->data[k+1] = L->data[k];
        }
    }

    L->data[i-1] = e;

    L->length++;

}


/**
*
*   ���Ա�ɾ��,�������Ա��ָ�� ��ɾ����λ�á�
*/

Status  deleteList (SqList * L, int i)
{
    Status e;

    if (L->length == 0)
    {
        return 0;

    }

    if(i<1||i>L->length)
    {
        return 0;
    }

    if (i <= L->length)
    {
        for (int deleteK = i; deleteK<=L->length; deleteK++)
        {
            L->data[deleteK-1] = L->data[deleteK];
        }

        e =L->data[i-1];
        L->length--;
    }
    return e;

}




///������   ///�������Ա�ĵ�˳��洢�ṹ���ڴ� ������ �����Ǹ�λ��ʱ�临�Ӷ�Ϊo(1) ������ɾ��ʱʱ�临�Ӷȶ�ΪO(n)��
int main()
{
    SqList   L;
    L.length = 7;

    for(int aa =0; aa<L.length; aa++)
    {
        L.data[aa] = aa;
    }

    int insertPosition = 3;
    int insertValue  = 9;

   // ListInsert(&L,insertPosition,insertValue);
    int returnDeleteNum = deleteList(&L,2);
    cout<<returnDeleteNum<<endl;
    for (int index =0; index<L.length; index++)
    {

       printf("list=%d",L.data[index]);
    }
    return 0;
}
