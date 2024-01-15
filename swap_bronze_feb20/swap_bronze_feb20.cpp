#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, k, a1, a2, b1, b2; cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    vector<int> cows(n);
    for (int i = 0; i < n; i ++) cows[i] = i + 1;
    int count = 0;
    vector<int> cows1 = cows;
    do{
        reverse(cows1.begin() + (a1 - 1), cows1.begin() + a2);
        reverse(cows1.begin() + (b1 - 1), cows1.begin() + b2);
        count ++;
    }
    while (cows != cows1);
    for (int i = 0; i < k % count; i ++){
        reverse(cows.begin() + (a1 - 1), cows.begin() + a2);
        reverse(cows.begin() + (b1 - 1), cows.begin() + b2);
    }
    for (auto it : cows) cout << it << endl;
}