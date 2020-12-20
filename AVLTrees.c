#include<stdio.h>
#include<stdlib.h>
struct Node {
struct Node *lchild;
struct Node *rchild;
int data;
int height;
}*root=NULL;
int height(struct Node *p){
if(p!= NULL){
    int x = height(p->lchild);
    int y = height(p->rchild);
    if(x > y){
        return x+1;
    }
    else
        return y+1;
    return 0;
}
}
int balanceFactor(struct Node *p){
int hl = p && p->lchild ? p->lchild->height:0;
int hr = p && p->rchild ? p->rchild->height:0;
return hl-hr;
}
struct Node *llRotation(struct Node *p){
struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=p;
p->lchild=plr;
pl->height=height(pl);
p->height=height(p);
if(root == p){
    root=pl;
}
return pl;
}
struct Node *lrRotation(struct Node *p){
struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=plr->lchild;
p->lchild=plr->rchild;
plr->lchild=pl;
plr->rchild=p;
pl->height=height(pl);
plr->height=height(plr);
p->height=height(p);
if(p==root){
    root=plr;
}
return plr;
}
struct Node *insertNode(struct Node *p,int key){
if(p==NULL){
    struct Node *temp = NULL;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->lchild = temp->rchild = NULL;
    temp->data = key;
    temp->height = 1;
    return temp;
}
else if(key < p->data){
    p->lchild= insertNode(p->lchild,key);
}
else if(key > p->data){
    p->rchild= insertNode(p->rchild,key);
}
else{
    printf("Element already exist in the list hence can't be inserted\n");
}
p->height = height(p);
if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1){
    return llRotation(p);
}
else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1){
    return lrRotation(p);
}
//else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1){
  //  rrRotation(p);
//}
//else if(balanceFactor(p)==-2 && balanceFactor(p->lchild)==1){
  //  rlRotation(p);
//}
return p;
}
int main(){
root = insertNode(root,20);
insertNode(root,10);
insertNode(root,25);
insertNode(root,5);
insertNode(root,15);
insertNode(root,13);
insertNode(root,17);
printf("%d",root->data);
return 0;
}
