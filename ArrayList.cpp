#include "ArrayList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// ============================================================
// KONSTRUKTOR - wywoływany automatycznie przy tworzeniu obiektu
// ============================================================
ArrayList::ArrayList() {
    capacity = 10;          // zaczynamy z miejscem na 10 elementów
    size = 0;               // na początku tablica jest pusta
    tab = new int[capacity]; // alokujemy pamięć na stercie (heap)
}

// ============================================================
// DESTRUKTOR - wywoływany automatycznie gdy obiekt jest niszczony
// Bez tego mielibyśmy wyciek pamięci (memory leak)
// ============================================================
ArrayList::~ArrayList() {
    delete[] tab; // zwalniamy pamięć którą zaalokowaliśmy w konstruktorze
}

// ============================================================
// RESIZE - podwaja pojemność tablicy gdy brakuje miejsca
// Złożoność: O(n) - musimy przekopiować wszystkie elementy
// ============================================================
void ArrayList::resize() {
    capacity *= 2;                  // podwajamy pojemność
    int* newTab = new int[capacity]; // alokujemy nową, większą tablicę

    // kopiujemy wszystkie elementy ze starej tablicy do nowej
    for (int i = 0; i < size; i++)
        newTab[i] = tab[i];

    delete[] tab;   // zwalniamy starą tablicę
    tab = newTab;   // tab teraz wskazuje na nową tablicę
}

// ============================================================
// DODAWANIE
// ============================================================

// Dodaj na koniec - O(1) zamortyzowane (rzadko robi resize)
void ArrayList::addEnd(int val) {
    if (size == capacity) resize();  // sprawdź czy jest miejsce
    tab[size] = val;                 // wstaw element na ostatnie wolne miejsce
    size++;                          // zwiększ licznik elementów
}

// Dodaj na początek - O(n) bo musimy przesunąć WSZYSTKIE elementy
void ArrayList::addFront(int val) {
    if (size == capacity) resize();

    // przesuwamy każdy element o jedno miejsce w prawo (od końca, żeby nie nadpisać)
    for (int i = size; i > 0; i--)
        tab[i] = tab[i - 1];

    tab[0] = val;  // wstawiamy nowy element na pozycję 0
    size++;
}

// Dodaj na podaną pozycję - O(n) bo przesuwamy część elementów
void ArrayList::addAt(int val, int pos) {
    if (size == capacity) resize();

    // pos musi być między 0 a size (włącznie)
    if (pos < 0) pos = 0;
    if (pos > size) pos = size;

    // przesuwamy elementy od pozycji pos w prawo
    for (int i = size; i > pos; i--)
        tab[i] = tab[i - 1];

    tab[pos] = val;
    size++;
}

// ============================================================
// USUWANIE
// ============================================================

// Usuń ostatni - O(1), wystarczy zmniejszyć licznik
void ArrayList::removeEnd() {
    if (size > 0) size--;
}

// Usuń pierwszy - O(n) bo musimy przesunąć wszystkie elementy w lewo
void ArrayList::removeFront() {
    if (size == 0) return;

    // przesuwamy każdy element o jedno miejsce w lewo
    for (int i = 0; i < size - 1; i++)
        tab[i] = tab[i + 1];

    size--;
}

// Usuń z podanej pozycji - O(n) bo przesuwamy część elementów
void ArrayList::removeAt(int pos) {
    if (size == 0) return;
    if (pos < 0) pos = 0;
    if (pos >= size) pos = size - 1;

    // przesuwamy elementy za pos o jedno miejsce w lewo (nadpisujemy usuwany)
    for (int i = pos; i < size - 1; i++)
        tab[i] = tab[i + 1];

    size--;
}

// ============================================================
// WYSZUKIWANIE - O(n) przeszukiwanie liniowe
// Zwraca indeks pierwszego wystąpienia lub -1 jeśli nie znaleziono
// ============================================================
int ArrayList::search(int val) {
    for (int i = 0; i < size; i++)
        if (tab[i] == val)
            return i;
    return -1;
}

// ============================================================
// WYŚWIETLANIE - O(n)
// ============================================================
void ArrayList::display() {
    if (size == 0) {
        cout << "(pusta tablica)\n";
        return;
    }
    for (int i = 0; i < size; i++)
        cout << tab[i] << " ";
    cout << "\n";
}

// ============================================================
// GENEROWANIE - wypełnia tablicę n losowymi liczbami z zakresu 0-9999
// Przed generowaniem czyści poprzednie dane
// ============================================================
void ArrayList::generate(int n) {
    size = 0;           // czyścimy tablicę (nie musimy kasować pamięci, tylko resetujemy licznik)
    for (int i = 0; i < n; i++)
        addEnd(rand() % 10000);  // losowe liczby 0-9999
}

// Getter - zwraca aktualną liczbę elementów
int ArrayList::getSize() {
    return size;
}
