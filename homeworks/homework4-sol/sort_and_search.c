#include "sort_and_search.h"

void fill_array(int int_array[])
{
  /*Let the user know what kind of input we are looking for*/
  fprintf(stdout, "Enter %d unsorted positive integers, one on each line:\n", ARRAYSIZE);

  /*Ask the user for a value and store that value ARRAYSIZE times*/
  for (int countFill = 0; countFill < ARRAYSIZE; countFill++)
  {
    /*Create a variable to collect the user's input*/
    int userData;
    fprintf(stdout, "Enter a value: \n");
    fscanf(stdin, "%d", &userData);
    int_array[countFill] = userData;
  }
}

 void print_array(int int_array[])
 {
   /*Count up to ARRAYSIZE and print that index of the array*/
   for(int countPrint = 0; countPrint < ARRAYSIZE; countPrint++)
   {
     fprintf(stdout,"%d ",int_array[countPrint]);
   }
   fprintf(stdout," \n");
 }

 void insertion_sort(int int_array[])
 {
   /*Create a variable to count how much of the array is sorted*/
   int sortIndex = 1;
   /*Create a variable to hold the number I am trying to sort*/
   int currentNum;
   /*Create a variable to hold the value I am comparing the current value to*/
   int compareNum;

   while (sortIndex < ARRAYSIZE)
   {
     /*Set currentNum equal to the value starting the unsorted array*/
     currentNum = int_array[sortIndex];

     for (int indexCounter = sortIndex; indexCounter > 0; indexCounter--)
     {
       compareNum = int_array[indexCounter-1];

       /*If the value we are looking at is less than the value directly
       to its left, switch the two values*/
       if (currentNum < compareNum)
       {
         int_array[indexCounter] = compareNum;
         int_array[indexCounter-1] = currentNum;
       }
     }

     sortIndex++;
   }
 }

 void scan_value(int* search_val)
 {
   /*Create a variable to represent the user's input*/
   int userSearch;
   fprintf(stdout,"Enter a value to search for (or -1 to finish): ");
   fscanf(stdin,"%d", &userSearch);
   *search_val = userSearch;
 }

 int binary_search(int int_array[], int value)
 {
   /*Let the user know the code is looking for their value*/
   fprintf(stdout,"Scanning for %d...\n", value);

   /*Define the initial minimum, maximum, and midpoint of search*/
   int minimum = 0;
   int maximum = ARRAYSIZE-1;
   int midpoint = (maximum + minimum)/2;

   /*If the midpoint is our number, then we stop here*/
   if (value == int_array[midpoint])
   {
     fprintf(stdout,"%d was found at index %d\n", value, midpoint);
     return midpoint;
   }
     while (minimum != maximum)
   {
     if (value > int_array[midpoint])
     {
       /*In this case, we only need to search the top half of the search range*/
       minimum = midpoint + 1;
       midpoint = (minimum + maximum)/2;
     }
     else if (value < int_array[midpoint])
     {
       /*In this case, we only need to search the bottom half of the search range*/
       maximum = midpoint - 1;
       midpoint = (minimum + maximum)/2;
     }
     else
     {
       /*In this case, we must be at the number we want*/
       fprintf(stdout,"%d was found at index %d\n", value, midpoint);
       return midpoint;
     }
   }

   if (minimum == maximum && value == int_array[minimum])
   {
     fprintf(stdout,"%d was found at index %d\n", value, minimum);
     return minimum;
   }
   else
   {
     fprintf(stdout,"%d was not found in the array\n", value);
     return 0;
   }

   return 0;

 }
