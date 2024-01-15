#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    int n, t; cin >> n >> t;
    vector<int> cows(n);
    vector<int> contacts(n);

    map<int, pair<int, int> > contacts_time_first;

    for (int i = 0; i < n; i ++){
        char x; cin >> x; int a = x - '0';
        cows[i] = a;
    }

    for (int i = 0; i < t; i ++){
        int t, a, b; cin >> t >> a >> b; a --; b --;
        contacts_time_first[t] = {a, b};
        contacts[a]++; contacts[b]++;
    }
    int min_shakes = INT32_MAX;
    int max_shakes = 0;
    int possibilities = 0;
    for (int i = 0; i < n; i ++){
        bool works = false;
        
        for (int k = 0; k <= *max_element(contacts.begin(), contacts.end()); k ++){
            vector<int> infected(n);
            infected[i] = 1;
            vector<int> shakes(n);
            for (auto contact : contacts_time_first){
                int a, b; a = contact.second.first; b = contact.second.second;
                if (infected[a] == 1 && shakes[a] <= k) {
                    shakes[a] ++;
                }
                if (infected[b] == 1 && shakes[b] <= k) {
                    shakes[b] ++;
                }
                if (infected[b] == 1 && infected[a] == 0){
                    if (shakes[b] <= k){
                        infected[a] = 1;
                    }
                }
                else if (infected[a] == 1 && infected[b] == 0){
                    if (shakes[a] <= k){
                        infected[b] = 1;
                    }
                }
            }
            // cout << i << " " << k << endl;
            // for (auto cow : infected){
            //     cout << cow << " ";
            // }
            // cout << endl;
            if (infected == cows){
                works = true;
                min_shakes = min(min_shakes, k);
                max_shakes = max(max_shakes, k);
            }
            if (infected != cows && works){
                break;
            }
        }
        if (works) possibilities ++;
        
    }
    string max;
    if (max_shakes == *max_element(contacts.begin(), contacts.end())) {
        max = "Infinity";
        cout << possibilities << " " << min_shakes << " " << max << endl;
    }
    else{
        cout << possibilities << " " << min_shakes << " " << max_shakes << endl;
    }
    

}