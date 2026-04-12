#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

// tablica dynamiczna - trzyma elementy jeden obok drugiego w pamieci
// gdy brakuje miejsca, rozmiar tablicy jest podwajany
class ArrayList {
    int* Tablica;        // wskaznik na blok pamieci z danymi
    int IloscElementow;  // ile elementow aktualnie jest w tablicy
    int MaksymalnyRozmiar; // ile elementow tablica moze pomiescic bez powiekszania

    void Powieksz(); // prywatna, wywolywana automatycznie przy braku miejsca

public:
    ArrayList();
    ~ArrayList();

    void DodajNaKoniec(int Wartosc);
    void DodajNaPoczatek(int Wartosc);
    void DodajNaPozycje(int Wartosc, int Pozycja);

    void UsunZKonca();
    void UsunZPoczatku();
    void UsunZPozycji(int Pozycja);

    int  Szukaj(int Wartosc);   // zwraca indeks lub -1 jesli nie znaleziono
    void Wyswietl();
    void Generuj(int IloscDoWygenerowania);
    int  PobierzRozmiar();
};

#endif
