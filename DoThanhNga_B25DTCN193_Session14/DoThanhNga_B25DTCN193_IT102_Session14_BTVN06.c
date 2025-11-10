#include<stdio.h>
int timMax(int numberList[100],int size){
    int max = numberList[0]; // gia su phan tu dau tien lon nhat
	for(int i=1; i<size; i++){
	if(max<numberList[i]){
        max = numberList[i]; // cap nhat max neu tim thay phan tu lon hon
	    }
    }
	return max; // Trả về số lớn nhất
}

int main(){
    int numberList[]={3,7,6,9,1};
    int size = 5; //So phan tu cua mang
    int max = timMax(numberList,size);
    printf("Gia tri lon nhat:%d\n",max);
    return 0;
}