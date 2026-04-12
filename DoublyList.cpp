#include "DoublyList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// ============================================================
// KONSTRUKTOR
// ============================================================
DoublyList::DoublyList() {
    head = nullptr;
    tail = nullptr;
}

// ============================================================
// DESTRUKTOR - zwalniamy wszystkie węzły
// ============================================================
DoublyList::~DoublyList() {
    NodeD* curr = head;
    while (curr) {
        NodeD* tmp = curr->next;
        delete curr;
        curr = tmp;
    }
}

// ============================================================
// DODAWANIE
// ============================================================

// Dodaj na koniec - O(1) dzięki wskaźnikowi tail
void DoublyList::addEnd(int val) {
    NodeD* n = new NodeD{val, nullptr, tail}; // next=nullptr, prev=stary tail

    if (!head) {
        // lista pusta
        head = tail = n;
    } else {
        tail->next = n; // stary ostatni wskazuje next na nowy
        tail = n;       // przesuwamy tail
    }
}

// Dodaj na początek - O(1)
void DoublyList::addFront(int val) {
    NodeD* n = new NodeD{val, head, nullptr}; // next=stary head, prev=nullptr

    if (head) head->prev = n; // stary pierwszy wskazuje prev na nowy
    head = n;

    if (!tail) tail = n; // lista była pusta
}

// Dodaj na podaną pozycję - O(n)
void DoublyList::addAt(int val, int pos) {
    if (pos <= 0) {
        addFront(val);
        return;
    }

    int len = getSize();
    if (pos >= len) {
        addEnd(val);
        return;
    }

    // dochodzimy do węzła na pozycji pos (ten węzeł zostanie przesunięty w prawo)
    NodeD* curr = head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    // wstawiamy PRZED curr
    NodeD* n = new NodeD{val, curr, curr->prev};

    if (curr->prev) curr->prev->next = n; // węzeł przed curr wskazuje na nowy
    curr->prev = n;                        // curr wskazuje prev na nowy

    if (n->prev == nullptr) head = n; // jeśli wstawiliśmy na początku
}

// ============================================================
// USUWANIE
// ============================================================

// Usuń pierwszy - O(1)
void DoublyList::removeFront() {
    if (!head) return;

    NodeD* tmp = head;
    head = head->next;

    if (head) head->prev = nullptr; // nowy pierwszy nie ma poprzednika
    else tail = nullptr;             // lista stała się pusta

    delete tmp;
}

// Usuń ostatni - O(1) dzięki wskaźnikowi prev w węźle tail!
// (W liście jednokierunkowej to było O(n))
void DoublyList::removeEnd() {
    if (!tail) return;

    NodeD* tmp = tail;
    tail = tail->prev;

    if (tail) tail->next = nullptr; // nowy ostatni nie ma następnika
    else head = nullptr;             // lista stała się pusta

    delete tmp;
}

// Usuń z podanej pozycji - O(n)
void DoublyList::removeAt(int pos) {
    if (!head) return;

    if (pos <= 0) {
        removeFront();
        return;
    }

    int len = getSize();
    if (pos >= len) pos = len - 1;

    // dochodzimy do węzła na pozycji pos
    NodeD* curr = head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    // "przepinamy" sąsiadów żeby pominęli curr
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;

    if (curr->next) curr->next->prev = curr->prev;
    else tail = curr->prev;

    delete curr;
}

// ============================================================
// WYSZUKIWANIE - O(n)
// ============================================================
int DoublyList::search(int val) {
    NodeD* curr = head;
    int i = 0;

    while (curr) {
        if (curr->data == val) return i;
        curr = curr->next;
        i++;
    }
    return -1;
}

// ============================================================
// WYŚWIETLANIE - O(n)
// ============================================================
void DoublyList::display() {
    if (!head) {
        cout << "(pusta lista)\n";
        return;
    }

    NodeD* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

// ============================================================
// GENEROWANIE - czyści listę i wypełnia n losowymi liczbami 0-9999
// ============================================================
void DoublyList::generate(int n) {
    while (head) removeFront(); // usuń wszystko

    for (int i = 0; i < n; i++)
        addEnd(rand() % 10000);
}

// ============================================================
// GETSIZE - O(n)
// ============================================================
int DoublyList::getSize() {
    int count = 0;
    NodeD* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}
