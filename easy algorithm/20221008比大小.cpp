#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);  // 有n组数据
    for (i = 0; i < n; i++) {
        int a, b, c, d;
		int i;
        scanf("%d %d %d %d",&a,&b,&c,&d);// 读入4个整数，对这4个整数排序，并输出结果
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

        printf("%d %d %d %d\n",a,b,c,d);// 请将排序代码写在这里，不能使用循环语句
    }

    return 0;
}
