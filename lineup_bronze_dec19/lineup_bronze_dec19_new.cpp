#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


void add_end(vector<vector<string> > * new_cows, string newCow){
    (*((*new_cows).end() - 1)).push_back(newCow);
}

int main() {
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    map<string, vector<string> > cowMap;

    for (auto cow : cows) cowMap[cow] = {};


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
        cowMap[cow1].push_back(cow2);
        cowMap[cow2].push_back(cow1);
    }

    vector<vector<string> > new_cows;

    while (cows.size() > 0){
        string curCow = cows[0];
        if (new_cows.size() > 0 && cowMap[*((*(new_cows.end() - 1)).end() - 1)].size() == 1){
            string lastCow = *((*(new_cows.end() - 1)).end() - 1);
            auto newCow = cowMap[lastCow][0];
            add_end(&new_cows, newCow);
            auto newCowPtr = find(cows.begin(), cows.end(), newCow);
            cows.erase(newCowPtr);
            cowMap[lastCow].erase(find(cowMap[lastCow].begin(), cowMap[lastCow].end(), newCow));
            cowMap[newCow].erase(find(cowMap[newCow].begin(), cowMap[newCow].end(), lastCow));
        }
        else {
            vector<string> connections = cowMap[curCow];
            int num_connect = connections.size();
            if (num_connect < 2){
                new_cows.push_back({curCow});
                cows.erase(cows.begin());
            }
            else {
                auto cow1 = min(connections[0], connections[1]);
                auto cow2 = max(connections[0], connections[1]);
                if (cowMap[cow1].size() == 1) {
                    new_cows.push_back({cow1, curCow, cow2});
                    cowMap[cow1].erase(find(cowMap[cow1].begin(), cowMap[cow1].end(), curCow));
                    cowMap[cow2].erase(find(cowMap[cow2].begin(), cowMap[cow2].end(), curCow));
                    cows.erase(cows.begin());
                    cows.erase(find(cows.begin(), cows.end(), cow1));
                    cows.erase(find(cows.begin(), cows.end(), cow2));
                    cowMap[curCow] = {};
                }
                else if (cowMap[cow2].size() == 1){
                    new_cows.push_back({cow2, curCow, cow1});
                    cowMap[cow1].erase(find(cowMap[cow1].begin(), cowMap[cow1].end(), curCow));
                    cowMap[cow2].erase(find(cowMap[cow2].begin(), cowMap[cow2].end(), curCow));
                    cows.erase(cows.begin());
                    cows.erase(find(cows.begin(), cows.end(), cow1));
                    cows.erase(find(cows.begin(), cows.end(), cow2));
                    cowMap[curCow] = {};
                }
                else{
                    cows.erase(cows.begin());
                    cows.push_back(curCow);
                }
            }
        }   
    }

    for (int i = 0; i < new_cows.size(); i ++){
        if (*(new_cows[i].end() - 1) < new_cows[i][0]) reverse(new_cows[i].begin(), new_cows[i].end());
    }
    sort(new_cows.begin(), new_cows.end());
    for (auto cowgroup : new_cows){
        for (auto cow : cowgroup) cout << cow << endl;
    }
    
}

