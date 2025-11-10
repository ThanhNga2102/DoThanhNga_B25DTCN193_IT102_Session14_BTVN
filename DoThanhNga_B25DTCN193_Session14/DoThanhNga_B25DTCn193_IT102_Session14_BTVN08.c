#include<stdio.h>
int kiemTraHoanHao(int n) {
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
        return 1; 
    return 0;
}
int main (){
    int a,b;
    printf("Nhap so thu nhat:");
    scanf("%d",&a);
    printf("Nhap so thu hai:");
    scanf("%d",&b);
    // Kiem tra so hoan hao
    if (kiemTraHoanHao(a)==1)
        printf("%d la so hoan hao\n",a);
    else
        printf("%d khong phai so hoan hao\n",a);
    if (kiemTraHoanHao(b)==1)
        printf("%d la so hoan hao\n",b);
    else
        printf("%d khong phai so hoan hao\n",b);
    return 0;
}