#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void ukurWaktuSort(vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr);
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
