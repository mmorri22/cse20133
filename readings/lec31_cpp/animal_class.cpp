#include <iostream>
#include <cstdlib>

class Animal {

    /*** Members ***/
    private:
        std::string name;
        int age;
        int weight;

    public:

        /* Constructor */
        Animal( const std::string& name, const int age, const int weight) :
            name(name), age(age), weight(weight){}

        /* Destructor - No dynamic memory, so nothing needs to be in it */
        ~Animal(){}

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

int main(){
    /* Static class using Constructor */
    Animal stack_cat( "kitty", 5, 12 );
    stack_cat.print_animal();    

    /* Dynamic class using Constructor and Destructor */
    Animal* heap_dog = new Animal("Eirinn", 7, 55);
    heap_dog->print_animal();
    heap_dog->set_weight(999); // will report an error

    delete heap_dog; 

    return EXIT_SUCCESS;
}