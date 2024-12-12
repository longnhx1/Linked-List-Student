#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

typedef struct SinhVien {
    char msSV[20];
    char hoTen[50];
    float diemTB;
} SV;

typedef struct Node {
    SV data;
    struct Node *next;
} node;

typedef struct Node *pNode;

void nhapSV(SV &data) {
    scanf("%s", data.msSV);
    getchar();
    
    gets(data.hoTen);
    scanf("%f", &data.diemTB);
}

void xuatSV(SV data) {
    printf("%s - %s - %.2f\n", data.msSV, data.hoTen, data.diemTB);
}

void khoiTaoDS(pNode &phead) {
    phead = NULL;
}

int checkDS(pNode &phead) {
    return phead == NULL;
}

pNode taoNode(SV x) {
    pNode newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void themDau(pNode &phead, SV x) {
    pNode newNode = taoNode(x);
    newNode->next = phead;
    phead = newNode;
}

void themCuoi(pNode &phead, SV x) {
    pNode newNode = taoNode(x);
    if (checkDS(phead)) {
        phead = newNode;
        return;
    }
    pNode temp = phead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void input(pNode &phead) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        SV x;
        nhapSV(x);
        themCuoi(phead, x);
    }
}

void output(pNode phead) {
    if (checkDS(phead)) {
        return;
    }
    pNode temp = phead;
    while (temp != NULL) {
        xuatSV(temp->data);
        temp = temp->next;
    }
}


void bubbleSort(pNode &phead) {
    if (checkDS(phead)) {
        return;
    }
    pNode temp = phead;
    for (pNode i = phead; i != NULL; i = i->next)
    {
        for (pNode j = phead; j->next != NULL; j = j->next)
        {
            if (j->data.diemTB < j->next->data.diemTB)
            {
                SV temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

int main() {
    pNode phead;
    khoiTaoDS(phead);
    input(phead);
    //output(phead);
    
    bubbleSort(phead);
    output(phead);
    
    return 0;
}
