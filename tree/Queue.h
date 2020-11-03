struct Node{
struct Node *lchild;
struct Node *rchild;
int data;
};
struct Queue{
int front;
int rear;
int size;
struct Node **Q;
};
void create(struct Queue *q,int size){
q->size=size;
q->front=q->rear=0;
q->Q=(struct Node **) malloc(size*sizeof(struct Node *));//array of pointers
}
void enqueue(struct Queue *q,struct Node *element){
if((q->rear+1)%q->size==q->front)
    printf("Queue full");
else{
        //printf("testingQ\n");
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=element;
}
}
struct Node * dequeue(struct Queue *q){
    struct Node *x=NULL;
    if(q->front==q->rear)
        printf("Queue is empty\n");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q){
return q.front==q.rear;
}
