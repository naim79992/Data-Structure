#include<stdio.h>
#define CAPACITY 3
int stack[CAPACITY];
int top=-1;


void push(int x) //void use korbo cz kisu return krtesi na onno kono function e.
{
    if(top<CAPACITY-1)
    {
        top=top+1;
        stack[top]=x;
        printf("Successfully added item %d\n",x);
    }
    else
    {
        printf("Exceptional!No spaces to add %d\n",x);
    }

}


int pop(){ //void pop(int x) hobe na +++ void use hobe na be careful

    if(top>=0){
     int val=stack[top];
      top=top-1;
      return val;
    }

    printf("Empty\n");
    return -1;
}
//wrong approch
/*
int pop(){

 if(top>=0){
 stack[top];
 top=top-1;
 return stack[top];
 }
 */

int peek(){   //void peek(int x){ hobe na +++++ void use hobe na(be careful)
 if(top >= 0){
        return stack[top];
    }
    printf("Exception from Peek! Empty Stack\n");
    return -1;
}

int main(){

printf("Implementing my stack in C.\n");
    peek();
    push(10);
    push(20);
    push(30);
    printf("Pop item: %d\n", pop());
    push(40);
    printf("Top of Stack: %d\n",peek());

return 0;
}
