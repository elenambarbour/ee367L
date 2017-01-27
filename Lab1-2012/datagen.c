/*
 * Generates data files
 *
 * Pre-condition:  No precondition
 *
 * Post-condition:  
 * Data files, each has the following format.
 * First line is the number of data values (integer).
 * Each subsequent line has an integer data value, which
 * is pseudo randomly generated in the range
 * from 0 to 99. 
 * For example, if the first line in the data
 * file is 20 then there are 20 subsequent
 * lines, each with a pseudo random integer value.
 * The data files are created in a subdirectory
 * "Data" and have the names "datafile-k", where
 * k is an integer 0, 1, 2, ...
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMFILES 10 /* Number of data files to be created */
#define NUMDATA 20  /* Number of data values in the data files */

/* Converts an integer value into an ascii string */
void convert(int i, char buffer[]);

main()
{

FILE * fp;
int i;
int j;
char fname[100] = {"Data/datafile-"};
char numtext[100];
char string[100];

srand48(1); /* Seeding the random number generator */

for (i=0; i<NUMFILES; i++) 
{
   convert(i, numtext); /* Create a file called "datafile-i" */
                        /* The next two functions strcpy and strcat */
                        /*    are from the string.h library */
   strcpy(string,fname); /* Copies the char string "fname" to "string" */
   strcat(string, numtext); /* Concatenates "numtext" to "string" */
   fp = fopen(string, "w");
   fprintf(fp,"%d\n",NUMDATA); /* Write the first line to the file */
   for (j=0; j<NUMDATA; j++)   /* Write random data values to the file */
      fprintf(fp,"%d\n",lrand48()%100);
   fclose(fp);
}

}

/* Converts an integer value into an ascii string */
void convert(int i, char buffer[])
{
int k = i;
int n;
int m;
char temp[10];
int numdigits;

temp[0] = '\0';
n = 0;  /* points to the last element in buffer */
if (k == 0) 
{ 
   n++;
   temp[n] = '0';
}
else
{
   while (k > 0) 
   {
      n++;
      temp[n] = '0' + (k%10);
      k = k/10;
   }
}
for (m=0; n>=0; n--)
{
   buffer[m] = temp[n];
   m++; 
}

}




