#include<stdio.h>

void bubbleSort(int arr[],int n){
int i,j;
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
}
void display(int arr[],int n){
int i;
for(i=0;i<n;i++){
    printf("%d \n",arr[i]);
}
}

int main(){
int arr[] = {4,1,9,7,10,5};
printf("Array elements before sorting are:-\n");
display(arr,6);
bubbleSort(arr,6);
printf("Sorted elements are:-\n");
display(arr,6);
}
