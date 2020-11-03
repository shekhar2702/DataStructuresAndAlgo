#include<stdio.h>
#include<stdlib.h>
struct stack{
int top;
int size;
int *s;
};
void createStack(struct stack *p){
p->top=-1;
printf("Enter the size of the stack\n");
scanf("%d",&p->size);
p->s=(int *) malloc(p->size*sizeof(int));
}
void display(struct stack *st){
int i;
if(st->top==-1){
    printf("Memory Underflow\n");
    return;
}
else{
int i;
for(i=st->top;i>=0;i--)
    printf("%d\n",st->s[i]);
}
}
void push(struct stack *s,int element){
if(s->top==s->size-1)
    {
        printf("Element full and hence no more element can be inserted\n");
        return;
    }
s->top++;
s->s[s->top]=element;
}
void pop(struct stack *p){
if(p->top==-1){
    printf("Memory underflow\n");
    return;
}
printf("Element popped is %d\n",p->s[p->top]);
free(p->s[p->top]);
p->top--;
}
void peek(struct stack *p,int position){
int counter=p->top;
position=p->top+1-position;
int i;
    printf("Peeked elements is %d\n",p->s[position]);
 }
int main(){
struct stack st;
createStack(&st);
//printf("Enter element to push\n");
//scanf("%d",&elem);
push(&st,1);
//peek(&st,1);
pop(&st);
//pop(&st);
//pop(&st);
//pop(&st);
//pop(&st);
//pop(&st);
//pop(&st);
//display(&st);
//peek(&st,1);
return 0;
}
