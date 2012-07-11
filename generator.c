/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cs50.h>

#define LIMIT 65536

int
main(int argc, char *argv[])
{
	int i;
    
    int n = atoi(argv[1]);
    if (argc == 3)
        srand((unsigned int) atoi(argv[2]));
    else
        srand((unsigned int) time(NULL));
    for (i = 0; i < n; i++)
        printf("%d\n", rand() % LIMIT);

}
