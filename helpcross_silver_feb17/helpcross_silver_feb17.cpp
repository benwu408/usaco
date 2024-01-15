#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

// bool compareLen(const pair<pair<int, int>, set<int> >& a, pair<pair<int, int>, set<int> >& b){
//     return (a.second.size() < b.second.size());
// }

int main(){
    int c, n;
    cin >> c >> n;

    multiset<int> chickens;

    multiset<pair<int, int> > cows;

    multiset<pair<int, int> > used_cows;
    
    int dont_work = 0;
    int works = 0;

    for (int i = 0; i < c; i ++){
        int a;
        cin >> a;
        chickens.insert(a);
    }

    for (int i = 0; i < n; i ++){
        int a, b;
        cin >> a >> b;
        cows.insert(make_pair(a, b));
    }
    // for (auto cow : cows){
    //     cout << cow.first << " " << cow.second << endl;
    // }
    for (auto chicken : chickens){
        // set<pair<int, int> > working_cows;
        auto best_cow = make_pair(0, INT32_MAX);
        for (auto cow : cows){
            
            if (cow.first > chicken) {
                // cout << "too high, break" << endl;
                // cout << "cow: " << cow.first << " " << cow.second << endl;
                break;
            }
            else if (cow.first <= chicken && cow.second >= chicken && cow.second < best_cow.second) {
                best_cow = cow;
                // cout << "new best cow" << endl;
                // cout << "cow: " << cow.first << " " << cow.second << endl;
            }
        }
        
        
        if (best_cow != make_pair(0, INT32_MAX)) {
            cows.erase(cows.find(best_cow));
            works ++;
        }

        // cout << endl << endl << endl;
    }
    // cout << c - dont_work << endl;
    cout << works << endl;
    // for (int i = 0; i < n; i ++){
    //     int a, b;
    //     cin >> a >> b;
    //     set<int> available;
        
        

    //     int upper = chickens.size() - 1;
    //     int lower = 0;

    //     while (chickens[(upper - lower)/2] < a || chickens[(upper - lower)/2] > b){
    //         if ((upper - lower) <= 1) break;
    //         else if (chickens[(upper - lower)/2] < a) lower = (upper - lower)/2;
    //         else upper = (upper - lower)/2;
    //     }
        
    //     if (upper - lower > 1){
    //         int middle = (upper - lower)/2;
    //         available.insert(middle);
    //         int left = middle - 1;
    //         int right = middle + 1;
    //         while (chickens[left] > a && left >= 0){
    //             available.insert(left);
    //             left --;
    //         }
    //         while (chickens[right] < b && right < chickens.size()){
    //             available.insert(right);
    //             right ++;
    //         }
    //     }
    //     pairs.push_back(make_pair(make_pair(a, b), available));

        
    // }
    // sort(pairs.begin(), pairs.end(), compareLen);
    // set<int> new_chickens;
    // new_chickens.insert(chickens.begin(), chickens.end());
    // for (auto pair : pairs){
    //     for (auto chicken : pair.second){
    //         if (new_chickens.find(chicken) != new_chickens.end()){
    //             num_pairs ++;
    //             new_chickens.erase(new_chickens.find(chicken));
    //         }
    //     }
    //     if (new_chickens.size() == 0) break;
    // }
    // cout << num_pairs << endl;

    
}