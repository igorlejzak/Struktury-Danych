#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

// klasa do mierzenia i zapisywania czasow operacji
// wszystkie metody sa statyczne - nie trzeba tworzyc obiektu
class Benchmark {
public:
    // zmierz czas wykonania dowolnej funkcji w nanosekundach [ns]
    // Func to szablon (template) - pozwala przekazać dowolny typ wywoływalny
    // (np. funkcję, lambda) bez argumentów
    template<typename Func>
    static long long ZmierzCzas(Func Funkcja) {
        auto CzasPrzed = high_resolution_clock::now(); // czas przed wykonaniem
        Funkcja();                                      // wykonaj mierzona operacje
        auto CzasPo = high_resolution_clock::now();    // czas po wykonaniu
        return duration_cast<nanoseconds>(CzasPo - CzasPrzed).count(); // roznica w ns
    }

    // zapisz wynik do pliku CSV (dopisuje na koniec, nie nadpisuje)
    // format wiersza: NazwaStruktury,NazwaOperacji,Rozmiar,CzasNs
    static void Zapisz(const string& NazwaStruktury, const string& NazwaOperacji, int Rozmiar, long long CzasNs) {
        ofstream Plik("wyniki.csv", ios::app); // ios::app = dopisz na koncu
        Plik << NazwaStruktury << "," << NazwaOperacji << "," << Rozmiar << "," << CzasNs << "\n";
        Plik.close();
    }
};

#endif
