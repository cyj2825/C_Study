#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int red(unsigned int num1);
int green(unsigned int num4);
int blue(unsigned int num7);

unsigned int colornum;

int main() {

	printf("RGB 색상값을 입력하세요(16진수 8자리): ");
	scanf("%x", &colornum);

	printf("RGB %x 중 RED = %x (10진수 : %d)\n", colornum, red(colornum), red(colornum));
	printf("RGB %x 중 GREEN = %x (10진수 : %d)\n", colornum, green(colornum), green(colornum));
	printf("RGB %x 중 BLUE = %x (10진수 : %d)\n", colornum, blue(colornum), blue(colornum));

	return 0;
}
int red(unsigned int num1) {
	int i, RED;
	unsigned int num2 = 0x00ff0000;
	unsigned int num3 = ((num1 & num2) >> 16);
	char a[8] = { 0 };

	for (i = 2; i < 4; i++) {
		if (a[i] >= 'A' && a[i] <= 'F') {
			num3 = num3 * 16 + a[i] - 'A' + 10;
		}
		else if (a[i] >= 'a' && a[i] <= 'f') {
			num3 = num3 * 16 + a[i] - 'a' + 10;
		}
		else if (a[i] >= '0' && a[i] <= '9') {
			num3 = num3 * 16 + a[i] - '0';
		}
	}
	RED = num3;
	return RED;
}
int green(unsigned int num4) {
	int i, GREEN;
	unsigned int num5 = 0x00000000;
	unsigned int num6 = ((num4 & num5) >> 8);
	char b[8] = { 0 };

	for (i = 4; i < 6; i++) {
		if (b[i] >= 'A' && b[i] <= 'F') {
			num6 = num6 * 16 + b[i] - 'A' + 10;
		}
		else if (b[i] >= 'a' && b[i] <= 'f') {
			num6 = num6 * 16 + b[i] - 'a' + 10;
		}
		else if (b[i] >= '0' && b[i] <= '9') {
			num6 = num6 * 16 + b[i] - '0';
		}
	}
	GREEN = num6;
	return GREEN;
}
int blue(unsigned int num7) {
	int i, BLUE;
	unsigned int num8 = 0x000000ab;
	unsigned int num9 = (num7 & num8);
	char c[8] = { 0 };

	for (i = 6; i < 8; i++) {
		if (c[i] >= 'A' && c[i] <= 'F') {
			num9 = num9 * 16 + c[i] - 'A' + 10;
		}
		else if (c[i] >= 'a' && c[i] <= 'f') {
			num9 = num9 * 16 + c[i] - 'a' + 10;
		}
		else if (c[i] >= '0' && c[i] <= '9') {
			num9 = num9 * 16 + c[i] - '0';
		}
	}
	BLUE = num9;
	return BLUE;
}