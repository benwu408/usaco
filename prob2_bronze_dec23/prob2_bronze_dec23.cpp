#include <set>
#include <map>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n; cin >> n;
    int initial = 0;
    vector<int> cows;
    vector<pair<int, bool> > groups;
    int current = 0;
    for (int i = 0; i < n; i ++){
        char x; cin >> x; int a = x - '0';
        if (a == 1) {
            current ++;
            initial ++;
            if (i == n - 1){
                groups.push_back({current, true});
                // cout << current << " " << true << endl;
            }
        }
        else if (current > 0){
            bool left = current == i;
            groups.push_back({current, left});
            // cout << current << " " << left << endl;
            current = 0;
        }
    }
    int min_initial = initial;
    bool done = false;
    for (float i = 1; i <= n; i += 2){
        // cout << i << endl;
        int total = 0;
        for (auto group : groups){
            // cout << "a" << endl;
            // cout << group.first << " " << group.second << endl;
            if (!group.second){
                if (i > group.first){
                    done = true;
                    break;
                }
                total += ceil(group.first/i);
                // cout << ceil(group.first/i) << endl;
            }
            else{
                if (i > 2 * (group.first - 1) + 1){
                    done = true;
                    break;
                }
                if (i > group.first){
                    total += 1;
                }
                else{
                    total += ceil(group.first/i);
                }
            }
        }
        if (done) break;
        // cout << "total: " << total << endl;
        min_initial = min(min_initial, total);
    }

    cout << min_initial << endl;
}