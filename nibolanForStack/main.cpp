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

void popStachk(sqStack  * L, int & e)  //������ &����û�п��� ��ԭ�в������в��� Ч�ʸ�.
{
    if  (L->base == L->top)
    {
        printf("ջ����û����\n");
        exit(0);

    }


    L->top--;
    e = *(L->top);//topָ������ǰһ��λ�õ�.

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
    printf("��������׺���ʽ����#��Ϊ������־");
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
            printf("�������");

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
