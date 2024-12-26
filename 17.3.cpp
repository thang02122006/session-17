#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    (*str)[strlen(*str) - 1] = '\0';
}

void inChuoiDaoNguoc(char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int demSoLuongTu(char *str) {
    int count = 0;
    char *token = strtok(str, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    return count;
}

void soSanhChuoi(char *str1, char *str2) {
    if (strlen(str1) > strlen(str2)) {
        printf("Chuoi ban dau dai hon chuoi so sanh.\n");
    } else if (strlen(str1) < strlen(str2)) {
        printf("Chuoi so sanh dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaTatCa(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Chuoi in hoa: %s\n", str);
}

void themChuoiVaoCu(char **str1) {
    char *str2;
    printf("Nhap vao chuoi muon them: ");
    getchar();
    fgets(str2, 100, stdin);
    str2[strlen(str2) - 1] = '\0';

    *str1 = (char *)realloc(*str1, (strlen(*str1) + strlen(str2) + 1) * sizeof(char));
    strcat(*str1, str2);
    printf("Chuoi sau khi them: %s\n", *str1);
}

int main() {
    char *chuoi = NULL;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapChuoi(&chuoi);
                break;
            case 2:
                if (chuoi != NULL) {
                    inChuoiDaoNguoc(chuoi);
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 3:
                if (chuoi != NULL) {
                    printf("So luong tu trong chuoi: %d\n", demSoLuongTu(chuoi));
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 4:
                if (chuoi != NULL) {
                    char *chuoiKhac;
                    nhapChuoi(&chuoiKhac);
                    soSanhChuoi(chuoi, chuoiKhac);
                    free(chuoiKhac);
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 5:
                if (chuoi != NULL) {
                    inHoaTatCa(chuoi);
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 6:
                if (chuoi != NULL) {
                    themChuoiVaoCu(&chuoi);
                } else {
                    printf("Ban chua nhap chuoi.\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 7);

    if (chuoi != NULL) {
        free(chuoi);
    }

    return 0;
}

