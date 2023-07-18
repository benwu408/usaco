#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void print_vector(vector<vector<vector<string> > > vec){
    cout << "printing vec" << endl;
    for (auto it : vec){
        for (auto itr : it){
            for (auto iter : itr){
                cout << iter << " ";
            }
            cout << endl;
        }
        cout << endl;
        
    }
    
    
}

bool satisfies(vector<string> vec, vector<pair<string, string> > partners){
    for (int i = 0; i < 8; i ++){
        for (auto it : partners){
            if (it.first == vec[i]){
                bool valid = false;
                if (i > 0){
                    if (vec[i - 1] == it.second) valid = true;
                }
                if (i < 7){
                    if (vec[i + 1] == it.second) valid = true;
                }
                if (!valid) return false;
            }
            
        }
    }
    return true;
}
int main() {
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    set<string> previous;
    sort(cows.begin(), cows.end());
    // print_vector(cows);
    vector<pair<string, string> > pairs;
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++){
        string cow1;
        string cow2;
        for (int x = 0; x < 6; x ++){
            string word;
            cin >> word;
            if (x == 0) cow1 = word;
            if (x == 5) cow2 = word;
        }
        pairs.push_back(make_pair(min(cow1, cow2), max(cow1, cow2)));
    }
    sort(pairs.begin(), pairs.end());
    if (satisfies(cows, pairs)){
        for (auto it : cows) cout << it << endl;
    }
    else{
        while (next_permutation(cows.begin(), cows.end())){
            if (satisfies(cows, pairs)){
                for (auto it : cows) cout << it << endl;
                break;
            }
        }
    }
    
    
    
}