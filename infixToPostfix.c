#include<stdio.h>
int top=-1;
void push(char *a,char element){
a[++top]=element;
}
int pop(char *a){
if(top==-1)
    return 0;
return a[top--];
}
void display(char *a){
int i;
for(i=0;a[i]!='\0';i++)
    printf("%c ",a[i]);
}
void conversion(char *infix){
int i,j=0;
char stack[20],postfix[20];
for(i=0;infix[i]!='\0';i++){
    if(!isOperator){
        postfix[j++]=infix[i];
        continue;
    }
     if(!pop(stack)){
        push(stack,infix[i]);
        continue;
    }
    if(calculatePriority(infix[i])>calculatePriority(stack[top])){
        push(stack,infix[i]);
        continue;
    }
    while(calculatePriority(infix[i])<=calculatePriority(stack[top])  )

}
}
int main(){
char infixExp[20];
printf("Enter the infix expression\n");
gets(infixExp);
conversion(infixExp);
return 0;
}
