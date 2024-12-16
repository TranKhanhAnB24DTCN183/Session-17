#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char* str) {
    printf("Nhap chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
}

void inChuoiDaoNguoc(char* str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", *(str + i));
    }
    printf("\n");
}

int demSoTu(char* str) {
    int dem = 0;
    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            dem++;
        }
        str++;
    }
    return dem + 1; 
}

void soSanhChuoi(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2) {
        printf("Chuoi 2 ngan hon chuoi 1.\n");
    } else if (len1 > len2) {
        printf("Chuoi 2 dai hon chuoi 1.\n");
    } else {
        printf("Hai chuoi co do dai ngang nhau.\n");
    }
}

void inHoaChuoi(char* str) {
    while (*str) {
        printf("%c", toupper(*str));
        str++;
    }
    printf("\n");
}

void themChuoiVaoCuoi(char* str1) {
    char str2[100];
    printf("Nhap chuoi muon them: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;
    strcat(str1, str2);
}

int main() {
    char chuoi[200];
    char chuoiKhac[100];
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. So sanh chuoi voi chuoi khac\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Them chuoi khac vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar(); 

        switch (luaChon) {
            case 1:
                nhapChuoi(chuoi);
                break;
            case 2:
                inChuoiDaoNguoc(chuoi);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", demSoTu(chuoi));
                break;
            case 4:
                nhapChuoi(chuoiKhac);
                soSanhChuoi(chuoi, chuoiKhac);
                break;
            case 5:
                inHoaChuoi(chuoi);
                break;
            case 6:
                themChuoiVaoCuoi(chuoi);
                printf("Chuoi sau khi them: %s\n", chuoi);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 7);

    return 0;
}

