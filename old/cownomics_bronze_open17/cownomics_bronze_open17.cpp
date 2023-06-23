#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<string> spotted;
    vector<int> mutations (m);
    iota(mutations.begin(), mutations.end(), 1);
    
    for (int i = 0; i < n; i ++){
        string cow;
        cin >> cow;
        spotted.push_back(cow);
    }

    for (int i = 0; i < n; i ++){
        string cow;
        cin >> cow;
        vector<int> new_mutations;
        for (auto spot : mutations){
            bool mutate = true;
            for (int k = 0; k < n; k ++){
                if (cow[spot - 1] == spotted[k][spot - 1]){
                    mutate = false;
                    break;
                }
            }
            if (mutate){
                new_mutations.push_back(spot);
            }
        }
        mutations = new_mutations;
    }
    
    cout << mutations.size() << endl;
    
}