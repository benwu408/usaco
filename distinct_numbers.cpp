#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> numbers;
    for (int i = 0; i < n; i ++){
        int num;
        cin >> num;
        numbers.insert(num);
    }
    cout << numbers.size() << endl;
}