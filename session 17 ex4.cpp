#include <stdio.h>
#include <stdbool.h>

void nhapMang(int* arr, int* n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inSoChan(int* arr, int n) {
    printf("Cac phan tu chan trong mang: ");
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

bool kiemTraSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void inSoNguyenTo(int* arr, int n) {
    printf("Cac phan tu la so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (kiemTraSoNguyenTo(*(arr + i))) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

void daoMang(int* arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - 1 - i);
        *(arr + n - 1 - i) = temp;
    }
    printf("Mang sau khi dao nguoc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void sapXepMang(int* arr, int n, bool tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tangDan) {
                if (*(arr + i) > *(arr + j)) {
                    int temp = *(arr + i);
                    *(arr + i) = *(arr + j);
                    *(arr + j) = temp;
                }
            } else {
                if (*(arr + i) < *(arr + j)) {
                    int temp = *(arr + i);
                    *(arr + i) = *(arr + j);
                    *(arr + j) = temp;
                }
            }
        }
    }
}

void sapXepMenuCon(int* arr, int n) {
    int luaChon;
    do {
        printf("\n1. Tang dan\n");
        printf("2. Giam dan\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                sapXepMang(arr, n, true);
                printf("Mang sau khi sap xep tang dan: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", *(arr + i));
                }
                printf("\n");
                break;
            case 2:
                sapXepMang(arr, n, false);
                printf("Mang sau khi sap xep giam dan: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", *(arr + i));
                }
                printf("\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 1 && luaChon != 2);
}

void timKiemPhanTu(int* arr, int n, int phanTu) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == phanTu) {
            printf("Phan tu %d da duoc tim thay o vi tri %d.\n", phanTu, i);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Phan tu %d khong ton tai trong mang.\n", phanTu);
    }
}

int main() {
    int n, luaChon;
    int arr[100];
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inSoChan(arr, n);
                break;
            case 3:
                inSoNguyenTo(arr, n);
                break;
            case 4:
                daoMang(arr, n);
                break;
            case 5:
                sapXepMenuCon(arr, n);
                break;
            case 6:
                {
                    int phanTu;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &phanTu);
                    timKiemPhanTu(arr, n, phanTu);
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le");
    }
    } while (luaChon != 7);

    return 0;
}
