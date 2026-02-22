#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;

    int pref = 0;

    vector<long long> low;
    low.push_back(-1);
    low.push_back(-1);
    low.push_back(-1);
    low.push_back(-1);
    low.push_back(-1);
    low.push_back(-1);
    low.push_back(-1);

    vector<long long> high(7);


    for (int i = 0; i < n; i ++){
        long long x; cin >> x;
        pref += x;
        pref %= 7;
        if (low[pref] == -1) low[pref] = i;
        high[pref] = i;
    }
    long long most = 0;
    for (int i = 0; i < 7; i ++) most = max(most, high[i] - low[i]);
    cout << most << endl;
}