#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
struct Node *root=NULL;
void treeCreate(){
int x;
struct Queue q;
create(&q,20);
struct Node *temp,*p;
printf("Enter the root data\n");
scanf("%d",&x);
//printf("testing\n");
root=(struct Node *) malloc(sizeof(struct Node));
//printf("testing\n");
root->data=x;
root->lchild=root->rchild=NULL;
//printf("testing\n");
enqueue(&q,root);
//printf("testing");
while(!isEmpty(q)){
    //printf("%d",isEmpty(q));
    p=dequeue(&q);
    printf("Enter the left child value\n");
    scanf("%d",&x);
    if(x!=-1){
        temp=(struct Node *) malloc(sizeof(struct Node));
        temp->data=x;
        temp->lchild=NULL;
        temp->rchild=NULL;
        enqueue(&q,temp);
        p->lchild=temp;
    }
    printf("Enter the right child value\n");
    scanf("%d",&x);
    if(x!=-1){
        temp=(struct Node *) malloc(sizeof(struct Node));
        temp->data=x;
        temp->lchild=temp->rchild=NULL;
        enqueue(&q,temp);
        p->rchild=temp;
    }
}
}
void preOrder(struct Node *p){
if(p){
printf("%d ",p->data);
preOrder(p->lchild);
preOrder(p->rchild);
}
}
void postOrder(struct Node *p){
if(p){
    postOrder(p->lchild);
    postOrder(p->rchild);
    printf("%d ",p->data);
}
}
void inOrder(struct Node *p){
if(p){
    inOrder(p->lchild);
    printf("%d ",p->data);
    inOrder(p->rchild);
}
}
void main(){
treeCreate();
printf("Preorder results\n");
preOrder(root);
printf("Postorder results\n");
postOrder(root);
printf("Inorder results\n");
inOrder(root);
}
