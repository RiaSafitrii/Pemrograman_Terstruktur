#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibonacciRekursif(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRekursif(n - 1) + fibonacciRekursif(n - 2);
}


int main() {
    vector<int> values = {10, 25, 30, 40, 50};
    vector<long long> rekursifTimes;
    vector<long long> dpTimes;

    for (int n : values) {
        auto start = high_resolution_clock::now();
        int fibonacciRekursifResult = fibonacciRekursif(n);
        auto stop = high_resolution_clock::now();
        auto rekursifDuration = duration_cast<microseconds>(stop - start);
        rekursifTimes.push_back(rekursifDuration.count());


        cout << "Hasil Fibonacci untuk n = " << n << ":\n";
        cout << "Rekursif : " << fibonacciRekursifResult << ", Waktu eksekusi : " << rekursifDuration.count() << " microseconds\n";
        cout << endl;
    }

    return 0;
}
