/*
Tipul int * const p
int * const p este un pointer constant la un int. Aceasta înseamnă că pointerul însuși este constant și nu poate fi modificat după ce este inițializat, dar valoarea la care pointează poate fi modificată. În acest context:

int * înseamnă un pointer la un int.
const aplicat la pointer înseamnă că pointerul este constant și nu poate fi redirecționat către o altă adresă după ce a fost inițializat.
*/

#include <iostream>
using namespace std;
class C
{
    int * const p;
public:
    C(int x) : p(&x)
    {
        (*p) += 3;
    }
    void set (int x)
    {
        p = &x;
    }
    friend ostream& operator<<(ostream& o, C x)
    {
        o << *x.p;
        return o;
    }
};
int main()
{
    cout << C(3);
    return 0;
}

/*
Probleme în cod
Inițializarea p în constructor:

În constructor, p este inițializat cu adresa lui x, care este un parametru al constructorului.
Aceasta este o problemă, deoarece x este o variabilă locală a constructorului și va fi distrusă când constructorul se termină. Deci, p va rămâne cu un pointer invalid după ce constructorul se termină.
Funcția set:

Funcția set încearcă să schimbe valoarea pointerului p, ceea ce nu este permis deoarece p este un const pointer.
Aceasta va cauza o eroare de compilare deoarece p este constant și nu poate fi reasignat după inițializare.


Programul nu compilează avem un pointer constant și există o metodă de tip
setter în clasa noastră care este neconstantă și impactează nu valoarea, ci
adresa (i.e. dorește să modifice adresa către care pointează), cum pointerul
este constant nu se poate acest lucru. Eroarea va fi la linia declarării
setter-ului, iar pentru repararea ei eliminăm const-ul din declararea atributului
p, îl vom lăsa doar int* p.
*/
