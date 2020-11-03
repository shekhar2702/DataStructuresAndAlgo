#include<stdio.h>
struct Node{
int data;
struct Node *next;
};
void insert(int data,int position);
void print();
void del(int position);
struct Node *head;
void main(){
head=NULL;
insert(2,1);
insert(3,2);
insert(4,1);
insert(5,2);
print();
del(1);
print();
}
void insert(int data,int position){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node*));
temp->data=data;
temp->next=NULL;
if(position==1){
    temp->next=head;
    head=temp;
    return;
}
struct Node *temp1=head;
int i;
for(i=1;i<position-1;i++)
    temp1=temp1->next;
temp->next=temp1->next;
temp1->next=temp;
}
void print(){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node*));
temp=head;
while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
}
}
void del(int position){
struct Node *temp=head;
if(position==1){
    free(head);
    head=temp;
    }
}
