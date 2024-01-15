#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    int n, t; cin >> n >> t;
    vector<int> cows(n);

    map<set<int>, int> contacts;
    map<int, pair<int, int> > contacts_time_first;

    for (int i = 0; i < n; i ++){
        char x; cin >> x; int a = x - '0';
        cows[i] = a;
    }

    for (int i = 0; i < t; i ++){
        int t, a, b; cin >> t >> a >> b; a --; b --;
        contacts[set<int> {a, b}] = t;
        contacts_time_first[t] = {a, b};
    }
    int min_shakes = INT32_MAX;
    int max_shakes = -1;
    int possibilities = 0;
    for (int i = 0; i < n; i ++){
        // cout << i << endl << endl << endl;
        bool works = false;
        vector<int> infected(n);
        vector<int> shakes(n);
        int curr_max_shakes = -1;
        infected[i] = 1;
        if (infected == cows){
            works = true;;
            min_shakes = 0;
            max_shakes = 0;
        }
        else{
            for (auto contact : contacts_time_first){
                int a, b;
                a = (contact.second.first); b = (contact.second.second);
                // cout << a << " " << b << endl;
                if (infected[a] == 1) shakes[a] ++;
                if (infected[b] == 1) shakes[b] ++;
                infected[a] = max(infected[a], infected[b]);
                infected[b] = infected[a];
                
                if (infected == cows){
                    
                    curr_max_shakes = *max_element(shakes.begin(), shakes.end());
                    works = true;
                    min_shakes = min(min_shakes, curr_max_shakes);
                    max_shakes = max(max_shakes, curr_max_shakes);
                    
                }
                else if (works && curr_max_shakes == *max_element(shakes.begin(), shakes.end())) works = false;
                // for (auto x : infected) cout << x << " ";
                // cout << endl;
                // for (auto x : shakes) cout << x << " ";
                // cout << endl;
            }
            if (works){
                if (curr_max_shakes == *max_element(shakes.begin(), shakes.end())){
                    max_shakes = INT32_MAX;
                    min_shakes = min(curr_max_shakes, min_shakes);
                }
                else{
                    min_shakes = min(min_shakes, curr_max_shakes);
                    max_shakes = max(max_shakes, curr_max_shakes);
                }
            }
            
            
        }
        if (works) possibilities ++;
        
    }
    string max;
    if (max_shakes == INT32_MAX) {
        max = "Infinity";
        cout << possibilities << " " << min_shakes << " " << max << endl;
    }
    else{
        cout << possibilities << " " << min_shakes << " " << max_shakes << endl;
    }
    

}