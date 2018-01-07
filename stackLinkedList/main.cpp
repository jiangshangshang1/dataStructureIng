#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define NO 0

using namespace std;

typedef  struct StackNode
{
    int data;
    struct StackNode * next;

} StackNode;

typedef struct StackNode *LinkStackPtr;
typedef struct LinkStack
{
    LinkStackPtr top;
    int counts;

} LinkStack;


int push(LinkStack * s,int e)
{

    LinkStackPtr node = (LinkStackPtr)malloc(sizeof(StackNode));
    node->data = e;
    node->next = s->top;
    s->top = node;
    s->counts++;

    return OK;

}


int pop(LinkStack *S, int  *e){
    LinkStackPtr p;
    if(S->top = NULL){
            return NO;

    }

    *e = S->top->data;
    p = S->top;
    S->top  =S->top->next;
    S->counts--;
    free(p);

    return OK;



}


/***对于栈链应用的会比顺序栈少 ， 无非就是单链表的结点结构  ，栈的结构 。组合使用 进站：先入栈底 出栈从栈顶弹出。**/


int main()
{
    return 0;
}
