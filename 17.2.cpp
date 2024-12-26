#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void nhapChuoi(char **str) {
    *str = (char *)malloc(100 * sizeof(char)); 
    if (*str == NULL) {
        printf("Loi cap phat bo nho.\n");
        exit(1);
    }
    
    printf("Nhap vao chuoi: ");
    getchar();  
    fgets(*str, 100, stdin);  
}

void inChuoi(char *str) {
    printf("Chuoi ban da nhap: %s", str);
}

int demSoLuongChuCai(char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int demSoLuongChuSo(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int demSoLuongKyTuDacBiet(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && *str != ' ' && *str != '\n' && *str != '\t') {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char *chuoi = NULL;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapChuoi(&chuoi);
                break;
            case 2:
                if (chuoi != NULL) {
                    inChuoi(chuoi);
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 3:
                if (chuoi != NULL) {
                    printf("So luong chu cai trong chuoi: %d\n", demSoLuongChuCai(chuoi));
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 4:
                if (chuoi != NULL) {
                    printf("So luong chu so trong chuoi: %d\n", demSoLuongChuSo(chuoi));
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 5:
                if (chuoi != NULL) {
                    printf("So luong ky tu dac biet trong chuoi: %d\n", demSoLuongKyTuDacBiet(chuoi));
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 6);

    if (chuoi != NULL) {
        free(chuoi);
    }

    return 0;
}

