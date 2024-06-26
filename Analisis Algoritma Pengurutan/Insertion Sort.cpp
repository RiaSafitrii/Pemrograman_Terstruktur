#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void ukurWaktu(vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Waktu yang dibutuhkan : " << duration.count() << " microseconds" << endl;
}

int main() {
	vector<int> sizes = {10, 100, 500, 1000, 10000};
    
    for (int size : sizes) {
        vector<int> arr(size);
        
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000;
        }
        cout << "Mengurutkan array acak : " << size << " \n";
        ukurWaktu(arr);
        cout << endl;

        sort(arr.begin(), arr.end(), std::greater<int>());
        cout << "Mengurutkan array terurut terbalik : " << size << " \n";
        ukurWaktu(arr);
        cout << endl;

        sort(arr.begin(), arr.end());
        cout << "Mengurutkan array terurut : " << size << " \n";
        ukurWaktu(arr);
        cout << endl;

        cout << "=========================================" << endl;
    }
    
    return 0;
}