#include<stdio.h>
struct array{
int A[10];
int length;
int size;
};
void swap(int *a,int *b){
int c;
c=*a;
*a=*b;
*b=c;
}
void display(struct array arr){
int i;
for(i=0;i<arr.size;i++)
    printf("%d",arr.A[i]);
printf("\n");
}
void reverse(struct array *arr){
int i,b[arr->size];
for(i=0;i<arr->size;i++)
    b[i]=arr->A[arr->size-i-1];
for(i=0;i<arr->size;i++)
    arr->A[i]=b[i];
printf("done reversing");
}
void leftShift(struct array *arr){
int i,n=arr->A[0];
for(i=0;i<arr->size-1;i++){
    arr->A[i]=arr->A[i+1];
}
arr->A[i]=n;
printf("After left shift:\n");
display(*arr);
}
int main(){
struct array arr={{7,2,3,4},7,4};
printf("Before reversing:\n");
display(arr);
reverse(&arr);
printf("After reversing:\n");
display(arr);
leftShift(&arr);
return 0;
}
