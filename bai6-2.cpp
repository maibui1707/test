// bai6-2.cpp
#include <stdio.h>
#include <stdlib.h>
// ham main
int main() {
	int chucai = 0, chuso = 0, ktdb = 0;
	char ch;
	FILE *f1, *f2;
	f1 = fopen("NEWS.INP","r");
	if (f1 == NULL) {
		printf("Khong mo duoc file NEWS.INP !");
		return 0;
	}
	f2 = fopen("NEWS.OUT","w");
	if (f2 == NULL) {
		printf("Khong mo duoc file NEWS.OUT !");
		return 0;
	}
	// doc tung ki tu tu file f1
	while (!feof(f1)) {
		ch = fgetc(f1);
		if ((ch >= 97) && (ch <= 122)) chucai++;
		else 
			if ((ch >= 48) && (ch <= 57)) chuso++;
				else 
					if (ch != '\n')ktdb++;
	}
	fprintf(f2,"%d%6d%6d",chucai, chuso, ktdb - 1);
	// dong files
	fclose(f1);
	fclose(f2);
	printf("Chuong trinh da chay xong !");
	return 0;
}
