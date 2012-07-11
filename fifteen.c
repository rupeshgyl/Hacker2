/***************************************************************************
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("Congrats You Won!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
	else
	{


        // sleep thread for animation's sake
        usleep(500000);
        }
    
  }
    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
    int i,j,k;
    k=(d*d)-1;
    for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			board[i][j]=k;
			k--;
		}	
	
	}
	
	
    if(!(k%2==0))
    {
	int temp;
	temp=board[d-1][d-3];
	board[d-1][d-3]=board[d-1][d-2];
	board[d-1][d-2]=temp;
    }
			
	return 1;	
}


/* 
 * Prints the board in its current state.
 */

void
draw()
{
	int i,j;
    	for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			printf("%2d  ",board[i][j]);
			
		}
		printf("\n");
	}
	return 1;
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
    int i,j,temp[10],v=2;
	while(v!=0)
	{
    		for(i=0;i<d;i++)
		{
			for(j=0;j<d;j++)
			{
				if(board[i][j]==0)
				{
					temp[0]=i;
					temp[1]=j;
				}
				if(board[i][j]==tile)
				{
					temp[2]=i;
					temp[3]=j;
				}
				
			}
	
		}
		if((temp[2]==temp[0])&&((temp[3]=temp[1]-1)||(temp[3]=temp[1]+1)))
		{
			temp[4]=board[temp[0]][temp[1]];
			board[temp[0]][temp[1]]=board[temp[2]][temp[3]];
			board[temp[2]][temp[3]]=temp[4];
			
		}	
		else if((temp[3]==temp[1])&&((temp[2]=temp[0]-1)||(temp[2]=temp[0]+1)))
		{
			temp[4]=board[temp[0]][temp[1]];
			board[temp[0]][temp[1]]=board[temp[2]][temp[3]];
			board[temp[2]][temp[3]]=temp[4];
			
		}	
		else
		{ 
			v=0;
    			return false;
		}
		return true;
	}
	
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
   int i,j,z,k=1,s;
    s=d*d;
    for(i=0;i<d;i++)
	{
		for(j=0,k=1,z=1;j<d;j++,k++)
		{
			if(board[i][j]==k)
			{
				z++;
			}
				
		}	
	
	}
	if(s==d)
	{
		return true;
	}
	else
	{
    return false;
	}
}
