#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void ukurWaktuSort(vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
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
        cout << "Mengurutkan array terururt : " << size << " \n";
        ukurWaktuSort(arr);
        cout << endl;
        
        cout << "=========================================" << endl;

    }

    return 0;
}
