#include <iostream>
#include <vector>
#include <stdio.h>
#define  maxSIze 20
using namespace std;

typedef int Status;


/**构造线性表*/
typedef struct
{
    Status  data[maxSIze];
    int length;

} SqList ;


/**
*
*
*线性表的插入,返回Int  ,参数为线性表的指针，插入的位置，插入的值
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
*   线性表删除,参数线性表的指针 ，删除的位置。
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




///主函数   ///对于线性表的的顺序存储结构，在存 读数据 不管那个位置时间复杂度为o(1) ，插入删除时时间复杂度都为O(n)。
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
