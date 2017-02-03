/* 
 * This is an implementation of merge sort 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 1000 

int a[MAXSIZE];       /* Array of data */
int temp[MAXSIZE];    /* Temporary array */

/* Global variables -- be careful */

void genvalues(int n); /* Initializes array a[] wih random values */
void prnvalues(int n); /* Displays array a[] */

/* 
 * The following function merges sorted subarrays 
 *    (a[last], a[last+1],..., a[midpt-1))
 *    (a[midpt], a[midpt+1], ..., a[last-1])
 * into a sorted array.
 */
void merge(int first, int midpt, int last); /* Merges subarrays */

/*
 * You are to change the following recursive implementation 
 * into an iterative implementation.
 */
void mergesort(int first, int last);        /* Merge sort */

void main() 
{
int length;

printf("Mergesort:  Enter size of array: ");
scanf("%d",&length);
if (length >= MAXSIZE) {
   printf("Array is too long: length = %d\n", length);
   return;
}
else if (length <= 0) {
   printf("Length must be positive\n");
   return;
}

genvalues(length);    /* Initialize a[] with random values */
printf("Initial values:\n");
prnvalues(length);    /* Display the values */

mergesort(0, length);

printf("\nOutput:\n");
prnvalues(length); /* Display the sorted values */
}

/* 
 * Mergesort:  Sorts the values in a[first], a[first+1],..., a[last-1] 
 * This is a recursive implementation.
 *
 * You are to change this into an iterative implementation.  
 *
 * It should still have O(n log n) time complexity.
 */

void mergesort(int first, int last)
{
int midpt;
midpt = (first+last)/2;

if (first < midpt-1) mergesort(first, midpt);
if (midpt < last-1) mergesort(midpt, last);
merge(first, midpt, last);
}


/*
 * Merges two sorted subarrays (sorted in increasing order)  
 *    (a[first], ..., a[midpt-1]) and
 *    (a[midpt],..., a[last-1]) 
 *    into
 *    subarray temp[first],..., temp[last-1] in increasing order.
 *    
 *    Then it copies temp[first],..., temp[last-1] back into
 *    a[first],..., a[last-1].
 */
void merge(int first, int midpt, int last)
{
int leftptr;   /* Pointers used in array a[ ] */
int rightptr;
int k;         /* pointer used in array temp[ ] */
int delay;

leftptr = first;
rightptr = midpt; 

/* Merge values in the two arrays of a[] into temp[] */
for(k=first; k<last; k++) {
   if (leftptr >= midpt) temp[k] = a[rightptr++];
   else if (rightptr >= last) temp[k] = a[leftptr++];
   else if (a[leftptr] < a[rightptr]) temp[k] = a[leftptr++];
   else if (a[leftptr] >= a[rightptr]) temp[k] = a[rightptr++];
   else printf("There's a bug \n");
}

/* Copy temp[] back to a[] */
for(k=first; k<last; k++) a[k] = temp[k];
}


/*
 * Initializes array a[] with random values.
 */
void genvalues(int n)
{
int i;
int k;
int temp;

for (i=0; i<n; i++) a[i] = i; /* Initialize with distinct values */

/* Now randomly shuffle the values */
srand48(1);     /*  Seed the pseudorandom number generator */
for (i=0; i<n; i++) {
   k = lrand48()%(n-i);
   temp = a[k];
   a[k] = a[n-i-1];
   a[n-i-1] = temp; 
}
}

/*
 * Prints the values in the array a[]
 */
void prnvalues(int n)
{
int i;
for (i=0; i<n; i++) {
   printf(" %d ", a[i]);
   if ((i+1)%10 == 0) printf("\n");
}
printf("\n");

}



