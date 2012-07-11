#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int
main()
{
	string mg,key;
	int asci[44],as2[20],as3[20];
	int i,l,l1,k=0;
	mg=(char*)malloc(256);
	key=(char*)malloc(256);
	printf("Enter the keyword\n");
	gets(key);
	printf("Enter the message to Encript\n");
	gets (mg);
	l=strlen(key);
	l1=strlen(mg);
	if(l<l1)
	{
		for(i=0;i<(l1-l);i++)
		{
			key[l+i]=key[i];	
		}
	}
	for(i=0;i<l1;i++)
	{
		asci[i]=(int) key[i];
		if((asci[i]>64)&&(asci[i]<91))
		{
			asci[i]=asci[i]-65;
		}
		else
		{
			asci[i]=asci[i]-97;
		}

	}
	printf("Your Encripted output is:");
	for(i=0;i<l1;i++)
	{
		if(k==1)
		{
			as2[i]=(int) mg[i];
			if((as2[i]>64)&&(as2[i]<91))
			{
				as3[i]=asci[i-1]+as2[i];
				
				if(as3[i]>90)
				{
					as3[i]=(as3[i]-90)+65;
					
				}
				
			}
		
			else if((as2[i]>96)&&(as2[i]<123))
			{
				as3[i]=asci[i-1]+as2[i];
				
				if(as3[i]>122)
				{
					as3[i]=(as3[i]-122)+97;
					
				}
			}
			else 
			{
				as3[i]=as2[i];
			}
		}
		else
		{	
			as2[i]=(int) mg[i];
			if((as2[i]>64)&&(as2[i]<91))
			{
				as3[i]=asci[i]+as2[i];
				if(as3[i]>90)
				{
					as3[i]=(as3[i]-90)+65;
				}
			}
		
			else if((as2[i]>96)&&(as2[i]<123))
			{
				as3[i]=asci[i]+as2[i];
				if(as3[i]>122)
				{
					as3[i]=(as3[i]-122)+97;
				}
			}
			else 
			{
				as3[i]=as2[i];
				k=1;
			}
		}
		printf("%c",(char) as3[i]);
	}
	printf("\n");
}
