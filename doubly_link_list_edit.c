#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next, *prev;

}*head = NULL, *tail = NULL;

void createlist(){

    int i, data;
    struct node *newnode;

    head = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter data for the first node: ");
    scanf("%d",&data);

    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    for ( i = 2; i <= 3; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data for the newnode: ");
        scanf("%d",&data);

        newnode->data = data;
        newnode->prev = tail;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    
}

void display(){

    struct node *temp1, *temp2;

    temp1 = head;
    temp2 = tail;

    while (temp1!= NULL)
    {
         printf("||  %d  ||   - - > >   ", temp1->data);
         temp1 = temp1->next;
    }
    printf("NULL\n\n");

    while (temp2!= NULL)
    {
         printf("||  %d  ||   - - > >   ", temp2->data);
         temp2 = temp2->prev;
    }
    printf("NULL\n\n");
    

    
}

void insertNth(){

    int pos, data;
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    temp = head;

    printf("\nEnter node position: ");
    scanf("%d",&pos);

    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    
    if (pos==1)
    {
        printf("\nEnter data to add node: ");
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;

    }
    else if(temp==tail)
    {

        printf("\nEnter data to add node: ");
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        
    }
    else
    {
        
        printf("\nEnter data to add node: ");
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;

    }
      

}

void deleteNth(){

    int n, i;

    printf("\nEnter node position to delete: ");
    scanf("%d", &n);

    struct node *currnode, *prevnode;

    prevnode = NULL;
    currnode = head;

    for ( i = 1; i < n; i++)
    {
        prevnode = currnode;
        currnode = currnode->next;
    }

    if (n==1)
    {
        head = head->next;
        printf("\nData of the node which will be deleted: %d\n", currnode->data);
        free(currnode);
    }
    else
    {
        if (currnode!= NULL)
        {
            if (prevnode!= NULL)
            {
                prevnode->next = currnode->next;
                currnode->next->prev = prevnode;
                printf("\nData of the node which will be deleted: %d\n", currnode->data);
                free(currnode);
            }
            
        }
        
    }
    
    
    
}

int main(){


    createlist();
    printf("\nThe doubly linked list: \n\n" );
    display();
    printf("\n");

    int choice;

    while (1)
    {
        printf("\n\t*************************** Doubly Linked List ***************************\n");
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Menu =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertNth();
            printf("\nInsertion Successful\n");
            break;
        case 2:
            deleteNth();
            printf("\nDeletion Successful\n");
            break;
        case 3:
            display();
            printf("\n");
            break;
        case 4:
            exit(0);
            break;
        
        default:printf("\nEnter valid choice value\n");
            break;
        }
    }
    

}