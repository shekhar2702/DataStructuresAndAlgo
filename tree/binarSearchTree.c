#include<stdio.h>
#include<stdlib.h>
struct Node{
struct Node *lchild;
int data;
struct Node *rchild;
};
struct Node * insert(struct Node *p,int element){
if(p==NULL){
    struct Node *t;
    t=(struct Node *) malloc(sizeof(struct Node));
    t->data=element;
    t->lchild=t->rchild=NULL;
    return t;
}
else if(element<p->data)
    p->lchild=insert(p->lchild,element);
else if(element>p->data)
    p->rchild=insert(p->rchild,element);
return p;
}
void preOrder(struct Node *p){
if(p){
 printf("%d ",p->data);
 preOrder(p->lchild);
 preOrder(p->rchild);
}
}
int main(){
struct Node *root=NULL;
root=insert(root,50);
root=insert(root,20);
root=insert(root,10);
root=insert(root,30);
root=insert(root,90);
preOrder(root);
}
