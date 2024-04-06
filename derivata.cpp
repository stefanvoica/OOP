#include <iostream>

class Baza {
private:
    int x;
public:
    Baza(int x_) : x(x_) { std::cout << "Constructor Baza\n"; }
    ~Baza() { std::cout << "Destructor Baza\n"; }
};

class Derivata : Baza {
public:
    Derivata() : Baza(1)              { std::cout << "Constructor 1 Derivata\n"; }
    Derivata(int x) : Baza(x)         { std::cout << "Constructor 2 Derivata\n"; }
    Derivata(const Baza& b) : Baza(b) { std::cout << "Constructor 3 Derivata\n"; }
    ~Derivata() { std::cout << "Destructor Derivata\n"; }
};

int main() {
    Baza b{1};
    std::cout << "main: Dupa b, inainte de d\n";
    Derivata d;
    Derivata e{5};
    Derivata f{b};
    std::cout << "main: sfarsit\n";
}
/*
Constructor Baza
main: Dupa b, inainte de d
Constructor Baza
Constructor 1 Derivata
Constructor Baza
Constructor 2 Derivata
Constructor 3 Derivata
main: sfarsit
Destructor Derivata
Destructor Baza
Destructor Derivata
Destructor Baza
Destructor Derivata
Destructor Baza
Destructor Baza
 */