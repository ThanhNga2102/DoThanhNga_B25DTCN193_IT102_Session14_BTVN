#include<stdio.h>
void printfArray(int arr[],int length){
    printf("Mảng đó là:");
    for(int i=0;i<length;i++){
        printf("%d\t",arr[i]);
    }
}
int main(){
   int arr[]={3,5,8,2,9};
   int length=sizeof(arr)/sizeof(arr[0]);
   printfArray(arr,length);
  return 0;
}