#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int
main()
{
	int key,i,l;
	int asci[44];
	string mg;
	string temp;
	temp=(char*)malloc(100);
	mg=(char*)malloc(256);
	printf("Enter the rotation key\n");
	gets(temp);
	key=atoi(temp);
	printf("Enter the message to Encript\n");
	gets(mg);
	l=strlen(mg);
	for(i=0;i<l;i++)
	{	
		asci[i]=(int) mg[i];
		if((asci[i]>64)&&(asci[i]<91))
		{
			asci[i]=key+asci[i];
			
			if(asci[i]>90)
			{
				asci[i]=(asci[i]%90)+64;
			}	
			
		}
		else if((asci[i]>96)&&(asci[i]<123))
		{
			asci[i]=key+asci[i];
			if(asci[i]>122)
			{
				asci[i]=(asci[i]%122)+96;
			}	
			
				
		}	

		printf("%c",(char) asci[i]);
	        
	
	}
	printf("\n");
	
}
	
	

