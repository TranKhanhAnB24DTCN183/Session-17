#include <stdio.h>
#include <stdlib.h>

void nhapMang(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", (arr + i));
    }
}

void hienThiMang(int* arr, int size) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int tinhTong(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int timMax(int* arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int* arr = NULL;
    int size = 0;
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
            case 1: {
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &size);
                if (size <= 0) {
                    printf("So phan tu khong hop le!\n");
                    size = 0;
                    break;
                }
                arr = (int*)malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Khong du bo nho cap phat!\n");
                    size = 0;
                    break;
                }
                nhapMang(arr, size);
                break;
            }
            case 2:
                if (size == 0 || arr == NULL) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    hienThiMang(arr, size);
                }
                break;
            case 3:
                printf("Do dai cua mang la: %d\n", size);
                break;
            case 4:
                if (size == 0 || arr == NULL) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    int tong = tinhTong(arr, size);
                    printf("Tong cac phan tu trong mang la: %d\n", tong);
                }
                break;
            case 5:
                if (size == 0 || arr == NULL) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    int max = timMax(arr, size);
                    printf("Phan tu lon nhat trong mang la: %d\n", max);
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

