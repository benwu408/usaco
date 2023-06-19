#include <iostream>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    long long total = 0;
    long long previous;
    cin >> previous;
    long long current_start = previous;
    long long x;
    for (int i = 1; i < n - 1; i ++) {
        cin >> x;
        if (x - previous - 1 > k) {
            total += k + (previous - current_start) + 1;
            current_start = x;
        }
        previous = x;
    }
    cin >> x;
    if ((x - previous) < k + 1) {
        total += 1 + k + (x - current_start);

    }
    else {
        total += k + 1 + (previous - current_start) + k + 1;

    }
    cout << total;
}