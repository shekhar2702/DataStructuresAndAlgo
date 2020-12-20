#include<stdio.h>

void insert(int arr[],int num){
int temp=arr[num];
int i=num;
while(i>1 && arr[i/2]<temp){
    arr[i]=arr[i/2];
    i/=2;
}
arr[i]=temp;
}
void display(int arr[],char operation[]){
    printf("After %s ",operation);
    printf("array is:-");
    int i;
for(i=1;i<=7;i++){
    printf("%d\n",arr[i]);
}
}
void deletion(int arr[],int num){
int deleted=arr[1],i=1,j=2*i;
arr[1]=arr[num];
arr[num]=deleted;
while(j<num-1){
    if(arr[j]<arr[j+1])
        j++;
    if(arr[i]<arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i=j;
        j=2*j;
    }
    else{
        break;
    }
}
}

int main(){
int arr[]={0,10,20,30,25,5,40,35};
int i;
for(i=2;i<=7;i++){
    insert(arr,i);
}
display(arr,"insertion");
for(i=7;i>1;i--)
    deletion(arr,i);
    //deletion(arr,6);
    //deletion(arr,5);
    //deletion(arr,4);
    //deletion(arr,3);
    //deletion(arr,2);
display(arr,"deletion");
}
