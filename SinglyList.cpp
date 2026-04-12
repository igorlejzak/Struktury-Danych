#include "SinglyList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// ============================================================
// KONSTRUKTOR - pusta lista: head i tail wskazują na nullptr
// ============================================================
SinglyList::SinglyList() {
    head = nullptr;
    tail = nullptr;
}

// ============================================================
// DESTRUKTOR - zwalniamy wszystkie węzły żeby uniknąć memory leak
// ============================================================
SinglyList::~SinglyList() {
    NodeS* curr = head;
    while (curr) {
        NodeS* tmp = curr->next; // zapamiętaj następny przed usunięciem
        delete curr;
        curr = tmp;
    }
}

// ============================================================
// DODAWANIE
// ============================================================

// Dodaj na koniec - O(1) dzięki wskaźnikowi tail
void SinglyList::addEnd(int val) {
    NodeS* n = new NodeS{val, nullptr}; // nowy węzeł, next = nullptr bo będzie ostatni

    if (!head) {
        // lista była pusta - nowy węzeł jest jedynym
        head = tail = n;
    } else {
        tail->next = n; // stary ostatni wskazuje na nowy
        tail = n;       // tail przesuwa się na nowy węzeł
    }
}

// Dodaj na początek - O(1)
void SinglyList::addFront(int val) {
    NodeS* n = new NodeS{val, head}; // next nowego węzła = dotychczasowy head

    head = n;            // head przesuwa się na nowy węzeł
    if (!tail) tail = n; // jeśli lista była pusta, tail też wskazuje na nowy węzeł
}

// Dodaj na podaną pozycję - O(n) bo musimy dojść do pozycji
void SinglyList::addAt(int val, int pos) {
    if (pos <= 0) {
        addFront(val);  // pozycja 0 = dodaj na początek
        return;
    }

    // sprawdź długość listy żeby nie wyjść poza zakres
    int len = getSize();
    if (pos >= len) {
        addEnd(val);    // pozycja >= rozmiar = dodaj na koniec
        return;
    }

    // dochodzimy do węzła PRZED pozycją pos
    NodeS* curr = head;
    for (int i = 0; i < pos - 1; i++)
        curr = curr->next;

    // wstawiamy nowy węzeł między curr a curr->next
    NodeS* n = new NodeS{val, curr->next};
    curr->next = n;

    // jeśli wstawiliśmy na koniec, aktualizujemy tail
    if (!n->next) tail = n;
}

// ============================================================
// USUWANIE
// ============================================================

// Usuń pierwszy - O(1)
void SinglyList::removeFront() {
    if (!head) return; // pusta lista - nic nie rób

    NodeS* tmp = head;  // zapamiętaj stary head
    head = head->next;  // przesuń head na drugi element

    if (!head) tail = nullptr; // lista stała się pusta - zeruj też tail

    delete tmp; // zwolnij pamięć starego head
}

// Usuń ostatni - O(n) bo nie mamy wskaźnika na przedostatni
void SinglyList::removeEnd() {
    if (!head) return;

    if (head == tail) {
        // lista ma tylko jeden element
        delete head;
        head = tail = nullptr;
        return;
    }

    // musimy dojść do węzła PRZED ostatnim
    NodeS* curr = head;
    while (curr->next != tail)
        curr = curr->next;

    delete tail;         // usuń ostatni
    tail = curr;         // nowy ostatni to curr
    tail->next = nullptr; // upewnij się że next = nullptr
}

// Usuń z podanej pozycji - O(n)
void SinglyList::removeAt(int pos) {
    if (!head) return;

    if (pos <= 0) {
        removeFront();
        return;
    }

    int len = getSize();
    if (pos >= len) pos = len - 1; // zabezpieczenie przed wyjściem poza zakres

    // dochodzimy do węzła PRZED usuwanym
    NodeS* curr = head;
    for (int i = 0; i < pos - 1; i++)
        curr = curr->next;

    NodeS* tmp = curr->next; // węzeł do usunięcia
    curr->next = tmp->next;  // "przeskocz" przez usuwany węzeł

    if (!curr->next) tail = curr; // jeśli usunęliśmy ostatni, aktualizuj tail

    delete tmp;
}

// ============================================================
// WYSZUKIWANIE - O(n) przeszukiwanie od head do tail
// ============================================================
int SinglyList::search(int val) {
    NodeS* curr = head;
    int i = 0;

    while (curr) {
        if (curr->data == val) return i; // znaleziono - zwróć indeks
        curr = curr->next;
        i++;
    }
    return -1; // nie znaleziono
}

// ============================================================
// WYŚWIETLANIE - O(n)
// ============================================================
void SinglyList::display() {
    if (!head) {
        cout << "(pusta lista)\n";
        return;
    }

    NodeS* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

// ============================================================
// GENEROWANIE - czyści listę i wypełnia n losowymi liczbami 0-9999
// ============================================================
void SinglyList::generate(int n) {
    // usuń wszystkie obecne węzły
    while (head) removeFront();

    for (int i = 0; i < n; i++)
        addEnd(rand() % 10000);
}

// ============================================================
// GETSIZE - przechodzi całą listę i liczy węzły - O(n)
// ============================================================
int SinglyList::getSize() {
    int count = 0;
    NodeS* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}
