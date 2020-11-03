#include<stdio.h>
#include<stdlib.h>
struct queue{
int front;
int rear;
int *q;
int size;
};
void enqueue(struct queue *Q,int num){
if(Q->rear==Q->size-1)
    printf("Queue full\n");
else
    Q->q[++Q->rear]=num;
}
int dequeue(struct queue *Q){
if(Q->rear==Q->front){
    printf("Nothing to be deleted.Hence returning 0\n");
    return 0;
}
else{
    Q->front++;
    return Q->q[Q->front];
}
}
void display(struct queue *Q){
int i;
if(Q->front==Q->rear){
    printf("Nothing to display\n");
}
else{
    printf("Testing\n");
    for(i=Q->front+1;i<=Q->rear;i++)
        printf("%d\n",Q->q[i]);
}
}
int main(){
struct queue Q;
printf("Enter the size of the queue\n");
scanf("%d",&Q.size);
Q.q=(int *) malloc(Q.size*sizeof(int));
Q.front=Q.rear=-1;
int ch,num,deleted;
while(1){
printf("Enter choice among 1.enqueue,2.dequeue,3.Display,4.quit\n");
scanf("%d",&ch);
switch(ch){
case 1:
    printf("Enter the number to be enqueued\n");
    scanf("%d",&num);
    enqueue(&Q,num);
    break;
case 2:
    deleted=dequeue(&Q);
    printf("%d\n",deleted);
    break;
case 3:
    printf("Elements are:\n");
    display(&Q);
case 4:
    printf("Exit\n");
    return 0;
}
}
}
