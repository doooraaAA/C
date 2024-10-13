#define _CRT_SECURE_N0_WARNINGS
#include<stdio.h>
int main() {
	int mici1, xishu1, mici2, xishu2, n,answer,a,b;
	scanf("%d %d", &mici1, &xishu1);
	n = mici1;
	int number1[101] = { 0 };
	int number2[101] = { 0 };//在数组中找系数
	while (mici1 > 0) {
		number1[mici1] = xishu1;
		scanf("%d %d", &mici1, &xishu1);		
	}
	number1[mici1] = xishu1;//输入完第一个多项式
	scanf("%d %d", &mici2, &xishu2);
	b = mici2;
	while (mici2 >0) {
		number2[mici2] = xishu2;
		scanf("%d %d", &mici2, &xishu2); 
	}
	number2[mici2] = xishu2;
	if (b>=n)
	{
		n = b;
	}
	answer = number1[n] + number2[n];
	if (n > 1 && answer != 0)
	{
		if (answer != 1 && answer != -1) {
			printf("%dx%d", answer, n);
		}
		else if (answer == -1) {
			printf("-x%d", n);
		}
		else {
			printf("x%d", n);
		}
	}
	else if (n == 1 && answer != 0) {
		if (answer != 1 && answer != -1) {
			printf("%dx", answer);
		}
		else if (answer == 1) {
			printf("x");
		}
		else {
			printf("-x");
		}
	}
		n--;
		if (n >= 0) {
			while (n > 0)
			{
				if (number1[n] != 0 || number2[n] != 0) {
					answer = number1[n] + number2[n];
					if (n != 1 && answer > 0)
					{
						if (answer != 1) {
							printf("+%dx%d", answer, n);
						}
						else {
							printf("+x%d", n);
						}
					}
					else if (n != 1 && answer < 0) {
						if (answer != -1) {
							printf("%dx%d", answer, n);
						}
						else {
							printf("-x%d", n);
						}
					}
					else if (n == 1 && answer > 0) {
						if (answer != 1) {
							printf("+%dx", answer);
						}
						else {
							printf("+x");
						}
					}
					else if (n == 1 && answer < 0) {
						if (answer != -1) {
							printf("%dx", answer);
						}
						else {
							printf("-x");
						}
					}
				}
				n--;
			}
			a = number1[0] + number2[0];
			if (a > 0) {
				printf("+%d\n", a);
			}
			else if (a < 0) {
				printf("%d\n", a);
			}
		}
		else {
			if (answer!=0) {
				printf("%d", answer);
			}
			else {
				printf("0");
			}
		}	
	return 0;
}