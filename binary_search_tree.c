#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data){
   struct node* d=(struct node *)malloc(sizeof(struct node));
   d->data=data;
   d->left=NULL;
   d->right=NULL;
}
void preorder(struct node * root){
      if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
      }
}
void postorder(struct node * root){
      if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
      }
}
void inorder(struct node * root){
      if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
      }
}
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2=createnode(6);
    struct node *p3=createnode(1);
    struct node *p4=createnode(4);

    p->left=p1;  
    p->right=p2;  
    p1->left=p3;  
    p1->right=p4;  

    inorder(p);
      printf("\n");
    // printf("%d", isBST(p)); 
    if(isBST(p)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }
    return 0;
}