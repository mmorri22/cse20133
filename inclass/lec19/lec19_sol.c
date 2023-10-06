#include <stdio.h>
#include <stdlib.h>

#define BUFFER 45
#define DEPARTMENT 4

// Step 4:
// Struct Definition will go here - lib_entry
// Must contain an index, title string sized BUFFER,
// a course_dept sized DEPARTMENT
// a Course Number course_num and the number of books num_books
typedef struct lib_entry{
    char title[BUFFER];
    char course_dept[DEPARTMENT];
    unsigned int course_num;
    unsigned int num_books;
}lib_entry;

int main( const int argc, const char* argv[] ){

    // Protect the inputs
    if( argc != 3 ){
        fprintf( stdout, "Incorrect Number of Inputs\n" );
        return EXIT_FAILURE;
    }

    // Step 1a - Create a read FILE* with the argv[1]
    FILE* lib_file =  fopen( argv[1], "r");

    // Step 2 - Check to ensure that the file exists
    if( lib_file == NULL ){
        fprintf( stdout, "No File Named %s\n", argv[1] );
        return EXIT_FAILURE;
    }

    // Message to the user, reading from the File
    fprintf( stdout, "Reading from %s\n", argv[1] );
    fprintf( stdout, "File memory info: %p -> %p\n", &lib_file, lib_file );

    // Step 3 - Read in the first line, which is the number of entries
    long unsigned int num_entries;
    if( fscanf( lib_file, "%ld", &num_entries ) ) {  }

    // Print the number of entries
    fprintf( stdout, "Reading %ld Entries...\n", num_entries );

    // Step 4 - Go to the library.h file and create a struct
    // Step 5a - Allocate the amount of dynamic memory for that struct
    lib_entry* the_lib = (lib_entry *)malloc( num_entries*sizeof(lib_entry) );

    // Print pointers for the dynamically allocated memory
    fprintf( stdout, "%p -> %p\n", &the_lib, the_lib );

    // Now we can see the number of entries
    fprintf( stdout, "_IO_read_ptr = %p, ", lib_file->_IO_read_ptr);
    fprintf( stdout, "_IO_read_end = %p\n", lib_file->_IO_read_end);

    // Step 6a - Loop through the array
    // Remember Dr. Morrison's Golden Rule of Pointers
    // Put the second bracket after Step 6b
    // Also, create an iterator before the loop
    long unsigned int iter = 0;
    while( lib_file != NULL && iter < num_entries ){

        // Step 7 - Scan in each value
        if( fscanf( lib_file, "%s", the_lib[iter].title) ){}
        if( fscanf( lib_file, "%s", the_lib[iter].course_dept) ){}
        if( fscanf( lib_file, "%u", &(the_lib[iter].course_num) ) ){}
        if( fscanf( lib_file, "%u", &(the_lib[iter].num_books) ) ){}

        // Print the values
        fprintf( stdout, "%s %s %u %u\n", the_lib[iter].title, 
            the_lib[iter].course_dept, the_lib[iter].course_num,
            the_lib[iter].num_books);

        // Print the locations of the pointers
        fprintf( stdout, "_IO_read_ptr = %p, ", lib_file->_IO_read_ptr);
        fprintf( stdout, "_IO_read_end = %p\n", lib_file->_IO_read_end);

        // Step 6b - Use the break command from the reading
        if( lib_file->_IO_read_ptr == lib_file->_IO_read_end  )
            break;

        ++iter;
    }

    // Step 1b - Close the FILE*
    fclose( lib_file );

    // Step 8a - Create a read FILE* with the argv[1]
    FILE* write_file =  fopen( argv[2], "w");

    // Step 9 - Print to the output
    fprintf( write_file, "%lu\n", num_entries);
    for( iter = 0; iter < num_entries; ++iter ){

        fprintf( write_file, "%s %s %u %u\n", the_lib[iter].title, 
            the_lib[iter].course_dept, the_lib[iter].course_num,
            the_lib[iter].num_books);

    }

    // Step 8b - Close the 
    fclose( write_file );

    // Step 5b - Free the lib_entry array
    free( the_lib );

    return EXIT_SUCCESS;
}