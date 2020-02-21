#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
typedef struct node
{
    int data;
    int min;
    struct node * prev;
}Node;
Node * tail = NULL;
void push(int x)
{
    if(tail==NULL)
    {
        tail = (Node *) malloc(sizeof(Node));
        tail->data = x;
        tail->min = x;
        tail->prev = NULL;
    }
    else
    {
        Node * c = (Node *) malloc(sizeof(Node));
        c->data = x;
        c->prev = tail;
        if(x<tail->min)
            c->min = x;
        else
            c->min = tail->min;
        tail = c;
    }
    printf("OK PUSHED %d\n",x);
}
void pop()
{
    if(tail!=NULL)
    {
        printf("OK POPPED %d\n",tail->data);
        Node *c = tail;
        tail = c->prev;
        free(c);
    }
    else
    {
        printf("STACK_UNDERFLOW\n");
    }
}
void peek()
{
    if(tail!=NULL)
        printf("%d\n",tail->data);
    else
        printf("STACK_UNDERFLOW\n");
}
void getMin()
{
    if(tail!=NULL)
        printf("%d\n",tail->min);
    else
        printf("STACK_UNDERFLOW\n");
}
int main()
{
    int n,x;
    char str[100];
    scanf("%d",&n);
    scanf("%c",str);
    for(int i=0;i<n;i++)
    {
        scanf(" %s",str);
        if(strcmp(str,"push")==0)
        {
            scanf("%d",&x);
            push(x);
        }
        else if(strcmp(str,"pop")==0)
            pop();
        else if(strcmp(str,"peek")==0)
            peek();
        else 
            getMin();
    }
}