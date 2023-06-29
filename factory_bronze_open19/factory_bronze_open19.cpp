#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

void print_vec(vector<int> vec){
    for (auto it : vec){
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    map<int, set<int> > connects;

    for (int i = 1; i <= n; i ++){
        set<int> vec;
        connects[i] = vec;
    }

    for (int i = 0; i < n; i ++){
        int begin;
        int end;
        cin >> begin >> end;

        connects[end].insert(begin);
    }

    bool change = true;
    while (change){
        map<int, set<int> > new_connects = connects;
        change = false;
        for (auto it : connects){
            for (auto itr : it.second){
                new_connects[it.first].insert(connects[itr].begin(), connects[itr].end());
                if (new_connects[it.first].size() > connects[it.first].size()) {
                    change = true;
                }
            }
        }
        connects = new_connects;
    }

    for (auto it : connects){
        if (it.second.size() == n - 1) {
            cout << it.first << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
}