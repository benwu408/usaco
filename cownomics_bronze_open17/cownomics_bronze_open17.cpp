#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<string> spotted;
    vector<int> mutations;

    for (int i = 0; i < n; i ++){
        string cow;
        cin >> cow;
        spotted.push_back(cow);
    }
    string first_regular;
    cin >> first_regular;
    for (int i = 0; i < m; i ++){
        bool mutate = true;
        for (int k = 0; k < n; k ++){
            if (first_regular[i] == spotted[k][i]){
                mutate = false;
                break;
            }
        }
        if (mutate){
            mutations.push_back(i);
        }
    }

    set<int> to_remove;
    for (int i = 1; i < n; i ++){
        string cow;
        cin >> cow;
        vector<int> new_mutations;
        for (auto spot : mutations){
            bool mutate = true;
            for (int k = 0; k < n; k ++){
                if (cow[spot] == spotted[k][spot]){
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