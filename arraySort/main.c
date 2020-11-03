#include<stdio.h>
struct array{
int A[10];
int length;
int size;
};
void display(struct array arr){
int i;
for(i=0;i<arr.size;i++){
    printf("%d ",arr.A[i]);
}
printf("\n");
}
void mergeSortedArrays(struct array arr1,struct array arr2){
int i=0,j=0,k;
struct array a={{0,0,0,0,0,0,0,0},10,8};
for(k=0;k<(arr1.size+arr2.size);k++){
    if(arr1.A[i]<arr2.A[j] && i<4 || j>=4){
        a.A[k]=arr1.A[i];
        i++;
        }
    else{
        a.A[k]=arr2.A[j];
        j++;
    }
}
printf("The sorted merged array is:\n");
display(a);
}
int main(){
struct array arr1={{3,8,16,20},10,4};
struct array arr2={{4,10,12,22},10,4};
printf("Array 1:\n");
display(arr1);
printf("Array 2:\n");
display(arr2);
mergeSortedArrays(arr1,arr2);
return 0;
}
