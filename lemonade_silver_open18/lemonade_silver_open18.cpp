#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    int minimum = 0;
    vector<int> cows;

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        cows.push_back(x);
    }

    sort(cows.begin(), cows.end(), greater<int> ());

    for (int i = 0; i < cows.size(); i ++){
        // cout << i << endl;
        if (cows[i] >= minimum) minimum ++;
    }

    cout << minimum << endl;
}