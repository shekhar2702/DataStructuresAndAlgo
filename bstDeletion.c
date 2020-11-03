#include<stdio.h>
#include<stdlib.h>
struct Node{
struct Node *lChild;
int data;
struct Node *rChild;
}*root=NULL;
struct Node * insert(struct Node *p,int data){
if(p==NULL){
    struct Node *t=(struct Node *) malloc(sizeof(struct Node));
    t->data=data;
    t->lChild=t->rChild=NULL;
    return t;
}
else if(data<p->data)
    p->lChild=insert(p->lChild,data);
else if(data>p->data)
    p->rChild=insert(p->rChild,data);
return p;
}
struct Node * deletion(struct Node *p,int key){
struct Node *q;
if(p==NULL)
    return NULL;
if(p->lChild==NULL && p->rChild==NULL){
    free(p);
    return NULL;
}
if(key<p->data)
    p->lChild=deletion(p->lChild,key);
else if(key>p->data)
    p->rChild=deletion(p->rChild,key);
else{
    if(height(p->lChild)>height(p->rChild)){
    // q=inPredecessor(p->lChild);
     p->data=q->data;
     p->lChild=deletion(p->lChild,q->data);
    }
    else{
      //  q=inSuccessor(p->rChild);
        p->data=q->data;
        p->rChild=deletion(p->rChild,q->data);
    }
}
return p;
}
int height(struct Node *p){
    int x,y;
    if(p==NULL)
        return 0;
    x=height(p->lChild);
    y=height(p->rChild);
    if(x>y)
        return x+1;
    return y+1;
}
struct Node * inPredecessor(struct Node *p){
while(p->rChild!=NULL)
    p=p->rChild;
return p;
}
struct Node * inSuccessor(struct Node *p){
while(p->lChild!=NULL)
    p=p->lChild;
return p;
}
void inOrderTraversal(struct Node *p){
int element;
if(p){
    inOrderTraversal(p->lChild);
    printf("%d ",p->data);
    inOrderTraversal(p->rChild);
}
}

int main(){
root=insert(root,10);
root=insert(root,20);
root=insert(root,30);
root=deletion(root,20);
struct Node *p=inPredecessor(root->lChild);
printf("%d",p->data);
inOrderTraversal(root);
return 0;
}
