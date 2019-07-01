// bai6-3.cpp
#include <stdio.h>
#include <stdlib.h>
struct tree{
	int id;
	float h;
};
// khai bao cac ham

void nhapdulieu(FILE *f, struct tree *T, int n);
void doicho(struct tree *a, struct tree *b);
void sapxep(struct tree *T, int n);
void ghiketqua(FILE *f, struct tree *T, int n);

// ham main
int main() {
	struct tree *T;
	int n, i;
	FILE *f1, *f2;
	f1 = fopen("TREE.INP","r");
	if (f1 == NULL) {
		printf("Khong mo duoc file TREE.INP !");
		return 0;
	}
	f2 = fopen("TREE.OUT","w");
	if (f2 == NULL) {
		printf("Khong mo duoc file TREE.OUT !");
		return 0;
	}
	// doc du lieu tu file f1
	fscanf(f1,"%d", &n); // doc dong dau tien
	// cap pha vung nho cho con tro T
	T = (tree *) malloc(n * sizeof(tree));
	nhapdulieu(f1, T, n);
	// sap xep theo chieu cao
	sapxep(T, n);
	// ghi du lieu ra file f2
	ghiketqua(f2, T, n);
	// dong file
	fclose(f1);
	fclose(f2);
	printf("Chuong trinh da chay xong !");	
	return 0;
}

// doi cho gia tri hai bien
void doicho(struct tree *a, struct tree *b) {
	struct tree tg;
	tg = *a;
	*a = *b;
	*b = tg;
}
// sap xep cac phan tu theo chieu tang dan cua chieu cao
void sapxep(struct tree *T, int n) {
	int i, j;
	for (i = 0; i < n-1; i++) 
		for (j = i + 1; j < n; j++) {
			if ((T+i)->h > (T+j)->h) doicho(T+i, T+j);
		}
}
// doc du lieu tu file f
void nhapdulieu(FILE *f, struct tree *T, int n) {
	int i;
	float x;
	for (i = 0; i < n; i++) {
		fscanf(f,"%f", &x);
		(T+i)->id = i + 1;
		(T+i)->h = x;
	}	
}
//ghi ket qua ra file
void ghiketqua(FILE *f, struct tree *T, int n) {
	int i;
	// ghi dong thu nhat
	for (i = 0; i < n; i++) {
		fprintf(f, "%5d", (T+i)->id);
	}
	// ghi dong thu hai
	fprintf(f,"\n");
	for (i = 0; i < n; i++) {
		fprintf(f, "%6.2f", (T+i)->h);
	}
}
