#include<stdio.h>
long long tinhGiaiThua(int n) {
    long long gt = 1;
    for (int i = 1; i <= n; i++)
        gt *= i;
    return gt;
}
int main (){
    int n = 35;
    printf("Nhap n: ");
    scanf("%d", &n);
// Tinh giai thua n!
    printf("%d! = %lld\n", n, tinhGiaiThua(n));
    return 0;
}