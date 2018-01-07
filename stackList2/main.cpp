#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#define STACK_INIT_SIZE  10
using namespace std;
typedef struct stackList
{
    int * base;
    int  * top;
    int stacksize;


} sqStack;

/**��ʼ��ջ**/
void  createStack(sqStack  * L)
{
    L->stacksize = STACK_INIT_SIZE;
    L->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
    if(! L->base)
    {
        exit(0);

    }
    L->top = L->base;


}
/**pushջ**/
void pushStack(sqStack  * L, int e)
{

    if (L->base - L->top >= STACK_INIT_SIZE)
    {
        L->base = (int*)realloc(L->base,(L->stacksize+10)*sizeof(int));
        if(!L->base)
        {

            exit(0);
        }
        L->top = L->base + L->stacksize;
        L->stacksize = L->stacksize+10;
    }

    *(L->top) = e ;
    L->top++;

}

/**popջ**/

void topPopStachk(sqStack  * L, int & e)  //������ &����û�п��� ��ԭ�в������в��� Ч�ʸ�.
{
    if  (L->base == L->top)
    {
        printf("ջ����û����\n");
        exit(0);

    }


    L->top--;
    e = *(L->top);

}


void popEleStack(sqStack  * L)
{
    if  (L->base == L->top)
    {
        printf("ջ����û����\n");
        exit(0);

    }
    L->top--;
    cout<<"������Ԫ������Ϊ:"<<*(L->top)<<endl;

}

/**���ջ***/
void clearStack(sqStack  * L)
{
    L->top =L->base;
}


/**����ջ**һ�����ͷŵ����top��baseָ��NULL  size����Ϊ0*/
void destoryStack(sqStack  * L)
{
    int i, len;
    len  = L->stacksize;
    for(int i =0; i<len; i++)
    {
        free(L->base);
        L->base++;

    }
    L->base = L->top = NULL;
    L->stacksize = 0;

}



/*ջ��Ԫ�ظ���**/
int getLength(sqStack  * L)
{
    return L->top - L->base ;

}



int main()
{


    sqStack L;
    createStack(&L);
    for (int i =0; i<5; i++)
    {
        pushStack(&L, i);

    }
    int j ;
    //topPopStachk(&L, j);
    //cout<< "������ջ��Ϊ��"<<j <<endl;

    int length = getLength(&L);
    cout<<length<<endl;
    clearStack(&L);
    /*
    for(int i= 0; i<length; i++)
    {
        popEleStack(&L);

    }
    */

    return 0;
}
