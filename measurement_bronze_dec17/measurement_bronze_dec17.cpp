#include <set>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num_changes = 0;
    map<string, int> rates {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
    map<int, pair<string, int> > changes;
    
    for (int i = 0; i < n; i ++){
        int a, c;
        string b;
        cin >> a >> b >> c;

        changes[a] = make_pair(b, c);
    }
    int last = 0;

    // for (auto cow : consumed){
    //     cout << cow.first << " " << cow.second << endl;
    // }
    set<string> top {"Bessie", "Elsie", "Mildred"};

    for (auto change : changes){
        rates[change.second.first] += change.second.second;
        pair<int, set<string> > cur_max = make_pair(0, set<string>{});
        for (auto cow : rates){
            // cout << cow.first << " " << cow.second << endl;
            if (cow.second > cur_max.first) cur_max = make_pair(cow.second, set<string>{cow.first});
            else if (cow.second == cur_max.first) {
                cur_max.second.insert(cow.first);
            }
        }

        if (cur_max.second != top){
            num_changes ++;
            top = cur_max.second;
        }

    
    }
    cout << num_changes << endl;
}