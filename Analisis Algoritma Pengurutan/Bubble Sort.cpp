#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void ukurWaktuSort(vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto durasi = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Waktu yang dibutuhkan : " << durasi.count() << " microseconds" << endl;
}

int main() {
    vector<int> ukuran = {10, 100, 500, 1000, 10000};

    for (int size : ukuran) {
        vector<int> arr(size);

        generate(arr.begin(), arr.end(), rand);
        cout << "Mengurutkan array acak : " << size << " \n";
        ukurWaktuSort(arr);
        cout << endl;
        
        sort(arr.begin(), arr.end(), greater<int>());
        cout << "Mengurutkan array terurut terbalik : " << size << " \n";
        ukurWaktuSort(arr);
        cout << endl;

        sort(arr.begin(), arr.end());
        cout << "Mengurutkan array terurut : " << size << " \n";
        ukurWaktuSort(arr);
        cout << endl;

        cout << "=========================================" << endl;
    }

    return 0;
}
