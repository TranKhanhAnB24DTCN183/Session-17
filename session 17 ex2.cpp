#include <stdio.h>
#include <ctype.h>
#include <string.h>

void nhapChuoi(char* str) {
    printf("Nhap chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
}

void inChuoi(char* str) {
    printf("Chuoi ban nhap: %s\n", str);
}

int demChuCai(char* str) {
    int dem = 0;
    while (*str) {
        if (isalpha(*str)) {
            dem++;
        }
        str++;
    }
    return dem;
}

int demChuSo(char* str) {
    int dem = 0;
    while (*str) {
        if (isdigit(*str)) {
            dem++;
        }
        str++;
    }
    return dem;
}

int demKyTuDacBiet(char* str) {
    int dem = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            dem++;
        }
        str++;
    }
    return dem;
}

int main() {
    char chuoi[100];
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
        getchar();

        switch (luaChon) {
            case 1:
                nhapChuoi(chuoi);
                break;
            case 2:
                inChuoi(chuoi);
                break;
            case 3:
                printf("So luong chu cai: %d\n", demChuCai(chuoi));
                break;
            case 4:
                printf("So luong chu so: %d\n", demChuSo(chuoi));
                break;
            case 5:
                printf("So luong ky tu dac biet: %d\n", demKyTuDacBiet(chuoi));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 6);

    return 0;
}

