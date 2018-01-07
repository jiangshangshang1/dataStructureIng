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

/**初始化栈**/
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
/**push栈**/
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

/**pop栈**/

void topPopStachk(sqStack  * L, int & e)  //这里用 &代表没有拷贝 对原有参数进行操作 效率高.
{
    if  (L->base == L->top)
    {
        printf("栈中已没数据\n");
        exit(0);

    }


    L->top--;
    e = *(L->top);

}


void popEleStack(sqStack  * L)
{
    if  (L->base == L->top)
    {
        printf("栈中已没数据\n");
        exit(0);

    }
    L->top--;
    cout<<"弹出的元素依次为:"<<*(L->top)<<endl;

}

/**清空栈***/
void clearStack(sqStack  * L)
{
    L->top =L->base;
}


/**销毁栈**一个个释放掉最后top和base指向NULL  size设置为0*/
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



/*栈的元素个数**/
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
    //cout<< "弹出的栈顶为："<<j <<endl;

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
