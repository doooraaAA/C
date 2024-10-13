#include<stdio.h>
int main() {
	int a,b,c;
	scanf("%d/%d", &a, &b);
	if (10 <= a && a < b && b < 100) {
		printf("0.");
		for (int i = 0; i < 200; i++) {
			a = (a % b) * 10;
			c=a/b;
			if(c==0&&a%b==0){
				break;
			}
			else{
				printf("%d", c);
			}
			
		}
		printf("\n");
		
	}
	return 0;
}

