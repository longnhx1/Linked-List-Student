#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct SV {
    char maSo[20];
    char hoTen[50];
    float diemTB;
} SinhVien;

typedef struct node {
    SinhVien info;
    struct node *next;
} Node;

typedef struct node *pNode;

// ham de nhap 1 sinh vien
void nhapSV(SV &svMoi) {
    scanf("%s", svMoi.maSo);
    getchar();

    gets(svMoi.hoTen);

    scanf("%f", &svMoi.diemTB);
}

// ham de xuat 1 sinh vien
void xuatSV(SV sv) {
    printf("%s - %s - %.2f\n", sv.maSo, sv.hoTen, sv.diemTB);
}

// ham de khoi tao danh sach rong
void khoiTaoDS(pNode &phead) {
    phead = NULL;
}

// ham de kiem tra danh sach rong
int checkDS(pNode &phead) {
    return phead == NULL;
}

// ham de tao node sinh vien
pNode taoNodeSV(SV data) {
    pNode newSinhVien = new node;
    newSinhVien->info = data;
    newSinhVien->next = NULL;
    return newSinhVien;
}

// ham de them sinh vien vao dau danh sach
void themDau(pNode &phead, SV data) {
    if(checkDS(phead)) {
        phead = taoNodeSV(data);
        return;
    }
    pNode newSinhVien = taoNodeSV(data);
    newSinhVien->next = phead;
    phead = newSinhVien;
}

void themCuoi(pNode &phead, SV data) {
    if (checkDS(phead)) {
        phead = taoNodeSV(data);
        return;
    }
    pNode newSinhVien = taoNodeSV(data);
    pNode temp = phead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newSinhVien;
}

// ham nhap danh sach sinh vien
void nhapDS(pNode &phead) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        SV svMoi;
        nhapSV(svMoi);
        themCuoi(phead, svMoi);
    }
}

// ham xuat danh sach sinh vien
void xuatDS(pNode phead) {
    if (checkDS(phead)) {
        printf("Danh sach rong\n");
        return;
    }
    pNode temp = phead;
    while (temp != NULL) {
        xuatSV(temp->info);
        temp = temp->next;
    }
}


int main() {
    pNode phead;
    khoiTaoDS(phead);
    nhapDS(phead);
    xuatDS(phead);
    return 0;
}