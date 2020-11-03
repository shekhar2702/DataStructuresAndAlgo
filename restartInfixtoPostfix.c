#include<stdio.h>
#include<stdlib.h>
struct stack{
int max;
char ch[20];
int top;
};
void push(char element,char *st,int *top){
*top=*top+1;
st[*top]=element;
}
char pop(struct stack *st){
if(st->top==-1)
    return -1;
char ch=st->ch[st->top];
st->top-=1;
return ch;
}
void display(char postfix[]){
    printf("Testing\n");
puts(postfix);
}
int isOperand(char a){
if(a=='+' || a=='-' || a=='*' || a=='/')
    return 0;
else
    return 1;
}
int precedenceCheck(char a){
if(a=='+' || a=='-')
    return 1;
else if(a=='*' || a=='/')
    return 2;
return 0;
}
void convert(struct stack *st,char infix[]){
int i=0,j=0;
char postfix[20];
while(infix[i]!='\0'){
    if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
    else if(precedenceCheck(infix[i])>precedenceCheck(st->ch[st->top]))
        push(infix[i++],st->ch,&st->top);
    else
        postfix[j++]=pop(st);
}
//printf("Testing");
while(st->top>=0)
    postfix[j++]=pop(st);
   postfix[j]='\0';
display(postfix);
}

int main(){
struct stack st;
st.top=-1;
st.max=10;
char a[10];
printf("Enter the infix expression\n");
gets(a);
//puts(a);
convert(&st,a);
return 0;
}
