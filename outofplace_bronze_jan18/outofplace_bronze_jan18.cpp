#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> cows;
    int previous = 0;
    int diff;

    for (int i = 0; i < n; i ++){
        int a; cin >> a; cows.push_back(a);
        if (a < previous){
            diff = i;
        }
        previous = a;
    }
    int cow1 = cows[diff - 1];
    int cow2 = cows[diff];
    int doubles = 0;
    int swaps = 1;

    if (diff > 1){
        for (int i = diff - 2; i > -1; i --){
            if (cows[i] <= cow2){
                break;
            }
            if (cows[i] == cows[i + 1]){
                doubles ++;
            }
            swaps ++;
        }
    }
    if (diff < n - 1){
        for (int i = diff + 1; i < n; i ++){
            if (cows[i] >= cow1){
                break;
            }
            if (cows[i] == cows[i - 1]){
                doubles ++;
            }
            swaps ++;
        }
    }

    cout << swaps - doubles << endl;
}