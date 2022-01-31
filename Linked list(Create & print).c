#include<stdio.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{

//memory te space nei nai akn o.sob gula blanck rakhsi.
    struct Node *a=NULL;
    struct Node *b=NULL;
    struct Node *c=NULL;

//jayga nilam memory te
    a=(struct Node*)malloc(sizeof(struct Node));
    b=(struct Node*)malloc(sizeof(struct Node));
    c=(struct Node*)malloc(sizeof(struct Node));

//Assigning data
    a->data=10;
    b->data=20;
    c->data=30;

//Connect node's address by pointer
    a->next=b;
    b->next=c;
    c->next= NULL;

//Transvarse(sob node gula visit kore tader data gula print korbo.)
    while(a!=NULL)
    {
        printf("%d -> ",a->data);
        a=a->next; //not a->next3
    }
    return 0;
}
