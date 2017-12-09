#include "Fangzhen.h"
#include <iostream>


#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<time.h>

using namespace std;
Node ::Node()
{
}

Node ::~Node()
{
}
Node * Node ::create(int n)
{
    int k = 0;

    head =NULL;
    tail =NULL;
    q =NULL;
    head = new Node();
    if(NULL ==head)
    {
        printf("ÄÚ´æ·ÖÅäÊ§°Ü");
        exit(1);
    }
    head->data =0;
    head->next=NULL;
    tail=head;


    for (int i =1; i<=n; i++)
    {
        q = new Node();
        if(NULL == q)
        {
            printf("ÄÚ´æ·ÖÅäÊ§°Ü");
            exit(1);
        }

        q->data = i;
        q->next = head;
        tail->next = q;
        tail = q;

    }

    return head;
}

void Node :: fangzhen(Node *  head,int n)
{
    Node * q =NULL;

    Node * L = head->next;
    while(L->next!=head)
    {
        L = L->next;
    }
    L->next = head->next;
    delete head;
    L = L->next;
    q = L;
    for(int j=1; j<=n; j++)
    {



        for(int i =1; i<=n; i++)
        {

            printf("%d",L->data);
            L = L->next;

        }
        cout<<endl;
        L = q->next;
        q =L;
    }


}
