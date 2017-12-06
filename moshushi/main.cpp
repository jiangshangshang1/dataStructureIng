#include <iostream>


#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<time.h>
using namespace std;


/*
魔术师发牌问题的简介：一位魔术师掏出一叠扑克牌，
魔术师取出其中13张黑桃，
洗好后，把牌面朝下。说：“我不看牌，
只数一数就能知道每张牌是什么？”魔术师口中念一，将第一张牌翻过来看正好是A；
魔术师将黑桃A放到桌上，继续数手里的余牌，
第二次数1，2，将第一张牌放到这叠牌的下面，将第二张牌翻开，正好是黑桃2，也把它放在桌子上。
第三次数1，2，3，前面二张牌放到这叠牌的下面，取出第三张牌，正好是黑桃3，
这样依次将13张牌翻出，全部都准确无误。求解：魔术师手中牌的原始顺序是什么样子的？
*/


struct  node
{
    int data;
    struct node * next;


} node;

typedef  struct node * musician;

//创建单向循环链表
musician create()
{
    int j = 13;
    int k = 0;

    musician head =NULL;
    musician tail =NULL;
    musician q =NULL;
    head = (musician)malloc(sizeof(node));
    if(NULL ==head)
    {
        printf("内存分配失败");
        return 0;
    }
    head->data =0;
    head->next=NULL;
    tail=head;


    for (int i =1; i<=12; i++)
    {
        q = (musician)malloc(sizeof(node));
        if(NULL == q)
        {
            printf("内存分配失败");
            return 0;
        }

        q->data = 0;
        q->next = head;
        tail->next = q;
        tail = q;

    }

    return head;


}


/**********魔术师排序********/
void musicianOrder(musician L)
{
    musician p  = NULL;
    p = L;
    p->data = 1;
    int countNumber = 2;
    int count = 0;
    while(1)
    {
        for (int i =0; i<countNumber; i++)
        {
            p =   p->next;
            //关键算法 如果此时位置有数据 循环数-1  并到下一个节点。
            if(p->data!=0)
            {
                p->next;
                i--;
            }
        }

        if(p->data == 0)
        {
            p->data = countNumber;
            countNumber++;

        }

        if(countNumber == 14)
        {
            break;

        }

    }

    p = L;
    for (int i =1;i<=13;i++) {
        cout<<p->data<<endl;
        p = p->next;

    }



}


int main()
{
    musician p = create();
    musicianOrder(p);
    return 0;
}
