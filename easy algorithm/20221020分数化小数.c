#include<stdio.h>
int main() {
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int a, b, c;
		int d = 1;
		scanf("%d %d %d", &a, &b, &c);
		if(2<=c&&c<=1000&&2<=a&&b<=10000000){
			int m = a / b;
			printf("%d.", m);
			a %= b;
			while (d++ < c) {
				a *= 10;
				printf("%d", a / b);
				a %= b;
			}
			a *= 10;
			if ((a % b) * 10 / b >= 5) {
				printf("%d\n", a / b + 1);
			} else {
				printf("%d\n", a / b);
			}
		}
	}
	return 0;
}

