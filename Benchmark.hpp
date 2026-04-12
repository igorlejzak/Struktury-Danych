#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

// Klasa pomocnicza do pomiaru i zapisywania czasów operacji.
// Wszystkie metody są statyczne - nie trzeba tworzyć obiektu Benchmark.
class Benchmark {
public:
    // measure - mierzy czas wykonania dowolnej funkcji/lambdy
    // Typ Func to tzw. template - działa z każdą funkcją bez argumentów
    // Zwraca czas w mikrosekundach (us)
    template<typename Func>
    static long long measure(Func f) {
        auto start = high_resolution_clock::now(); // zapamiętaj czas przed
        f();                                        // wykonaj mierzoną funkcję
        auto end = high_resolution_clock::now();   // zapamiętaj czas po
        return duration_cast<microseconds>(end - start).count(); // oblicz różnicę
    }

    // save - dopisuje wiersz do pliku CSV (nie nadpisuje, tylko dopisuje)
    // Format: NazwaStruktury,NazwaOperacji,RozmiarDanych,CzasWMikrosekundach
    static void save(const string& struktura, const string& operacja, int rozmiar, long long czas) {
        ofstream file("wyniki.csv", ios::app); // ios::app = dopisz na końcu pliku
        file << struktura << "," << operacja << "," << rozmiar << "," << czas << "\n";
        file.close();
    }
};

#endif
