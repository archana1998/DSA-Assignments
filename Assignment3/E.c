#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}Node;
Node * head =NULL;
Node * tail=NULL;
void addNode(int x)
{
    if(head==NULL)
    {
        head = (Node *) malloc(sizeof(Node));
        head->data=x;
        head->next=NULL;
        tail = head;
    }
    else
    {
        tail->next= (Node *) malloc(sizeof(Node));
        tail = tail->next;
        tail->data=x;
        tail->next = NULL;
    }
}
void print()
{
    Node * hc = head;
    while(hc!=NULL)
    {
        printf("%d ",hc->data);
        hc=hc->next;
    }
}
Node * last()
{
    Node * hc = head;
    while(hc->next->next!=NULL)
        hc = hc->next;
    return hc;
}
int main()
{
    int x;
    char c;
    while(scanf("%d",&x))
    {
        c = getchar();
        addNode(x);
        if(c=='\n')
            break;
    }
    Node * curr = head;
    while(curr!=NULL&&curr->next!=NULL)
    {
        Node* l = last();
        if(l!=curr)
        {
            tail->next = curr->next;
            curr->next = tail;
            tail = l;
            tail->next = NULL;
        }
        curr = curr->next->next;
    }
    print();
}
