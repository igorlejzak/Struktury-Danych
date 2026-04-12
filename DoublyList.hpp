#ifndef DOUBLYLIST_HPP
#define DOUBLYLIST_HPP

// Węzeł listy dwukierunkowej - ma wskaźniki w obie strony
struct NodeD {
    int data;    // przechowywana wartość
    NodeD* next; // wskaźnik na następny węzeł
    NodeD* prev; // wskaźnik na poprzedni węzeł
};

// Lista dwukierunkowa - każdy węzeł wskazuje na następny I poprzedni.
// Dzięki temu removeEnd jest O(1) (mamy tail->prev), a addAt może iść od końca.
class DoublyList {
    NodeD* head; // wskaźnik na pierwszy węzeł
    NodeD* tail; // wskaźnik na ostatni węzeł

public:
    DoublyList();
    ~DoublyList();

    void addEnd(int val);       // dodaj na koniec - O(1)
    void addFront(int val);     // dodaj na początek - O(1)
    void addAt(int val, int pos); // dodaj na pozycję - O(n)

    void removeEnd();           // usuń ostatni - O(1) dzięki prev!
    void removeFront();         // usuń pierwszy - O(1)
    void removeAt(int pos);     // usuń z pozycji - O(n)

    int  search(int val);       // szukaj wartości - O(n)
    void display();             // wyświetl - O(n)
    void generate(int n);       // generuj n losowych elementów
    int  getSize();             // zlicz i zwróć rozmiar - O(n)
};

#endif
