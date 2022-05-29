/*
Create list
Display
Add first
Add last
Add mid
add any
Add n+1 or n-1 [Only function]
Delete first
Delete last
Delete mid
Delete any
Delete n+1 or n-1
Find by data
Find by position
Count
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {

    int data;
    struct node *next;

}*head;

void createlist(int n){

    int i, data;
    struct node *newnode, *temp;

    head = (struct node*)malloc(sizeof(struct node));

    printf("Enter data for the first node: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;

    for(i=2; i<=n; i++){

        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for new nodes: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;

    }

    printf("\n");

}

void display(){

    struct node *temp;

    temp = head;

    while(temp!=NULL){

        printf("|| %d ||  -->>  ", temp->data);
        temp= temp->next;

    }
    printf("NULL\n");

}

void addfirst(){

    int data;
    struct node *firstnode;

    firstnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for the newnode to add at first position: ");
    scanf("%d", &data);

    firstnode->data = data;
    firstnode->next = NULL;

    firstnode->next = head;
    head = firstnode;

    printf("\nData insertion successful!!\n");

}

void addlast(int n){

    int data;
    struct node *lastnode, *temp;

    lastnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for the last node of the list: ");
    scanf("%d", &data);

    lastnode->data = data;
    lastnode->next = NULL;

    temp = head;

    while(temp->next!=NULL){

        temp = temp->next;

    }

    temp->next = lastnode;

    printf("\nData insertion successful!!\n");

}

void addmid(int n){

    int data, mid;
    struct node *midnode, *currnode, *prevnode;

    prevnode = NULL;
    currnode = head;

    if(n%2==0){
        mid = n/2;
    }
    else if(n%2!=0){
        mid = (n+1)/2;
    }

    midnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for the mid node: ");
    scanf("%d", &data);

    midnode->data = data;
    midnode->next = NULL;

    for(int i=1; i<=mid; i++){

        prevnode = currnode;
        currnode = currnode->next;

    }

    prevnode->next = midnode;
    midnode->next = currnode;

    printf("\nData insertion successful!!\n");

}

void addany(int n){

    int i, data;
    struct node *newnode, *prevnode, *currnode;

    prevnode = NULL;
    currnode = head;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for the newnode to add at the %d position: ", n);
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = NULL;

    if(n==1){

        newnode->next = head;
        head = newnode;

        printf("\nData insertion successful!!\n");

    }
    else{

        for(i=2; i<=n; i++){

            prevnode = currnode;
            currnode = currnode->next;

        }

        prevnode->next = newnode;
        newnode->next = currnode;

        printf("\nData insertion successful!!\n");

    }



}

void add_at_algebric_position(int n){

    int data, i;
    n = n-1;
    struct node *newnode, *prevnode, *currnode;

    prevnode = NULL;
    currnode = head;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data to add at n-1 or %d position: ", n);
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = NULL;

    for(i=2; i<=n; i++){

        prevnode = currnode;
        currnode = currnode->next;

    }

    prevnode->next = newnode;
    newnode->next = currnode;

    printf("\nData insertion successful!!\n");

}

void deletefirst(){

    struct node *firstnode;

    firstnode = head;
    head = head->next;

    free(firstnode);

}

int count(){

    int num;

    struct node *temp;

    temp = head;

    while(temp!=NULL){

        num++;
        temp = temp->next;

    }

    return num;

}

void deletelast(int n){

    struct node *prevnode, *currnode;

    prevnode = NULL;
    currnode = head;

    int i;

    for(i=2; i<=n; i++){

        prevnode = currnode;
        currnode = currnode->next;

    }

    if(currnode!=NULL){

        if(prevnode!=NULL){

            prevnode->next = currnode->next;
            free(currnode);

        }

    }

}

void deletemid(int n){

    int i, a;
    struct node *prevnode, *currnode;

    prevnode = NULL;
    currnode = head;

    if(a%2==0){
        a = n/2;
    }
    else if(a%2!=0){
        a = (n+1)/2;
    }

    for(i=2; i<=a; i++){

        prevnode = currnode;
        currnode = currnode->next;

    }

    if(currnode!=NULL){

        if(prevnode!=NULL){

            prevnode->next = currnode->next;
            free(currnode);

        }

    }


}

void deleteany(int n){

    int i;
    struct node *prevnode, *currnode;

    prevnode = NULL;
    currnode = head;

    if(n==1){

        currnode = head;
        head = head->next;
        free(currnode);

    }
    else{

        for(i=2; i<=n; i++){

            prevnode = currnode;
            currnode = currnode->next;

        }

        if(currnode!=NULL){

            if(prevnode!=NULL){

                prevnode->next = currnode->next;
                free(currnode);

            }

        }

    }

}

void find_by_data(int n){

    int data, i;
    struct node *temp;

    printf("\nEnter data to find a node in the linked list: ");
    scanf("%d", &data);

    temp = head;

    for(i=1; i<=n; i++){

        if(temp->data == data){

            printf("\nThe node found according to the given data.\n");
            printf("The node is at %dth position.\n", i);

        }

        temp = temp->next;

    }

}

void find_by_positon(int n){

    int w;
    struct node *temp;

    printf("\nEnter position to find a node: ");
    scanf("%d", &w);

    temp = head;

    for(int i = 1; i<=n; i++){

        if(i==w){

            printf("\nA node exists at the given position\n");
            printf("The node stores %d data\n", temp->data);

        }

        temp = temp->next;

    }

}

int main(){

    int n;
    printf("Enter the number of nodes you want to add: ");
    scanf("%d", &n);
    //Creating a linked list
    createlist(n);
    printf("The linked list: \n");
    printf("\n");
    //Displaying a linked list
    display();
    printf("\n");
    addfirst();
    printf("\n");
    display();
    printf("\n");
    addlast(n);
    printf("\n");
    display();
    printf("\n");
    addmid(n);
    printf("\n");
    display();
    printf("\n");
    int any;
    printf("Enter position to add node: ");
    scanf("%d", &any);
    addany(any);
    printf("\n");
    display();
    printf("\n");

    deletefirst();
    printf("\nAfter deleting the first node\n");
    printf("\n");
    display();
    printf("\n");

    int m;
    printf("\nEnter the number of nodes are available now: ");
    scanf("%d", &m);
    deletelast(m);
    printf("\nAfter deleting the last node\n");
    printf("\n");
    display();
    printf("\n");

    int k;
    printf("\nEnter the number of nodes are available now: ");
    scanf("%d", &k);
    deletemid(k);
    printf("\nAfter deleting the mid node\n");
    printf("\n");
    display();
    printf("\n");

    int s;
    printf("\nEnter the position to delete node: ");
    scanf("%d", &s);
    deleteany(s);
    printf("\nAfter deleting the node\n");
    printf("\n");
    display();
    printf("\n");

    int x;
    printf("\nEnter the number of nodes are available now: ");
    scanf("%d", &x);
    find_by_data(x);

    int y;
    printf("\nEnter the number of nodes are available now: ");
    scanf("%d", &y);
    find_by_positon(y);

    printf("\n\nThe linked list contains %d nodes at last\n\n", count());



return 0;
}
