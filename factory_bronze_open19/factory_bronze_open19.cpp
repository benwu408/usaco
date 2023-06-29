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


    for (int i = 0; i < n; i ++){
        int begin;
        int end;
        cin >> begin >> end;

        connects[end] = set<int> {begin};
    }

    bool change = true;
    while (change){
        map<int, set<int> > new_connects = connects;
        for (auto it : connects){
            for (auto itr : it.second){
                for (auto itt : connects[itr]){
                    new_connects[it.first].insert(itt);
                }
            }
        }
        if (new_connects == connects){
            change = false;
        } else connects = new_connects;
    }
    bool found = false;
    for (auto it : connects){
        if (it.second.size() == n - 1) {
            cout << it.first << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << -1 << endl;
}