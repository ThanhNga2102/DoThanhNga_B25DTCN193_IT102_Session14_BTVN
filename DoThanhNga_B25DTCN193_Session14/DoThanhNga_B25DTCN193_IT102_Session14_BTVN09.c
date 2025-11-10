#include<stdio.h>
int timUCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a; // neu a la UCLN
}
int main() {
    int x,y;
    printf("Nhap so thu nhat:");
    scanf("%d",&x);
    printf("Nhap so thu hai:");
    scanf("%d",&y);
    int ucln = timUCLN(x, y);
    printf("Uoc chung lon nhat cua %d va %d la: %d", x, y, ucln);
    return 0;
}