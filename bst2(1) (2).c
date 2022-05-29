#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
}node;

// function to create new nodes
node *new_node(int data)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->info=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

// function to insert nodes in BST
node *insert(node *root,int data)
{
    if(root==NULL){
    return new_node(data);
    }

    else
    {
        if(data<root->info){
        root->left=insert(root->left,data);
        // printf("%p***",root);
        }
        else{
        root->right=insert(root->right,data);
        //printf("%p***",root);
        }

    }
   // printf("%d",root);
return root;
}

// function for inorder traversal
void implement(node *root)
{
    if(root)
    {
        printf("%d ",root->info);
        implement(root->left);

        implement(root->right);
    }
}
int main()
{

    node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    //root = insert(root, 60);
    //root = insert(root, 80);

    printf("the given Binary Search tree \n");
    implement(root);
    return 0;
}
