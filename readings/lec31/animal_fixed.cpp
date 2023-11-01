#include <iostream>
#include <cstdlib>

class Animal {

    /*** Members ***/
    private:
        std::string name;
        int age;
        int weight;

    public:
        /*** Class Set Methods ***/
        void set_weight(const int w) {

            if (w > 100) {
                printf("error: unrealistic weight!\n");
                return;
            }

            /* Accessing the weight in Animal using "this" */
            this->weight = w;
        }

        void set_name( const std::string& name ){

            this->name = name;
        }

        void set_age( const int age ){

            this->age = age;
        }

        /*** Class Get Methods ***/
        std::string get_name() const{
            return this->name;
        }

        int get_weight() const{
            return this->weight;
        }

        int get_age() const{
            return this->age;
        }
        
        void print_animal() const{
            
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
    stack_cat.set_name("kitty");
    stack_cat.set_age(5);
    stack_cat.set_weight(12);
    stack_cat.print_animal();    

    // C++ Equivalent of Animal* heap_dog = (Animal *)malloc( sizeof(Animal) );
    Animal* heap_dog = new Animal();
    heap_dog->set_name("Eirinn");
    heap_dog->set_age(7);
    heap_dog->set_weight(55);

    heap_dog->print_animal();

    heap_dog->set_weight(999); // will report an error


    // C++ Equivalent of free( heap_dog );
    delete heap_dog;

    return EXIT_SUCCESS;
}