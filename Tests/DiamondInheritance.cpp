//by Ilya Mirzazhanov
//Diamond Inheritance problem
//clang can detect it
//polystat can not
#include <iostream>
using namespace std;

//super parent class
class A {
public:
    virtual void name(){
         cout << "This is class A \n";
    }
};

class B: public A {}; 

class C: public A {};

//diamond inheritance 
class D: public B, public C {};
 
int main() {
    //indefined behavior when name() 
    return 0;
}

