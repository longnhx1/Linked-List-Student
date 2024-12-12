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
        
        temp = temp->next;
    }
}

void timMSSV(pNode phead, char x[]) {
	if (checkDS(phead)) return;
	bool result = false;
	pNode temp = phead;
	while(temp != NULL) {
		if (strcmp(temp->data.msSV, x) == 0){
			xuatSV(temp->data);
			result = true;
		} 
		temp = temp->next;
	}
	if (result == false) printf("Not Found");
}

int main() {
    pNode phead;
    khoiTaoDS(phead);
    input(phead);
    char x[100];
    scanf("%s", x);
    timMSSV(phead, x);
    return 0;
}
