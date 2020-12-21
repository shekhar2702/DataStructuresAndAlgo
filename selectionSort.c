#include<stdio.h>

void selectionSort(int arr[],int n){
int i,j,p;
for(i=0;i<n;i++){
    p=i;
    for(j=i;j<n;j++){
        if(arr[j]<arr[p])
            p=j;
    }
    int temp = arr[i];
    arr[i]=arr[p];
    arr[p]= temp;
}
}

void display(int arr[],int n){
int i;
for(i=0;i<n;i++){
 printf("%d\n",arr[i]);
}
}

int main(){
int arr[]={20,40,10,30,70,90,80};
printf("Elements before sorting\n");
display(arr,7);
printf("Elements after sorting\n");
selectionSort(arr,7);
display(arr,7);
}
