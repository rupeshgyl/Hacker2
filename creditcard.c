#include <cs50.h>
#include <stdio.h>
#include <time.h>

/* Code you want timed here */


int
main(void)
{
	clock_t start = clock();
	int f[8],s[12],t[15],i=0,q=1,j,st=0,se[7],k=7,ex,total=0,ans;
	long long int cardno;
		while(q=1)
		{	
		printf("Enter Your Card Number\n");
		scanf("%lluLL", &cardno);
		if((cardno>99999999999999)&&(cardno<10000000000000000))
		{
			while(cardno!=0)
			{
				t[i]=cardno%10;
				cardno=cardno/10;
				i++;
			}
		
			for(i=0,j=0;i<14,j<8;i++)
			{
				f[j]=t[i];
				i++;
				j++;
			}
			for(i=1,j=0;i<16,j<7;i++)
			{
				s[j]=t[i];
				i++;
				j++;
			}
			if(f[7]==3)
			{
				if((s[6]==4)||(s[6]==7))
				{
					printf("Your Card is American Express\n");
				}
			}
			else if(f[7]==5)
			{
				if((s[6]>0)&&(s[6]<6))
				{
					printf("Your card is Master Card\n");
				}
			}
			else if(f[7]==4)
			{
				printf("Yor card is of visa type\n");
			}
			else
			{
				printf("Your card is of other type\n");
			}
		
			for(i=0;i<7;i++)
			{
				s[i]=s[i]*2;
			}
			for(i=0;i<7;i++)
			{
				if((s[i])>9)
				{
					
					ex=s[i]/10;
					s[i]=s[i]%10;
					s[k]=ex+s[i];
					s[i]=0;	
					k++;
				}
			}
			for(i=0;i<k;i++)
			{
				st=st+s[i];	
			}
			for(i=0;i<8;i++)
			{
				total=total+f[i];
			
			}
				total=total+st;
			ans=total%10;
			if(ans==0)
			{
				printf("Your card is legit proceed\n");	
				printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
				printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
				exit(1);
				
			}			
			else
			{
				printf("Your card is not legit\n");
				q=1;	
			}
		}
		else
		{
			q=1;
		}
		}
		
	
}

				
			
			
		
