#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c,d;
		int e=0;
		scanf("%d %d %d", &a, &b, &c);
		for (d = 10; d <= 100; d++) {
			if (d % 3 == a && d % 5 == b && d % 7 == c) {
				printf("%d\n", d);
				e=1;
				break;
			}

		}
		if(e!=1){
		printf("Impossible");	//TODO
		}
		
		}
	
	return 0;
}
