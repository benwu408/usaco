#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int main() {
    int k ;
    int n;
    cin >> k >> n;

    map<int, set<int> > less;
    
    for (int i = 0; i < k; i ++){
        vector<int> prev;
        map<int, set<int> > current_less;
        vector<int> day;
        for(int o = 0; o < n; o ++){
            int cow;
            cin >> cow;
            day.push_back(cow);
            if (i == 0){
                set<int> vec;
                less[cow] = vec;
            }
        }
        for (int x = 0; x < n - 1; x ++){
            set<int> new_vec;
            current_less[day[x]] = new_vec;
            for(int y = x + 1; y < n; y ++){
                
                if (i == 0){
                    current_less[day[x]].insert(day[y]);
                    less[day[x]].insert(day[y]);
                }    
                else{
                    if (less[day[x]].find(day[y]) != less[day[x]].end()){
                        current_less[day[x]].insert(day[y]);
                    }
                }
            }
                
        }

        less = current_less;
        cout << "less at end of " << i << endl;
        for (auto it : less){
            for (auto itr : it.second){
                cout << it.first << " " << itr << endl;
            }
        }
        
        
        
    }
    int count = 0;
    
    for (auto it : less){
        count += it.second.size();
        for (auto itr : it.second){
            cout << it.first << " " << itr << endl;
        }
    }
    cout << count;
}