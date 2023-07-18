#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> diamonds;

    for (int i = 0; i < n; i ++){
        int diamond;
        cin >> diamond;
        diamonds.push_back(diamond);
    }
    sort(diamonds.begin(), diamonds.end());

    int begin = 0;
    int maxRange = 0;
    for (int i = 0; i < n; i ++){
        if (diamonds[i] - diamonds[begin] > k){
            maxRange = max(maxRange, i - begin);
            begin ++;
            
        }
    }
    if (maxRange == 0){
        maxRange = n;
    }
    cout << maxRange << endl;
}