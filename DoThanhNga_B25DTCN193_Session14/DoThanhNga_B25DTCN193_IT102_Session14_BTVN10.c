#include <stdio.h>
#define MAX 100

// 1. Nhập mảng
void nhapMang(int a[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);

    if(*n > MAX) {
        printf("So phan tu vuot qua gioi han!\n");
        *n = 0;
        return;
    }

    if(*n < 0) {
        printf("So phan tu khong hop le!\n"); 
        *n = 0;
        return;
    }

    for(int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// 2. In mảng
void inMang(int a[], int n) {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }

    printf("Cac phan tu: ");
    for(int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

// 3. Thêm phần tử
void themPhanTu(int a[], int *n, int x, int pos) {
    if (*n >= MAX) {
        printf("Mang day, khong the them!\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for(int i = *n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = x;
    (*n)++;

    printf("Da them!\n");
}

// 4. Sửa phần tử
void suaPhanTu(int a[], int n, int pos, int x) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    a[pos] = x;
    printf("Da sua!\n");
}

// 5. Xóa phần tử
void xoaPhanTu(int a[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for(int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;

    printf("Da xoa!\n");
}

// 6a. Sắp xếp tăng
void sapXepTang(int a[], int n) {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    printf("Da sap xep tang dan!\n");
}

// 6b. Sắp xếp giảm
void sapXepGiam(int a[], int n) {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] < a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    printf("Da sap xep giam dan!\n");
}

// 7a. Tìm kiếm tuyến tính
int timKiemTuyenTinh(int a[], int n, int x) {
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            return i;
    return -1;
}

// 7b. Tìm kiếm nhị phân
int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == x)
            return mid;
        if(a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int a[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap gia tri mang\n");
        printf("2. In mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Sap xep\n");
        printf("7. Tim kiem\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                nhapMang(a, &n);
                break;

            case 2:
                inMang(a, n);
                break;

            case 3: {
                int x, pos;
                printf("Nhap vi tri can chen (0 -> %d): ", n);
                scanf("%d", &pos);
                printf("Nhap gia tri can chen: ");
                scanf("%d", &x);
                themPhanTu(a, &n, x, pos);
                break;
            }

            case 4: {
                int pos, x;
                printf("Nhap vi tri can sua (0 -> %d): ", n - 1);
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &x);
                suaPhanTu(a, n, pos, x);
                break;
            }

            case 5: {
                int pos;
                printf("Nhap vi tri can xoa (0 -> %d): ", n - 1);
                scanf("%d", &pos);
                xoaPhanTu(a, &n, pos);
                break;
            }

            case 6: {
                int c;
                printf("1. Giam dan\n2. Tang dan\nChon: ");
                scanf("%d", &c);
                if(c == 1)
                    sapXepGiam(a, n);
                else if(c == 2)
                    sapXepTang(a, n);
                else
                    printf("Lua chon khong hop le!\n");
                break;
            }

            case 7: {
                int c, x;
                printf("1. Tuyen tinh\n2. Nhi phan\nChon: ");
                scanf("%d", &c);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);

                if(c == 1) {
                    int vt = timKiemTuyenTinh(a, n, x);
                    if(vt == -1) printf("Khong tim thay!\n");
                    else printf("Tim thay tai vi tri %d\n", vt);
                } else if(c == 2) {
                    sapXepTang(a, n); // sắp xếp trước khi tìm nhị phân
                    int vt = timKiemNhiPhan(a, n, x);
                    if(vt == -1) printf("Khong tim thay!\n");
                    else printf("Tim thay tai vi tri %d\n", vt);
                } else
                    printf("Lua chon khong hop le!\n");

                break;
            }

            case 8:
                printf("Thoat chuong trinh...\n");
                break;

            default:
                printf("Nhap sai, nhap lai!\n");
        }

    } while(choice != 8);

    return 0;
}
