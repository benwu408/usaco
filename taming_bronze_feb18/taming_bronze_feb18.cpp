#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    bool works = true;
    int n;
    cin >> n;
    vector<int> breakout(n);
    fill(breakout.begin(), breakout.end(), 1);
    breakout[0] = 2; 
    // 1 -> ambiguous, 0 -> no breakout, 2 -> breakout

    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        if (x >= 0){
            if (i - x >= 0){
                if (breakout[i - x] == 0){
                    cout << -1 << endl;
                    works = false;
                    break;
                }
                breakout[i - x] = 2;
                for (int f = 1 + i - x; f <= i; f ++) {
                    if (breakout[f] == 2){
                        cout << -1 << endl;
                        works = false;
                        break;
                    }
                    breakout[f] = 0;
                }
            }

        }
        if (!works) break;
    }
    if (works){
        int min = 0;
        int max = 0;
        for (auto p : breakout){
            if (p == 2){
                min ++;
                max ++;
            }
            else if (p == 1) max ++;
        }

        cout << min << " " << max << endl;
    }
}