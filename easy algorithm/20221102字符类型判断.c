#include <stdio.h>
int main()
{
	int n;
	char a;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%c",&a);
		a=getchar();
		if(a>='0'&&a<='9')
		{
			printf("number\n");
		}
		else if((a>='a'&&a<='z')||(a<='Z'&&a>='A'))
		{
			printf("letter\n");
		}
		else
		{
			printf("else\n");
		}
	}
	return 0;
}


