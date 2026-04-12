#ifndef SINGLYLIST_HPP
#define SINGLYLIST_HPP

// Węzeł listy jednokierunkowej - przechowuje dane i wskaźnik na następny węzeł
struct NodeS {
    int data;    // przechowywana wartość
    NodeS* next; // wskaźnik na następny węzeł (nullptr jeśli ostatni)
};

// Lista jednokierunkowa - każdy węzeł wskazuje tylko na następny.
// Przechowujemy head (pierwszy) i tail (ostatni) dla szybkiego dodawania na koniec.
class SinglyList {
    NodeS* head; // wskaźnik na pierwszy węzeł
    NodeS* tail; // wskaźnik na ostatni węzeł

public:
    SinglyList();
    ~SinglyList();

    void addEnd(int val);       // dodaj na koniec - O(1)
    void addFront(int val);     // dodaj na początek - O(1)
    void addAt(int val, int pos); // dodaj na pozycję - O(n)

    void removeEnd();           // usuń ostatni - O(n) bo musimy dojść do przedostatniego
    void removeFront();         // usuń pierwszy - O(1)
    void removeAt(int pos);     // usuń z pozycji - O(n)

    int  search(int val);       // szukaj wartości - O(n)
    void display();             // wyświetl - O(n)
    void generate(int n);       // generuj n losowych elementów
    int  getSize();             // zlicz i zwróć rozmiar - O(n)
};

#endif
