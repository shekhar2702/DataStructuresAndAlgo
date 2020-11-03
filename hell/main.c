#include<stdio.h>
struct Node{
int data;
struct Node *next;
}*head;
void insert(int n);
void display();
void insert_at_begin();
void insert_at_end();
int main(){
int n;
printf("enter n\n");
scanf("%d",&n);
insert(n);
printf("the data are:-");
display();
insert_at_begin();
printf("after beg_insert\n");
display();
insert_at_end();
printf("after end insert");
display();
}
void insert(int n){
struct Node *temp,*temp1;
head=(struct Node*)malloc(sizeof(struct Node));
printf("enter the head's data");
scanf("%d",&head->data);
head->next=NULL;
int i;
temp=head;
for(i=2;i<=n;i++){
    temp1=(struct Node*)malloc(sizeof(struct Node));
    printf("enter %d data",i);
    scanf("%d",&temp1->data);
    temp1->next=NULL;
    temp->next=temp1;
    temp=temp->next;
}
}
void display(){
struct Node *temp;
if(head==NULL){
    printf("No data");
}
temp=head;
while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
}
}
void insert_at_begin(){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
printf("enter data to be inserted at beginning\n");
scanf("%d",&temp->data);
temp->next=head;
head=temp;
}
void insert_at_end(){
struct Node *temp,*temp1;
temp1=head;
while(temp1->next!=NULL){
    temp1=temp1->next;
}
temp=(struct Node*)malloc(sizeof(struct Node));
printf("Enter data to be inserted at the end");
scanf("%d",&temp->data);
temp->next=NULL;
temp1->next=temp;


}
