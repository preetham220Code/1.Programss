#include <iostream>
using namespace std;

class Base { 
public: 
    void normal (){ 
        cout<<"Base::normal(early binding)\n";
    } 
    virtual void special (){ 
        cout<<"Base::special\n"; 
    } 
}; 

class derived: public Base { 
public: 
    void normal (){ 
        cout<<"derived::normal\n";
    } 
}; 

int main(){ 
    derived d; 
    Base *b = &d; 
    b->normal(); 
    b->special(); 
    return 0; 
}
