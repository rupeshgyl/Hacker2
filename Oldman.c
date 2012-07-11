#include <cs50.h>
#include <stdio.h>
#include<string.h>


int
main(void)
{
	int i,n;
	string no[]={"One","two","three","four","five","six","seven","eight","nine","ten"};
	string part[]={"on my thumb", "on my shoe", "on my knee", "on my door", "on my hive", "on my sticks", "up in heaven", "on my gate", 				"on my spine", "once again"};
	printf("Enter the Number of paragraphs wanted by you\n");
	scanf("%d", &n);
	printf("Your song is here\n");
	for(i=0;i<n;i++)
	{
		printf("This old man, he played %s\nHe played knick-knack %s\nKnick-knack paddywhack, give your dog a bone\nThis old man came rolling home\n\n",no[i],part[i]);

	}
	
}
