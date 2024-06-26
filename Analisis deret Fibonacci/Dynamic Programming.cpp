#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibonacciDynamicProgramming(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    vector<int> values = {10, 25, 30, 40, 50};
    vector<long long> dpTimes;

    for (int n : values) {
        auto start = high_resolution_clock::now();
        int fibonacciDynamicProgrammingResult = fibonacciDynamicProgramming(n);
        auto stop = high_resolution_clock::now();
        auto dpDuration = duration_cast<microseconds>(stop - start);
        dpTimes.push_back(dpDuration.count());

        cout << "Hasil Fibonacci untuk n = " << n << ":\n";
        cout << "Dynamic Programming : " << fibonacciDynamicProgrammingResult << ", Waktu eksekusi : " << dpDuration.count() << " microseconds\n";
        cout << endl;
    }

    return 0;
}
