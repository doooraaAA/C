#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);  // ��n������
    for (i = 0; i < n; i++) {
        int a, b, c, d;
		int i;
        scanf("%d %d %d %d",&a,&b,&c,&d);// ����4������������4���������򣬲�������
		if(a>b){
			i=a;
			a=b;
			b=i;
		}
		if(a>c){
		i=a;
		a=c;
		c=i;	
		}
		if(a>d){
			i=a;
			a=d;
			d=i;
		}
		if(b>c){
			i=b;
			b=c;
			c=i;
		}
		if(b>d){
			i=b;
			b=d;
			d=i;
		}
		if(c>d){
			i=c;
			c=d;
			d=i;
		}

        printf("%d %d %d %d\n",a,b,c,d);// �뽫�������д���������ʹ��ѭ�����
    }

    return 0;
}
