#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cur_order = {1, 2, 3};
    vector<int> num_guessed = {0, 0, 0};

    for (int i = 0; i < n; i ++){
        int swap1, swap2, guess;
        cin >> swap1 >> swap2 >> guess;
        swap(cur_order[swap1 - 1], cur_order[swap2 - 1]);
        num_guessed[cur_order[guess - 1] - 1] ++;
    }
    
    cout << *max_element(num_guessed.begin(), num_guessed.end()) << endl;
}