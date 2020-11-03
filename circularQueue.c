#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
int size;
int *a;
int f;
int r;
};
void createQueue(struct circularQueue *q){
int i,num,temp;
printf("Enter the number of elements\n");
scanf("%d",&num);
printf("enter all the queue elements\n");
for(i=0;i<num;i++){
    q->r++;
    scanf("%d",temp);
    q->f=temp;
}

}
void enqueue(struct circularQueue *q,int num){
if(q->r+1%q->size==q->f)
    printf("queue full hence nothing can be inserted anymore\n");
else{
    q->r=q->r+1%q->size;
    q->a[q->r]=num;
}
}
int dequeue(struct circularQueue *q){
printf("Testing\n");
int x;
if(q->f==q->r){
    printf("Nothing can be deleted as queue is empty\n");
    return 0;
}
else{
    q->f=q->f+1%q->size;
    x=q->a[q->f];
}
return x;
}
void display(struct circularQueue *q){
int front=q->f+1%q->size;
while(front!=q->f){
    printf("%d",q->a[front]);
    front=(front+1)%q->size;
    }
}
int main(){
struct circularQueue q;
q.f=q.r=0;
printf("Enter the size of the array\n");
scanf("%d",&q.size);
q.a=(int *) malloc(q.size*sizeof(int));
printf("Create the queue now by entering the elements\n");
//createQueue(&q);
int ch;
int element;
while(1){
printf("Now enter your choice 1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
scanf("%d",&ch);
switch(ch){
case 1:
    printf("Enter the element to be inserted\n");
    scanf("%d",&element);
    enqueue(&q,element);
    break;
case 2:
    printf("Testing\n");
    element=dequeue(&q);
    printf("The element deleted is %d\n",element);
    break;
case 3:
    display(&q);
    break;
case 4:
    return 0;
}
}
return 0;
}
