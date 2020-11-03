#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
}*top;
void push(int data){
struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
temp->data=data;
temp->next=top;
top=temp;
}
void display(){
struct Node *current=top;
while(current){
    printf("%d\n",current->data);
    current=current->next;
}
}
int pop(){
if(!top){
    printf("Memory underflow");
    return;
}
struct Node *temp=top;
top=top->next;
free(temp);
}
int main(){
push(2);
push(3);
push(4);
push(5);
push(6);
push(7);
pop();
display();
return 0;
}
