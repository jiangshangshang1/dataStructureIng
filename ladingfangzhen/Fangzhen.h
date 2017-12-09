#ifndef FANGZHEN_H_INCLUDED
#define FANGZHEN_H_INCLUDED

class Node
{

public:
    Node();
    ~Node();
private:
    int data;
    Node * next;
    Node * head;
    Node * tail;
    Node * q;
public:
    Node * create(int n);
    void fangzhen(Node * head,int n);

};



#endif // FANGZHEN_H_INCLUDED
