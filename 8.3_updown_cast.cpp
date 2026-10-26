#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() { 
        cout << "Animal \n"; 
    } 
}; 

class dog : public Animal {
public:
    void speak() const override { 
        cout << "Woof!\n"; 
    }
    ~dog() { 
        cout << "Dog \n"; 
    }
};

int main() {
    Animal* a = new dog();
    
    
    if (dog* d = dynamic_cast<dog*>(a)) { 
        d->speak();
    }
    
    delete a; 
    return 0;
}
