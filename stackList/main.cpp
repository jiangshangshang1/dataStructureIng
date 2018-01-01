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

void popStachk(sqStack  * L, int & e){ //这里用 &代表没有拷贝 对原有参数进行操作 效率高.
    if  (L->base == L->top) {
        printf("栈中已没数据\n");
        exit(0);

    }


    L->top--;
    e = *(L->top);

}


int main()
{
    sqStack L;
    createStack(&L);
    int e = 5;
    int j ;
    pushStack(&L , e);
    popStachk(&L, j);
    cout<< "弹出的为："<<j <<endl;
    return 0;
}
