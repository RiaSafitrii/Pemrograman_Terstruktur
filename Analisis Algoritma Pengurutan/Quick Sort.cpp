#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void ukurWaktuSort(vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
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
        cout << "Mengurutkan array terurut terbalik :" << size << " \n";
        ukurWaktuSort(arr);
        cout << endl;

        sort(arr.begin(), arr.end());
        cout << "Mengurutkan array terurut :" << size << " \n";
        ukurWaktuSort(arr);
        cout << endl;
        
        cout << "=========================================" << endl;
    }

    return 0;
}
