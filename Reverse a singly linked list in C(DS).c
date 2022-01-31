#include<stdio.h>
struct Node *createLinkedList(int arr[],int size);
void reverseLinkedList(struct Node *head);
//array er element dia linkedlist er 1 ta kore node(data & address part er member) banabo.

struct Node
{
    int data; //data part
    struct Node *next; //address part
};

int main()
{
    int a[]= {5,10,15};
    struct Node *head=NULL;
    head=createLinkedList(a,3);
    struct Node *Newhead=head;
    while(head!=NULL)
    {
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
     reverseLinkedList(Newhead);
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

void reverseLinkedList(struct Node *head)
{

    struct Node *prev=NULL,*current=head,*next=NULL; //*current=head
    while(current!=NULL)
    {
        //store the next node
        next=current->next; //store next

        //reverse the connection

        current->next=prev;
        prev=current;
        current=next;

    }
    head=prev;

//print output

    while(head !=NULL)
    {

        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}






