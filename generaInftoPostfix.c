#include<stdio.h>
struct stack{
int max;
char ch[20];
int top;
};
void push(char c,struct stack * st){
st->top=st->top+1;
st->ch[st->top]=c;
}
char pop(struct stack * st){
char ch=st->ch[st->top];
st->top=st->top-1;
return ch;
}
int innerStackPrecedence(char ch){
if(ch=='+' || ch=='-')
    return 2;
else if(ch=='*' || ch=='/')
    return 4;
else if(ch=='^')
    return 5;
else if(ch=='(')
     return 0;
else{
    return -1;
    printf("test\n");
    }
}
int outerStackPrecedence(char ch){
if(ch=='+' || ch=='-')
    return 1;
else if(ch=='*' || ch=='/')
    return 3;
else if(ch=='^')
    return 6;
else if(ch=='(')
     return 7;
else if(ch==')')
    return 0;
}
int isOperand(char a){
if(a=='+' || a=='-' || a=='*' || a=='/' || a== '^' || a=='(' || a==')')
    return 0;
else
    return 1;
}
void calculatePostfix(char infix[]){
int i=0,j=0;
struct stack st;
st.max=20;
st.top=-1;
char postfix[20];
//puts(infix);
while(infix[i]!='\0'){
    if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
    else if(outerStackPrecedence(infix[i])>innerStackPrecedence(st.ch[st.top]))
        push(infix[i++],&st);
    else if(outerStackPrecedence(infix[i])<innerStackPrecedence(st.ch[st.top]))
        postfix[j++]=pop(&st);
    else{
        pop(&st);
        i++;
    }
}
printf("Testing\n");
while(st.top>=0){
  //  printf("Testing\n");

    postfix[j++]=pop(&st);
}
postfix[j]='\0';
//printf("Testing\n");
puts(postfix);
}
int main(){
char infix[20];
printf("Enter the infix expression\n");
gets(infix);
//puts(infix);
//printf("%d\n",innerStackPrecedence(st.ch[st.top]));
calculatePostfix(infix);
return 0;
}
