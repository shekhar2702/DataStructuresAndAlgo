#include<stdio.h>
#include<stdlib.h>
int top=-1;
void push(char A[],char a){
A[++top]=a;
//printf("%d\n",top);
//printf("%c\n",A[0]);
}
int pop(char A[]){
char b=A[top];
//free(A[top]);
printf("Element popped is %c\n",b);
top--;
return b;
}
int isEmpty(){
if(top==-1)
    return 1;
return 0;
}
int main(){
char expression[20];
printf("Enter the expression\n");
scanf("%s",expression);
int i;
char stack[20];
for(i=0;expression[i]!='\0';i++){
    if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
        push(stack,expression[i]);
    else if(expression[i]==')' || expression[i]=='}' || expression[i]==']'){
        //printf("%c\n",expression[i]);
        //printf("%c\n",pop(stack));
        if(isEmpty()){
            printf("Not balanced\n");
            return 0;
            }
        else if((expression[i]==')') && (expression[i]-pop(stack)==1) || (expression[i]==']') && (expression[i]-pop(stack)==2) || (expression[i]=='}') && (expression[i]-pop(stack)==2))
        {   //printf("hello\n");
                continue;
        }
        else{
            //printf("%d\n",expression[i]-pop(stack));
            printf("testing\n");
            printf("Not balanced\n");
            return 0;
        }
        }
    else
        continue;
    }
if(isEmpty())
    printf("Balanced parenthesis\n");
else
    printf("Parenthesis not balanced\n");
}
