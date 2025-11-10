#include <stdio.h>

int kiemTraSoNguyenTo(int n) {
    if (n < 2)
    return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
        return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap mot so: ");
    scanf("%d", &n);

    if (kiemTraSoNguyenTo(n) == 1)
        printf("So %d la so nguyen to", n);
    else
        printf("So %d khong phai la so nguyen to", n);

    return 0;
}
