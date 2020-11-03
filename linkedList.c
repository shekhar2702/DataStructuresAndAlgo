#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
}*head,*last;
int size=6;
//int s;
void createLinkedList(int a[],struct Node *p,int size){
head=p;
last=p;
head->data=a[0];
int i;
for(i=1;i<size;i++){
   struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
   temp->data=a[i];
   temp->next=NULL;
   last->next=temp;
   last=temp;
}
last->next=head;
}
void insertAtLast(struct Node *p,int data){
struct Node *current=p;
while(current->next!=NULL)
    current=current->next;
struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
temp->data=data;
temp->next=NULL;
current->next=temp;
last=temp;
size++;
recursiveDisplay();
}
void insert(struct Node *p,int position,int data){
int i=1;
struct Node *current=p;
while(i<position-1){
    current=current->next;
    i++;
}
struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
temp->data=data;
temp->next=current->next;
current->next=temp;
size++;
printf("After modifications\n");
display(p);
}
void display(struct Node *p){
struct Node *current=p;
while(current){
    printf("%d\n",current->data);
    current=current->next;
}
}
int recursiveAddition(struct Node *p){
if(!p)
    return 0;
else
    return recursiveAddition(p->next)+p->data;
}
void recursiveDisplay(struct Node *p){
struct Node *current=p;
while(current){
    printf("%d\n",current->data);
    current=current->next;
}
}
int recursiveMax(struct Node *p){
static int s;
if(!p)
    return -32768;
else{
    s=recursiveMax(p->next);
    if(s<p->data)
        return p->data;
}
}
void deleteElements(struct Node *p,int position){
if(position>size)
{
    printf("Enter valid values or just fuck off!!");
    return;
}
struct Node *q=p,*r;
int count=1;
if(position==1){
    p=p->next;
    free(q);
    display(p);
}
else{
    while(count<position-1){
        q=q->next;
        count++;
        }
        r=q->next;
        q->next=r->next;
        free(r);
        display(p);
}
}
void insertInSortedLinkedList(struct Node *p,int data){
struct Node *r=p->next;
struct Node *q=p;
struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
temp->data=data;
temp->next=NULL;
if(temp->data<p->data){
    //printf("testing\n");
    temp->next=p;
    //printf("%u\n",p);
    //printf("%u\n",temp);
    //printf("%u\n",temp->next);
    //p=temp;
    //printf("%u\n",temp->next);
    //printf("%u\n",p);
    size++;
    //printf("%d",temp->data);
    display(temp);
    return;
}
else{
        printf("Hello");
    while(r->data<temp->data && r->next!=NULL){
        q=q->next;
        r=r->next;
    }
    size++;
    if(r->data>temp->data && r->next==NULL){
     printf("test\n");
     printf("test\n");
    temp->next=q->next;
    q->next=temp;
    display(p);
     return;
    }
    else if(r->next==NULL){
        temp->next=NULL;
        q->next=temp;
        display(p);
        return;
    }
    printf("test");
    temp->next=q->next;
    q->next=temp;
    display(p);
}
}
void checkIfSorted(struct Node *p){
struct Node *q=p,*r=p->next;
while(r){
    if(q->data>r->data)
    {
        printf("Not sorted\n");
        return;
    }
    q=q->next;
    r=r->next;
}
printf("sorted");
}
void removeDuplicatesInSortedLinkedList(struct Node *p){
struct Node *current=p,*q=p->next;
while(q){
    //if(current->data==q->data){
    if(current->data!=q->data){
        current=q;
        q=q->next;
    }
    else{
        current->next=q->next;
        free(q);
        q=current->next;
    }
        //while(current->data==q->data){
          //  current->next=q->next;
            //free(q);
            //if(current->next!=NULL)
            //q=current->next;
        //}

    //if(current->next==NULL){
      // printf("Testing\n");
       //break;
    //}
    //current=current->next;
    //q=q->next;
}
display(p);
}
void reverseUsingThreePointers(struct Node *p){
struct Node *e=p,*d,*c;
//printf("%u",c->next);
while(e){
    d=e;
    e=e->next;
    d->next=c;
    c=d;
}
display(d);
}
void concatanateList(struct Node *p,struct Node *q){
struct Node *current=p;
while(current->next!=NULL)
    current=current->next;
current->next=q;
display(p);
}
void mergeLinkedList(struct Node *p,struct Node *q){
struct Node *firstPointer,*secondPointer,*temp,*current;
if(p->data<q->data){
    firstPointer=p;
    secondPointer=q;
    current=p;
}
else{
    current=q;
    firstPointer=q;
    secondPointer=p;
}
while(firstPointer && secondPointer){
    if(firstPointer->data<secondPointer->data){
        temp=firstPointer;
        firstPointer=firstPointer->next;
    }
    else{
        temp=secondPointer;
        secondPointer=secondPointer->next;
        temp->next=firstPointer;
    }
}
if(!firstPointer)
    temp->next=secondPointer;
display(current);
}
void loopCheck(struct Node *p)
{
    struct Node *q,*r;
    q=r=p;
    do{
        q=q->next;
        r=r->next;
        if(r->next!=NULL){
            r=r->next;
            if(r==q){
                printf("Looping Present\n");
                return;
            }
        }
        else{
            r=NULL;
        }
    }while(q && r);
    printf("No Loops\n");
}
void displayCircularLinkedList(struct Node *p){
struct Node *current=p;
do{
    printf("%d\n",current->data);
    current=current->next;
}while(current!=p);
}
void displayRecursivelyCircularLinkedList(struct Node *p){
static int flag=0;
if(p!=head || flag==0){
    flag=1;
    printf("%d\n",p->data);
    displayCircularLinkedList(p->next);
}
}
void circularInsertions(struct Node *p,int position,int data){
int count;
if(position==1){
    while(p->next!=head)
        p=p->next;
    struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=head;
    p->next=temp;
    head=temp;
    return;
}
for(count=1;count<position-1;count++)
    p=p->next;
struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
temp->data=data;
temp->next=p->next;
p->next=temp;
return;
}

int main(){
int a[]={1,4,5,6,7,8};
int b[]={3,10,11,12,14,15};
//int i;
//for(i=0;i<6;i++){
    //printf("%d\n",a[i]);}
struct Node *p=(struct Node *) malloc(sizeof(struct Node));
struct Node *q=(struct Node *) malloc(sizeof(struct Node));
createLinkedList(a,p,size);
//createLinkedList(b,q,size);
//recursiveDisplay();
//display(p);
//printf("The sum is:%d\n",recursiveAddition(head));
//printf("Max element=%d\n",recursiveMax(p));
//insert(p,4,3);
//insertAtLast(p,90);
//insertInSortedLinkedList(p,1);
//  printf("test");
//deleteElements(p,1);
//checkIfSorted(p);
//removeDuplicatesInSortedLinkedList(p);
//reverseUsingThreePointers(p);
//concatanateList(p,q);
//mergeLinkedList(q,p);
//loopCheck(p);
//displayCircularLinkedList(p);
circularInsertions(p,1,9);
displayCircularLinkedList(head);
//printf("%d\n",p->data);
return 0;
}
