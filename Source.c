#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned char check_digit(char*);

int main(void) {
	char id[9];
	unsigned char cd, c; // cd: check digit, c: the char from user input
	printf_s(
"== 身份證號碼驗證程式 ==\n\
請輸入身份證號碼首八個字元：");
	gets_s(id, 9);
	printf_s("請輸入身份證號碼最後一個字元（括號內數字或字元）：");
	c = getchar();
	cd = check_digit(id);
	if (c == cd) {
		printf_s("身份證號碼正確！\n");
	}
	else {
		printf_s("身份證號嗎不正確！\n");
		printf_s("檢驗位為：%c\n", cd);
	}
	system("PAUSE");
	return 0;
}

unsigned char check_digit(char* id) {
	// Return the check digit of the HKID in int.
	auto int sum = 0, i, j, rem; // rem: remainder
	if (strlen(id) != 8) {
		// HKID with one alphabet prefixed
		sum += 36 * 9;
		i = 8;
	}
	else {
		i = 9;
	}
	for (i, j = 0; i >= 2; i--, j++) {
		if (isalpha(*(id + j))) {
			sum += (toupper(*(id + j)) - 55) * i;
		}
		else {
			sum += (*(id + j) - 48) * i;
		}
	}
	rem = sum % 11;
	if (rem == 0) {
		return '0';
	}
	else if (rem == 1) {
		return 'A';
	}
	else {
		return 11 - rem + '0';
	}
	/*for (i; i >= 2; i--) {
		if (isalpha(*(id - (i - 9)))) {
			sum += (toupper(*(id - (i - 9))) - 55) * i;
		}
		else {
			sum += (*(id - (i - 9)) - 48) * i;
		}
	}*/
}