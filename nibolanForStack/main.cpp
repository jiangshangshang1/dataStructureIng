#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
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

void popStachk(sqStack  * L, int & e)  //这里用 &代表没有拷贝 对原有参数进行操作 效率高.
{
    if  (L->base == L->top)
    {
        printf("栈中已没数据\n");
        exit(0);

    }


    L->top--;
    e = *(L->top);//top指向数据前一个位置的.

}


int getLength(sqStack  * L)
{
    return L->top - L->base ;

}





int main()
{
    sqStack s;
    createStack(&s);
    int e;

    char c;
    printf("请输入中缀表达式，以#作为结束标志");
    scanf("%c",&c);

    while(c!='#')
    {

        if(c>='0'&&c<='9')
        {
            printf("%c",c);
            // scanf("%c",&c);
            // if(c<'0'||c>'9'){
            //         printf(" ");

            // }

        }
        else if ('+' == c || '-' == c)
        {
            if (!getLength(&s))
            {

                pushStack(&s,c);
            }

            else
            {

                popStachk(&s,e);

                if(e == '+'||e == '-')
                {
                    pushStack(&s,e);

                }
                else{
                                printf("%c",e);

                }

                pushStack(&s,c);

            }


        }

        else if ('*' == c || '/'==c)
        {
            pushStack(&s,c);

        }
        else
        {
            printf("输入错误");

        }



        scanf("%c",&c);

    }

    while(getLength(&s))
    {
        popStachk(&s,e);
        printf("%c",e);

    }




    return 0;
}
