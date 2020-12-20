#include<stdio.h>

void insertionSort(int a[],int num){
int i,j,hole;
for(i=1;i<num;i++){
    hole=a[i];
    j=i-1;
    while(hole<a[j] && j>=0){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=hole;
}
}

void display(int a[],int num){
int i;
for(i=0;i<num;i++){
    printf("%d\n",a[i]);
}
}

int main(){
int arr[]={5,7,1,9,17,14,40,27};
printf("Array elements before sorting:-\n");
display(arr,8);
insertionSort(arr,8);
printf("Array elements after sorting:-\n");
display(arr,8);
}
