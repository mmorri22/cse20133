 #include "sort_and_search.h"
 #define ARRAYSIZE 10

   int main()
   {
     /*Define the array*/
     int int_array[ARRAYSIZE];

     /*Define the search_val the user will input*/
     int search_val = 0;

     /*Define value as what will be searched for in the final function call*/
     int value;

     /*Call fill array in order to receive the array we want to work with*/
     fill_array(int_array);

     /*State what is going to be printed from the loop*/
     fprintf(stdout,"Unsorted array: ");
     /*Print the unsorted array, that is, the array as given by the user*/
     print_array(int_array);

     /*Sort the array that was given using the insertion sort algorithm*/
     insertion_sort(int_array);

     /*State what is going to be printed from the loop*/
     fprintf(stdout,"Sorted array: ");
     /*Print the sorted array*/
     print_array(int_array);

     /*Get an initial value from the user to search for*/
     scan_value(&search_val);

     /*While the user does not enter -1, continue asking for values
     to search for and search for them*/
     while (search_val != -1)
     {
       /*Set value equal to the user's input*/
       value = search_val;

       /*Search for the user's requested value and either output the index,
       explain it wasn't found, or end the program*/
       binary_search(int_array, value);

       /*Get a value from the user to search for*/
       scan_value(&search_val);

     }

     return 0;
   }
