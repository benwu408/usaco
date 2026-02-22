#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> shuffle(n);

    vector<int> shuffle_find(n);

    vector<int> orig(n);

    vector<int> final(n);

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        x --;
        shuffle[i] = x;
        shuffle_find[x] = i;
    }

    for (int i = 0; i < n; i ++){
        orig[i] = shuffle_find[shuffle_find[shuffle_find[i]]];
    }

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        final[orig[i]] = x;
    }

    for (auto it : final) cout << it << endl;

}