#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void losuj(int tab[], int wielkosc, int zakres);
void wypisz(int tab[], int wielkosc);
void podaj(int liczby2[], int wielkosc);
int porownaj(int tab1[], int wielkosc, int tab2[], int wielkosc2);

int main()
{
    int liczby[6];
    int wielkosc = sizeof(liczby)/sizeof(*liczby);
    losuj(liczby, wielkosc, 46);

    int liczby2[6];
    int wielkosc2 = sizeof(liczby2)/sizeof(*liczby2);

    cout << "podaj swoje liczby: ";
    podaj(liczby2, wielkosc2);

    cout << "Wylosowane liczby: ";
    wypisz(liczby, wielkosc);

    cout << "Udalo ci sie trafic: " << porownaj(liczby, wielkosc, liczby2, wielkosc2) << endl;

    cout << endl << endl;

    return 0;
}

void losuj(int tab[], int wielkosc, int zakres) {
    time_t t;
    srand((unsigned) time(&t));

    for (int i = 0; i < wielkosc; i++) {
        int liczba = rand() % zakres;
        for (int j = 0; j < wielkosc; j++) {
            if (liczba == tab[j]) {
                liczba++;
                if (liczba > wielkosc) {
                    liczba -= wielkosc;
                }
            } else break;
        }
        tab[i] = liczba;
    }
}

void wypisz(int tab[], int wielkosc) {
    for (int i = 0; i < wielkosc; i++) {
        cout << tab[i];
        if (i != wielkosc - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void podaj(int tab[], int wielkosc) {
    for (int i = 0; i < wielkosc; i++) {
        int b;
        cin >> b;
        for (int i = 0; i < wielkosc; i++) {
            for (int j = 0; j < wielkosc; j++) {
                if (b == tab[j]) {
                    b++;
                    if (b > wielkosc) {
                        b -= wielkosc;
                    }
                } else break;
            }
        }
        tab[i] = b;
    }
}

int porownaj(int tab1[], int wielkosc, int tab2[], int wielkosc2) {
    int match = 0;

    for (int i = 0; i < wielkosc; i++) {
        for (int j = 0; j < wielkosc2; j++) {
            if(tab1[i] == tab2[j]) {
                match++;
            }
        }
    }
    return match;
}

