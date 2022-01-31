#include<stdio.h>
struct Node *createLinkedList(int arr[],int size);
int searchLinkedList(struct Node *head,int value);

//array er element dia linkedlist er 1 ta kore node(data & address part er member) banabo.

struct Node
{
    int data; //data part
    struct Node *next; //address part
};

int main()
{
    int a[]= {15,30,45,60,100};
    struct Node *head=NULL;
    head=createLinkedList(a,5);
    struct Node *current=head;
    printf("Index : %d\n",searchLinkedList(head,60));

    return 0;
}

struct Node *createLinkedList(int arr[],int size)   //ei fucntion array nibe & array k linkedList e convert korbe.;
{
// VVI:  *createLinkedList hobe & struct Node type r


    struct Node *head=NULL,*temp=NULL,*current=NULL;
    int i;

    for(i=0; i<size; i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node)); //not int temp=(struct Node *)malloc(sizeof(struct Node));
        printf("%d\n",arr[i]);

        temp->data=arr[i];
        temp->next=NULL;

        if(head==NULL)
        {
            head=temp;
            current=temp;
        }
        else
        {
            current->next=temp;
            current=current->next;
        }
    }
    return head;
}



int searchLinkedList(struct Node *head,int value)
{
    int index=1;
    while(head!=NULL)
    {
        if(head->data==value)
        {
            return index;
        }
        index++;
        head=head->next;
    }
    return -1;
}


