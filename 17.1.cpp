#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu mang: ");
    scanf("%d", n);

    *arr = (int *)malloc(*n * sizeof(int));

    if (*arr == NULL) {
        printf("Loi cap phat bo nho.\n");
        exit(1);
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void hienThiMang(int *arr, int n) {
    printf("Cac phan tu trong mang la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int tinhDoDaiMang(int n) {
    return n;
}

int tinhTong(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}

int timMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int *arr = NULL;
    int n = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                if (arr != NULL) {
                    hienThiMang(arr, n);
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 3:
                if (arr != NULL) {
                    printf("Do dai mang: %d\n", tinhDoDaiMang(n));
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 4:
                if (arr != NULL) {
                    printf("Tong cac phan tu trong mang: %d\n", tinhTong(arr, n));
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 5:
                if (arr != NULL) {
                    printf("Phan tu lon nhat trong mang: %d\n", timMax(arr, n));
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 6);

    if (arr != NULL) {
        free(arr);
    }

    return 0;
}

