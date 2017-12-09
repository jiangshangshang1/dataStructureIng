#include <iostream>

#include "Fangzhen.h"

using namespace std;

int main()
{
    Node *  n = new Node();
    Node * head = n->create(5);
    n->fangzhen(head,5);

    return 0;
}
