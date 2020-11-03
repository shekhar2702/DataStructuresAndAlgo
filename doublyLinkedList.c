#include<stdio.h>
#include<stdlib.h>
struct Node{
struct Node *prev;
int data;
struct Node *next;
}*head,*last;
int size=6;
void create(int a[],int size){
int i;
struct Node *p=(struct Node *) malloc(sizeof(struct Node));
p->data=a[0];
p->prev=NULL;
p->next=NULL;
head=p;
for(i=1;i<size;i++){
    struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
    temp->prev=p;
    temp->data=a[i];
    temp->next=NULL;
    p->next=temp;
    p=temp;
}
last=p;
}
void display(){
struct Node *temp=head;
while(temp){
    printf("%d\n",temp->data);
    temp=temp->next;
}
}
void insert(int position,int data){
struct Node *temp=head;
int i;
if(position==1){
    struct Node *p=(struct Node *) malloc(sizeof(struct Node));
    p->data=data;
    p->next=head;
    p->prev=NULL;
    head=p;
    size++;
}
else{
    for(i=1;i<position-1 && temp;i++)
        temp=temp->next;
    struct Node *p=(struct Node *) malloc(sizeof(struct Node));
    p->data=data;
    p->prev=temp;
    if(temp->next)
        p->next=temp->next;
    else
        p->next=NULL;
    temp->next=p;
    size++;
}
}
void deletion(int position){
struct Node *temp=head;
if(position==1){
    head=head->next;
    head->prev=NULL;
    printf("Deleted element is %d\n",temp->data);
    free(temp);
    //size--;
}
else{
        int i;
    for(i=0;i<position-1 && temp;i++)
        temp=temp->next;
        temp->prev->next=temp->next;
    if(temp->next){
      temp->next->prev=temp->prev;
    }
    printf("deleted element is %d\n",temp->data);
    free(temp);
}
}
void reverse(){
struct Node *p=head;
struct Node *temp;
last=head;
while(p){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    if(p->prev==NULL)
        head=p;
    p=p->prev;
}
}
int main(){
int A[6]={1,2,3,4,5,6};
create(A,6);
//deletion(1);
reverse();
display();
}
