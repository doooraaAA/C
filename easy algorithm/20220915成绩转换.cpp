#include <stdio.h>
int main()
{
	int x=0;
	scanf("%d",&x);
	switch(x/10)  //�õ�ʮλ�����зֶ� 
	{
		case 9:
			printf("A");
			break;
		case 8:
			printf("B");
			break;
		case 7:
			printf("C");
			break;
		case 6:
			printf("D");
			break;
		default:
			printf("E");
		
		
	}
	
	
	return 0;
} 
