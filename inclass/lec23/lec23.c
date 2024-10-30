#include <stdio.h>
#include <stdlib.h>

#define BUFFER 45
#define DEPARTMENT 4

// Step 4:
// Struct Definition will go here - lib_entry
// Must contain an index, title string sized BUFFER,
// a course_dept sized DEPARTMENT
// a Course Number course_num and the number of books num_books


int main( const int argc, const char* argv[] ){

    // Protect the inputs
    if( argc != 3 ){
        fprintf( stdout, "Incorrect Number of Inputs\n" );
        return EXIT_FAILURE;
    }

    // Step 1a - Create a read FILE* with the argv[1]
    

    // Step 2 - Check to ensure that the file exists


    // Message to the user, reading from the File
    fprintf( stdout, "Reading from %s\n", argv[1] );
    fprintf( stdout, "File memory info: %p -> %p\n", &lib_file, lib_file );

    // Step 3 - Read in the first line, which is the number of entries


    // Print the number of entries
    fprintf( stdout, "Reading %ld Entries...\n", num_entries );

    // Step 4 - Create a struct ^
    // Step 5a - Allocate the amount of dynamic memory for that struct


    // Print pointers for the dynamically allocated memory
    fprintf( stdout, "%p -> %p\n", &the_lib, the_lib );

    // Now we can see the location of the pointers
    fprintf( stdout, "_IO_read_ptr = %p, ", lib_file->_IO_read_ptr);
    fprintf( stdout, "_IO_read_end = %p\n", lib_file->_IO_read_end);

    // Step 6a - Loop through the array
    // Remember Dr. Morrison's Golden Rule of Pointers
    // Put the second bracket after Step 6b
    // Also, create an iterator before the loop


        // Step 7 - Scan in each value
        
        
        
        

        // Print the values
        fprintf( stdout, "%s %s %u %u\n", the_lib[iter].title, 
            the_lib[iter].course_dept, the_lib[iter].course_num,
            the_lib[iter].num_books);

        // Print the locations of the pointers
        fprintf( stdout, "_IO_read_ptr = %p, ", lib_file->_IO_read_ptr);
        fprintf( stdout, "_IO_read_end = %p\n", lib_file->_IO_read_end);

        // Step 6c - Use the break command from the reading
        
            

    // Step 6b - Put the bracket from the while loop here  
    

    // Step 1b - Close the FILE*
    

    // Step 8a - Create a read FILE* with the argv[1]
    

    // Step 9 - Print to the output


    // Step 8b - Close the 
    

    // Step 5b - Free the lib_entry array
    

    return EXIT_SUCCESS;
}