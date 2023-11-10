#include <iostream>
#include <cstdlib>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

int main(){
    
	// Created, but not initialized - Will not pass PQC yet
    pthread_t tid_0;

    std::cout << &tid_0 << " " << tid_0 << std::endl;
    
    return EXIT_SUCCESS;
}