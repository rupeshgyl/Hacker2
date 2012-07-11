#include <cs50.h>
#include <stdio.h>
int
main(void)
{
int a=0,b=0,c=1,i,w=1;
while(w=1)
{
   	printf("Enter Days in the month\n");
	scanf("%d",&a);
	if((a<32)&&(a>27))
   {
	printf("No of pennies received first day\n");
	scanf("%d",&b);
	for(i=0;i<a;i++)
	{
		c=c*b;
	}
	c=c-1;
	printf("Total Money Corresponds to:\n");
	printf("%d\n",c);
	w=0;
	exit(1);
   }
	else
	{
		w=1;
	}
}
}
