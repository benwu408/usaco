#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_set>
using namespace std;

void run(){
    int n, q, c;
    cin >> n >> q >> c;

    vector<int> scores(n);

    vector<int> can_change(n);

    vector<pair<int, int> > comps;

    vector<int> greatest(n);

    int most = -1;

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        scores[i] = x;
        most = max(most, x);
        if (x == 0) can_change[i] = 1;
        greatest[i] = most; 
    }

    // for (int i = 0; i < n - 1; i ++) cout << scores[i] << " ";
    // cout << scores[n - 1] << endl;
    for (int i = 0; i < q; i ++){
        int a, h; cin >> a >> h;
        a --; h --;
        comps.push_back({h, a});
    }
    sort(comps.begin(), comps.end());

    int new_max = 0;
    bool changed = false;
    do{
        changed = false;
        for (auto it : comps){
            if (scores[it.first] <= greatest[it.second]) {
                changed = true;
                if (can_change[it.first] == 0|| greatest[it.second] == c){
                    cout << -1 << endl;
                    return;
                }
                else if (scores[it.first] == scores[it.second] && scores[it.first] == 0){
                    if (c == 1){
                        cout << -1 << endl;
                        return;
                    }
                    else{
                        scores[it.first] = 2;
                        scores[it.second] = 1;
                    }
                }
                else scores[it.first] = greatest[it.second] + 1;
                for (int i = it.first; i < n; i ++){
                    if (greatest[i] >= scores[it.first]) break;
                    else greatest[i] = scores[it.first];
                }
            }
            
        }
    }
    while (changed);
    for (int i = 0; i < n - 1; i ++) {
        if (scores[i] == 0) cout << 1 << " ";
        else cout << scores[i] << " ";
    }
    if (scores[n - 1] == 0) cout << 1 << endl;
    else cout << scores[n - 1] << endl;
}


int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i ++){
        run();
    }
}