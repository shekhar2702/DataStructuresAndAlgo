#include<stdio.h>
#include<stdlib.h>
struct arr{
int *A;
int length;
int size;
};
void display(struct arr array){
int i;
for(i=0;i<array.size;i++)
    printf("%d\n",array.A[i]);
}
void insert(struct arr *array,int position,int num){
int i;
for(i=array->size;i>=position;i--){
    array->A[i]=array->A[i-1];
}
array->A[i]=num;
printf("The modified array after insertion is:\n");
array->size+=1;
display(*array);
}

void del(struct arr *array,int position){
int i;
printf("before deletion\n");
display(*array);
for(i=position-1;i<array->size-1;i++)
    array->A[i]=array->A[i+1];
array->size-=1;
printf("After deletion the array is:\n");
display(*array);
}
int main(){
struct arr array;
int i;
printf("Enter max length\n");
scanf("%d",&array.length);
printf("Enter the size of the array\n");
scanf("%d",&array.size);
array.A=(int *)malloc(array.length*sizeof(int));
printf("Enter the elements of the array\n");
for(i=0;i<array.size;i++)
    scanf("%d",&array.A[i]);
display(array);
int pos,num;
printf("Enter the position at which you want to insert and then the number\n");
scanf("%d%d",&pos,&num);
insert(&array,pos,num);
int delPos;
printf("Enter the position to be deleted");
scanf("%d",&delPos);
del(&array,delPos);
return 0;
}
