
#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define _GNU_SOURCE        
#include <crypt.h>

     
     int
     main(void)
     {
	char ans;
       unsigned long seed[2];
       char salt[] = "$1$........";
       const char *const seedchars =
         "./0123456789ABCDEFGHIJKLMNOPQRST"
         "UVWXYZabcdefghijklmnopqrstuvwxyz";
       char *password;
       int i; 
       seed[0] = time(NULL);
       seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);
       for (i = 0; i < 8; i++)
         salt[3+i] = seedchars[(seed[i/5] >> (i%5)*6) & 0x3f];
    
       password = crypt(getpass("Password:"), salt);
    
       	puts(password);
	
     }

