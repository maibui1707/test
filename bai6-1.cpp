  // bai6-1.cpp
#include <stdio.h>
#include <stdlib.h>
// ham tim uoc so chung lon nhat cua hai so
int uscln(int a, int b) {
	while ((a != 0) && (b != 0)) {
		if (a > b) a = a % b;
		else b = a % b;
	}
	if (a == 0) return b;
	else return a;
}
// ham tinh a2 + b2
int tong(int a, int b) {
	return a*a + b*b;
}
// ham main
int main() {
	int a, b;
	FILE *f1, *f2;
	f1 = fopen("NUMBER.INP","r");
	if (f1 == NULL) {
		printf("Khong mo duoc file NUMBER.INP !");
		return 0;
	}
	f2 = fopen("NUMBER.OUT","w");
 	if (f2 == NULL) {
		printf("Khong mo duoc file NUMBER.OUT !");
		return 0;
	}
	// doc du lieu tu file f1
	fscanf(f1,"%d%d", &a, &b);
	// ghi du lieu vao file f2
	fprintf(f2,"%d\n", uscln(a, b));
	fprintf(f2,"%d", tong(a, b));
	// dong files
	fclose(f1);
	fclose(f2);
	printf("Chuong trinh da chay xong !");
	return 0;
}
