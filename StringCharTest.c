#include<stdio.h>
int main(){
char s1[10];
gets(s1);
int i;
//i=printf("%d",printf("Tests"));
//printf("%d",i);
for(i=0;s1[i]!='\0';i++)
    printf("%c\n",s1[i]);
return 0;
}
