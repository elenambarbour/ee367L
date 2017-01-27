/*
 * Pre-condition:  The input is a data file which is
 * formatted as follows.  The first line is an integer
 * equal to the number of data values that follow it.
 * Each subsequent line is a data value, which is an
 * integer.  The data file's name is an argument
 * in the command line.
 *
 * Post-condition: The program will sum all the data
 * values in the data file.  Then it will display the
 * sum on the standard output.   
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main(int argc, char *argv[])
{

FILE * fp;
int i;
int numvalues;
int datavalue;
int sum;

if (argc != 2) 
{
   printf("Usage: ./%s Data/file_name\n",argv[1]);
   return;
}

if ((fp=fopen(argv[1], "r"))==NULL)
{
   printf("Could not open the data file %s\n",argv[1]);
   return;
}

/* Read the first line which is the number of data values */
fscanf(fp, "%d", &numvalues);
if (numvalues > 1000 || numvalues < 0) 
{
   printf("Error: the number of data values %d exceeds 1000\n",numvalues); 
   fclose(fp);
   return;
}

/* Read in the data values and sum them */
sum = 0;
for (i=0; i<numvalues; i++)
{
   fscanf(fp, "%d", &datavalue); 
   sum += datavalue;
}

printf("Sum from data file %s is %d\n", argv[1], sum);
fclose(fp);
}

