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


/***����ջ��Ӧ�õĻ��˳��ջ�� �� �޷Ǿ��ǵ�����Ľ��ṹ  ��ջ�Ľṹ �����ʹ�� ��վ������ջ�� ��ջ��ջ��������**/


int main()
{
    return 0;
}
