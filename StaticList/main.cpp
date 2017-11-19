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
                静态链表
数据结构：每个数组节点都有值和游标.
游标表示下一个节点，节点分为已用节点和备用节点
第一个节点和最后节点保留：
第一个节点游标表示备用节点起始位置
最后一个节点游标表示已用节点的起始位置
已用节点的最后一个元素的游标指向0，表示末尾。
*************************************/

typedef int Status, Elem;

typedef struct
{
    int data;
    int cur;

} Compent,StackLinkList[MAXSIZE];


/**********************************
         初始化链表
输入值：链表的指针
输出值：状态码
功能：  将所以节点的游标指向后一个节点
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
         分配备用空间
输入值：链表的指针
输出值：备用节点的下标
功能：  将备用节点的分配出来使用
 *********************************/
Status mallocSpace (StackLinkList  space)
{
    int i ;
    i = space[0].cur;
    if(space[0].cur)
    {
        space[0].cur = space[i].cur;  //将备用的拿出来。第一个节点存向备用的下一个
        return i;
    }


}

/********
获取已用节点的长度
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
          创建值
输入值：链表的指针，初始值个数
输出值：状态码
功能：  为链表初始指定个数的随机值
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

静态链表的插入

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
        for (int k =1; k<=i-1 ; k++)  //定位到要插入位置的前一个元素
        {
            j =space[j].cur;

        }
        space[newJ].cur = space[j].cur;  //将插入的cur存放他前一个位置的cur，也就是前一个位置的后一个位置的地址
        space[j].cur = newJ; //要插入位置的前一个位置存放将要插入的这个值的cur
        return OK;

    }
    return ERROR;
}

/**回收到备用链表**/

void freeSL(StackLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur  = k;
}

/******************

静态链表的删除

*******************/

Status deletetList(StackLinkList space, int i)
{
    int j,k;
    k =MAXSIZE-1;
    if (i<1 || i>getLength(space))
    {
        return ERROR;
    }
    for (int j =1; j<=i-1 ; j++)  //定位到要删除位置的前一个元素
    {
        k =space[k].cur;

    }

    j = space[k].cur;

    space[k].cur = space[j].cur;

    freeSL(space,j);

    return OK;
}


/**********************************
          输出链表
输入值：链表的指针
输出值：状态码
功能：  将链表的值一一输出
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
