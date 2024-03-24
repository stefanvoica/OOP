#include<iostream>
using namespace std;

class C {
    int x;
public:
    C() { cout << "C()"; x=0; }
    C (int y) { cout<< "C("<< y<< ")"; x=y; }
    C (C& c) { cout<<"C(&)"; x=c.x;}
    ~C() { cout<<"~C"; }
}q(11283);

void foo(C c)
{
    C c1;
}

int main ()
{
    C c, c1(2023), c2(c);
    foo(c1);
    return 0;
}

/*
c->x=0
c1->x=2023
c2->x=0 (preluata de la c)

Pt functia foo se creeaza un element de tipul clasei C, copie a lui c1;
c->x=2023
c1->x=0

Se afiseaza C()C(2023)C(&)C(&)C()~C~C~C~C~C
*/
