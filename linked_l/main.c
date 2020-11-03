#include<stdio.h>
struct Node{
int data;
struct Node *next;
}*head;
void insert(int n);
void display();
int main(){
head=NULL;
int n;
printf("how many values");
scanf("%d",&n);
insert(n);
display();
}
void insert(int n){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
if(head==NULL){
    printf("Enter head's data");
    scanf("%d",&temp->data);
    temp->next=NULL;
    head=temp;
}
int i;
for(i=2;i<=n;i++){
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp=temp->next;
}
}
void display(){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
temp=head;
if(head==NULL){
    printf("empty");
}
else{
    printf("data are:\n");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
}
