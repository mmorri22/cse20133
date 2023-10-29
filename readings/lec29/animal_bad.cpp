#include <iostream>
#include <cstdlib>

class Animal {

    /*** Members ***/
    std::string name;
    int age;
    int weight;

    /*** Class Methods ***/
    void set_weight(int w) {
    
        if (w > 100) {
            printf("error: unrealistic weight!\n");
            return;
        }
        
        /* Accessing the weight in Animal using "this" */
        this->weight = w;
        
    }

    int get_weight() {
        return this->weight;
    }
    
    void print_animal(){
        
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Name: " << this->name << std::endl;
        std::cout << this->name << "'s age: " << this->age << std::endl;  
        std::cout << this->name << "'s weight: " << this->weight << std::endl;   
        std::cout << "--------------------------------" << std::endl;

    }

};

int main()
{
    Animal stack_cat;
    stack_cat.name = "kitty";
    stack_cat.age = 5;
    stack_cat.set_weight(12);
    stack_cat.print_animal();    

    // C++ Equivalent of Animal* heap_dog = (Animal *)malloc( sizeof(Animal) );
    Animal* heap_dog = new Animal();
    heap_dog->name = "Eirinn";
    heap_dog->age = 7;
    heap_dog->set_weight(55);

    heap_dog->print_animal();

    heap_dog->set_weight(999); // will report an error


    // C++ Equivalent of free( heap_dog );
    delete heap_dog;

    return EXIT_SUCCESS;
}