#include <stdio.h>
#include<stdlib.h>
void main(){
    int i;
int *p={1,2,3,4,5};
int *q=(int *) malloc(5*sizeof(int));
for(i=0;i<5;i++){
    printf("%d",*(p+i));
}
}
