#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec (n);
    vector<int> correct (n);
    iota(vec.begin(), vec.end(), 1);

    for (int i = 0; i < n; i++) {
        int a, b, guess;
        cin >> a >> b >> guess;

        int temp = vec[a - 1];
        vec[a - 1] = vec[b - 1];
        vec[b - 1] = temp;
        
        correct[vec[guess - 1]]++;
    }

    cout << *(max_element(correct.begin(), correct.end())) << endl;
}