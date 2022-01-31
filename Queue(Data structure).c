#include<stdio.h>
#include<stdbool.h>

#define CAPACITY 5

int ourQueue[CAPACITY];
int front=0,rear=-1,totalItem=0;

bool isFull(){
if(totalItem==CAPACITY){
return true;
}
return false;
}

bool isEmpty(){
if(totalItem==0){
    return true;
}
return false;

}


void enquese(int item){

 if(isFull()){
 printf("Sorry ,the Queue is full.\n");
 return; //eta evabe likhlo kan?
 }

 rear=(rear+1)%CAPACITY;
 ourQueue[rear] = item;
 totalItem++;
}

void printQueue(){ //item add hoitese nki bojhar jonno.
int i;
printf("Queue: ");
for(i=0;i<CAPACITY;i++){
    printf("%d",ourQueue[i]);
}
printf("\n");
}

int dequeue(){
    if(isEmpty()){
        printf("Sorry, the Queue is empty.\n");
        return -1;
    }
    int frontItem = ourQueue[front];
    ourQueue[front] = -1;
    front = (front + 1) % CAPACITY;
    totalItem--;
    return frontItem;
}

int main()
{
    printf("Let's implement our Queue.\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(10);
    printQueue();
    enqueue();
    printQueue();
    enqueue(30);
    printQueue();

    return 0;
}
