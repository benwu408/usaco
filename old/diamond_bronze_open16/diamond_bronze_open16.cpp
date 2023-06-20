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
    int end = n - 1;
    int max = 0;
    for (int i = 0; i < n; i ++){
        int diamond = diamonds[i];
        if (diamond - diamonds[begin] > k){
            if (i - begin > max){
                max = i - begin;
            }
            begin += 1;
            
        }
    }
    if (max == 0){
        max = n;
    }
    cout << max << endl;
}