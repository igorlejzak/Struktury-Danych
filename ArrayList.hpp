#ifndef ARRAYLIST.HPP
#define ARRAYLIST.HPP

// Tablica dynamiczna - przechowuje elementy w ciągłym bloku pamięci.
// Gdy zabraknie miejsca, rozmiar tablicy jest podwajany (resize).
class ArrayList {
    int* tab;       // wskaźnik na blok pamięci z danymi
    int size;       // ile elementów aktualnie jest w tablicy
    int capacity;   // ile elementów tablica może pomieścić bez resize

    void resize();  // prywatna - wywołuje się sama gdy potrzeba

public:
    ArrayList();
    ~ArrayList();

    void addEnd(int val);       // dodaj na koniec
    void addFront(int val);     // dodaj na początek
    void addAt(int val, int pos); // dodaj na podaną pozycję

    void removeEnd();           // usuń ostatni
    void removeFront();         // usuń pierwszy
    void removeAt(int pos);     // usuń z podanej pozycji

    int  search(int val);       // szukaj wartości, zwróć indeks lub -1
    void display();             // wyświetl wszystkie elementy
    void generate(int n);       // wypełnij n losowymi liczbami 0-9999
    int  getSize();             // zwróć aktualny rozmiar
};

#endif
