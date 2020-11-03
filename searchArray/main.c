#include<stdio.h>
struct array{
int A[10];
int length;
int size;
};
void linearSearch(struct array arr,int num){
int count=0,i;
for(i=0;i<arr.size;i++){
    if(arr.A[i]==num){
        count=1;
        break;
    }
    }
if(count==1)
    printf("Element found");
 else
        printf("Not found");
}
void binarySearch(struct array arr,int num){
int low=0,high=arr.size-1,mid=arr.size/2,count=0;
while(low<=high){
    if(num==arr.A[mid]){
        count=1;
        break;
    }
    if(num>arr.A[mid]){
        low=mid+1;
        mid=(low+high)/2;
    }
    else{
        high=mid-1;
        mid=(low+high)/2;
    }
}
if(count==1)
    printf("Found");
else
    printf("Not found");
}
void main(){
struct array arr={{0,2,3,4,5},7,5};
int num,i;
printf("Enter the number to be searched\n");
scanf("%d",&num);
binarySearch(arr,num);
}
