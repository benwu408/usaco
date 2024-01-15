#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

// struct Lifeguard {
//     int s, e;
// };

// int main(){
//     int n;
//     cin >> n;
//     unordered_map<int, vector<int> > shifts;
//     unordered_map<int, int> lifeguard_single_shifts;
//     int least = INT32_MAX;
//     for (int i = 0; i < n; i ++){
//         int s, e;
//         cin >> s >> e;
//         lifeguard_single_shifts[i] = 0;
//         for (int x = s; x < e; x ++){
//             if (shifts.find(x) == shifts.end()){
//                 lifeguard_single_shifts[i] ++;
//                 shifts[x] = vector<int> {i};
//             }
//             else{
//                 if (shifts[x].size() == 1){
//                     lifeguard_single_shifts[shifts[x][0]] --;
//                     least = min(least, lifeguard_single_shifts[shifts[x][0]]);
//                 }
//                 shifts[x].push_back(x);
//             }
//         }
//         least = min(least, lifeguard_single_shifts[i]);
//     }

    

//     // for (auto lifeguard : lifeguard_single_shifts){
//     //     least = min(least, lifeguard.second);
//     // }
//     cout << shifts.size() - least << endl;
// }

int main() {
    int n;
    cin >> n;
    map<int, pair<int, bool> > lifeguard_log;
    vector<int> alone(n);
    int start = INT32_MAX;
    int total = 0;

    for (int i = 0; i < n; i ++){
        int s, e;
        cin >> s >> e;
        start = min(start, s);
        lifeguard_log[s] = make_pair(i, true);
        lifeguard_log[e] = make_pair(i, false);
    }
    // for (auto lifeguard : lifeguard_log){
    //     cout << "time: " << lifeguard.first << " guard number: " << lifeguard.second.first << " " << lifeguard.second.second << endl;
    // }
    set<int> current;
    int last = start;
    // cout << last << endl;
    for (auto event : lifeguard_log){
        // cout << "time: " << event.first << " guard number: " << event.second.first << " " << event.second.second << endl;
        // for (auto guard : current) cout << guard << endl;
        if (current.size() > 0) total += event.first - last;
        if (current.size() == 1) alone[*current.begin()] += event.first - last;
        if (event.second.second){
            current.insert(event.second.first);
        }
        else{
            current.erase(current.find(event.second.first));
        }
        last = event.first;
    }
    // cout << "total: " << total << endl;
    // for (auto lifeguard : alone){
    //     cout << lifeguard << endl;
    // }
    cout << total - *min_element(alone.begin(), alone.end()) << endl;
}