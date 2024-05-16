#include<stdio.h>
int main()
{
	int a=0,b=1,c,range,i;
  	printf("Enter the number of terms: ");
  	scanf("%d", &range);
	printf("the fibonacci series :%d,%d",a,b);
	c=a+b;
	for(i=2;i<range;i++)
	{
		printf(",%d",c);
		a=b;
		b=c;
		c=a+b;
	}
	return 0;
}
