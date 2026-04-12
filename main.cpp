#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ArrayList.hpp"
#include "SinglyList.hpp"
#include "DoublyList.hpp"
#include "Benchmark.hpp"

using namespace std;

// ============================================================
// MENU POMOCNICZE - wyświetla opcje operacji (identyczne dla każdej struktury)
// ============================================================
void wyswietlMenu(const string& nazwa) {
    cout << "\n=== " << nazwa << " ===\n";
    cout << "1. Generuj losowo\n";
    cout << "2. Dodaj na poczatek\n";
    cout << "3. Dodaj na koniec\n";
    cout << "4. Dodaj na pozycje\n";
    cout << "5. Usun z poczatku\n";
    cout << "6. Usun z konca\n";
    cout << "7. Usun z pozycji\n";
    cout << "8. Szukaj\n";
    cout << "9. Wyswietl\n";
    cout << "10. Benchmark (automatyczny pomiar)\n";
    cout << "0. Powrot\n";
    cout << "Wybor: ";
}

// ============================================================
// BENCHMARK - automatyczny pomiar dla 8 rozmiarów danych
// Mierzy czas BEZ żadnego cin/cout wewnątrz lambdy
// Wyniki zapisywane do wyniki.csv
// ============================================================
void runBenchmark() {
    // 8 różnych rozmiarów zgodnie z wymaganiami (od 5000 wzwyż)
    int rozmiary[] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    int iloscRozmiarow = 8;
    int powtorzenia = 5; // każdy pomiar uśredniamy z 5 prób

    cout << "\nBenchmark start...\n";

    for (int r = 0; r < iloscRozmiarow; r++) {
        int n = rozmiary[r];
        cout << "Rozmiar: " << n << "...\n";

        // ---- ARRAYLIST ----
        {
            ArrayList arr;
            arr.generate(n); // wypełnij danymi przed pomiarem

            // Dodawanie na początek
            long long suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                ArrayList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.addFront(rand() % 10000); });
            }
            Benchmark::save("ArrayList", "addFront", n, suma / powtorzenia);

            // Dodawanie na koniec
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                ArrayList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.addEnd(rand() % 10000); });
            }
            Benchmark::save("ArrayList", "addEnd", n, suma / powtorzenia);

            // Dodawanie na losową pozycję
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                ArrayList tmp; tmp.generate(n);
                int pos = rand() % (n + 1);
                suma += Benchmark::measure([&]() { tmp.addAt(rand() % 10000, pos); });
            }
            Benchmark::save("ArrayList", "addAt", n, suma / powtorzenia);

            // Usuwanie z początku
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                ArrayList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.removeFront(); });
            }
            Benchmark::save("ArrayList", "removeFront", n, suma / powtorzenia);

            // Usuwanie z końca
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                ArrayList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.removeEnd(); });
            }
            Benchmark::save("ArrayList", "removeEnd", n, suma / powtorzenia);

            // Usuwanie z losowej pozycji
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                ArrayList tmp; tmp.generate(n);
                int pos = rand() % n;
                suma += Benchmark::measure([&]() { tmp.removeAt(pos); });
            }
            Benchmark::save("ArrayList", "removeAt", n, suma / powtorzenia);

            // Wyszukiwanie
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                ArrayList tmp; tmp.generate(n);
                int val = rand() % 10000;
                suma += Benchmark::measure([&]() { tmp.search(val); });
            }
            Benchmark::save("ArrayList", "search", n, suma / powtorzenia);
        }

        // ---- SINGLYLIST ----
        {
            // addFront
            long long suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                SinglyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.addFront(rand() % 10000); });
            }
            Benchmark::save("SinglyList", "addFront", n, suma / powtorzenia);

            // addEnd
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                SinglyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.addEnd(rand() % 10000); });
            }
            Benchmark::save("SinglyList", "addEnd", n, suma / powtorzenia);

            // addAt
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                SinglyList tmp; tmp.generate(n);
                int pos = rand() % (n + 1);
                suma += Benchmark::measure([&]() { tmp.addAt(rand() % 10000, pos); });
            }
            Benchmark::save("SinglyList", "addAt", n, suma / powtorzenia);

            // removeFront
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                SinglyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.removeFront(); });
            }
            Benchmark::save("SinglyList", "removeFront", n, suma / powtorzenia);

            // removeEnd
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                SinglyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.removeEnd(); });
            }
            Benchmark::save("SinglyList", "removeEnd", n, suma / powtorzenia);

            // removeAt
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                SinglyList tmp; tmp.generate(n);
                int pos = rand() % n;
                suma += Benchmark::measure([&]() { tmp.removeAt(pos); });
            }
            Benchmark::save("SinglyList", "removeAt", n, suma / powtorzenia);

            // search
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                SinglyList tmp; tmp.generate(n);
                int val = rand() % 10000;
                suma += Benchmark::measure([&]() { tmp.search(val); });
            }
            Benchmark::save("SinglyList", "search", n, suma / powtorzenia);
        }

        // ---- DOUBLYLIST ----
        {
            // addFront
            long long suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                DoublyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.addFront(rand() % 10000); });
            }
            Benchmark::save("DoublyList", "addFront", n, suma / powtorzenia);

            // addEnd
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                DoublyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.addEnd(rand() % 10000); });
            }
            Benchmark::save("DoublyList", "addEnd", n, suma / powtorzenia);

            // addAt
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                DoublyList tmp; tmp.generate(n);
                int pos = rand() % (n + 1);
                suma += Benchmark::measure([&]() { tmp.addAt(rand() % 10000, pos); });
            }
            Benchmark::save("DoublyList", "addAt", n, suma / powtorzenia);

            // removeFront
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                DoublyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.removeFront(); });
            }
            Benchmark::save("DoublyList", "removeFront", n, suma / powtorzenia);

            // removeEnd
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                DoublyList tmp; tmp.generate(n);
                suma += Benchmark::measure([&]() { tmp.removeEnd(); });
            }
            Benchmark::save("DoublyList", "removeEnd", n, suma / powtorzenia);

            // removeAt
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                DoublyList tmp; tmp.generate(n);
                int pos = rand() % n;
                suma += Benchmark::measure([&]() { tmp.removeAt(pos); });
            }
            Benchmark::save("DoublyList", "removeAt", n, suma / powtorzenia);

            // search
            suma = 0;
            for (int p = 0; p < powtorzenia; p++) {
                DoublyList tmp; tmp.generate(n);
                int val = rand() % 10000;
                suma += Benchmark::measure([&]() { tmp.search(val); });
            }
            Benchmark::save("DoublyList", "search", n, suma / powtorzenia);
        }
    }

    cout << "Benchmark zakończony! Wyniki zapisane w wyniki.csv\n";
}

// ============================================================
// MAIN - dwupoziomowe menu
// ============================================================
int main() {
    srand(time(NULL)); // inicjalizacja generatora losowego

    ArrayList arr;   // obiekt tablicy dynamicznej
    SinglyList sl;   // obiekt listy jednokierunkowej
    DoublyList dl;   // obiekt listy dwukierunkowej

    int struktura, operacja;

    while (true) {
        // ---- POZIOM 1: wybór struktury ----
        cout << "\n=== WYBIERZ STRUKTURE ===\n";
        cout << "1. Tablica dynamiczna\n";
        cout << "2. Lista jednokierunkowa\n";
        cout << "3. Lista dwukierunkowa\n";
        cout << "4. Benchmark (pomiar wszystkich)\n";
        cout << "0. Wyjscie\n";
        cout << "Wybor: ";
        cin >> struktura;

        if (struktura == 0) break;
        if (struktura == 4) { runBenchmark(); continue; }

        // ---- POZIOM 2: operacja na wybranej strukturze ----
        while (true) {
            if (struktura == 1) wyswietlMenu("TABLICA DYNAMICZNA");
            if (struktura == 2) wyswietlMenu("LISTA JEDNOKIERUNKOWA");
            if (struktura == 3) wyswietlMenu("LISTA DWUKIERUNKOWA");

            cin >> operacja;
            if (operacja == 0) break;

            int n, val, pos;

            // ---- TABLICA ----
            if (struktura == 1) {
                if (operacja == 1) {
                    cout << "Podaj ilosc elementow: ";
                    cin >> n;
                    arr.generate(n);
                    cout << "Wygenerowano " << n << " elementow.\n";
                }
                else if (operacja == 2) {
                    val = rand() % 10000;                  // losuj wartość 0-9999
                    arr.addFront(val);
                    cout << "Dodano " << val << " na poczatek.\n";
                }
                else if (operacja == 3) {
                    val = rand() % 10000;
                    arr.addEnd(val);
                    cout << "Dodano " << val << " na koniec.\n";
                }
                else if (operacja == 4) {
                    cout << "Podaj pozycje: ";
                    cin >> pos;
                    val = rand() % 10000;
                    arr.addAt(val, pos);
                    cout << "Dodano " << val << " na pozycje " << pos << ".\n";
                }
                else if (operacja == 5) { arr.removeFront(); cout << "Usunieto z poczatku.\n"; }
                else if (operacja == 6) { arr.removeEnd();   cout << "Usunieto z konca.\n"; }
                else if (operacja == 7) {
                    cout << "Podaj pozycje: ";
                    cin >> pos;
                    arr.removeAt(pos);
                    cout << "Usunieto z pozycji " << pos << ".\n";
                }
                else if (operacja == 8) {
                    cout << "Podaj szukana wartosc: ";
                    cin >> val;
                    int idx = arr.search(val);
                    if (idx == -1) cout << "Nie znaleziono.\n";
                    else cout << "Znaleziono na indeksie: " << idx << "\n";
                }
                else if (operacja == 9) { arr.display(); }
                else if (operacja == 10) { runBenchmark(); }
            }

            // ---- LISTA JEDNOKIERUNKOWA ----
            else if (struktura == 2) {
                if (operacja == 1) {
                    cout << "Podaj ilosc elementow: ";
                    cin >> n;
                    sl.generate(n);
                    cout << "Wygenerowano " << n << " elementow.\n";
                }
                else if (operacja == 2) {
                    val = rand() % 10000;
                    sl.addFront(val);
                    cout << "Dodano " << val << " na poczatek.\n";
                }
                else if (operacja == 3) {
                    val = rand() % 10000;
                    sl.addEnd(val);
                    cout << "Dodano " << val << " na koniec.\n";
                }
                else if (operacja == 4) {
                    cout << "Podaj pozycje: ";
                    cin >> pos;
                    val = rand() % 10000;
                    sl.addAt(val, pos);
                    cout << "Dodano " << val << " na pozycje " << pos << ".\n";
                }
                else if (operacja == 5) { sl.removeFront(); cout << "Usunieto z poczatku.\n"; }
                else if (operacja == 6) { sl.removeEnd();   cout << "Usunieto z konca.\n"; }
                else if (operacja == 7) {
                    cout << "Podaj pozycje: ";
                    cin >> pos;
                    sl.removeAt(pos);
                    cout << "Usunieto z pozycji " << pos << ".\n";
                }
                else if (operacja == 8) {
                    cout << "Podaj szukana wartosc: ";
                    cin >> val;
                    int idx = sl.search(val);
                    if (idx == -1) cout << "Nie znaleziono.\n";
                    else cout << "Znaleziono na indeksie: " << idx << "\n";
                }
                else if (operacja == 9) { sl.display(); }
                else if (operacja == 10) { runBenchmark(); }
            }

            // ---- LISTA DWUKIERUNKOWA ----
            else if (struktura == 3) {
                if (operacja == 1) {
                    cout << "Podaj ilosc elementow: ";
                    cin >> n;
                    dl.generate(n);
                    cout << "Wygenerowano " << n << " elementow.\n";
                }
                else if (operacja == 2) {
                    val = rand() % 10000;
                    dl.addFront(val);
                    cout << "Dodano " << val << " na poczatek.\n";
                }
                else if (operacja == 3) {
                    val = rand() % 10000;
                    dl.addEnd(val);
                    cout << "Dodano " << val << " na koniec.\n";
                }
                else if (operacja == 4) {
                    cout << "Podaj pozycje: ";
                    cin >> pos;
                    val = rand() % 10000;
                    dl.addAt(val, pos);
                    cout << "Dodano " << val << " na pozycje " << pos << ".\n";
                }
                else if (operacja == 5) { dl.removeFront(); cout << "Usunieto z poczatku.\n"; }
                else if (operacja == 6) { dl.removeEnd();   cout << "Usunieto z konca.\n"; }
                else if (operacja == 7) {
                    cout << "Podaj pozycje: ";
                    cin >> pos;
                    dl.removeAt(pos);
                    cout << "Usunieto z pozycji " << pos << ".\n";
                }
                else if (operacja == 8) {
                    cout << "Podaj szukana wartosc: ";
                    cin >> val;
                    int idx = dl.search(val);
                    if (idx == -1) cout << "Nie znaleziono.\n";
                    else cout << "Znaleziono na indeksie: " << idx << "\n";
                }
                else if (operacja == 9) { dl.display(); }
                else if (operacja == 10) { runBenchmark(); }
            }
        }
    }

    return 0;
}
