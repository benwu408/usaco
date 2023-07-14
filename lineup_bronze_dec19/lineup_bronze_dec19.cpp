#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


void add_end(vector<vector<string> > * new_cows, string newCow){
    (*((*new_cows).end() - 1)).push_back(newCow);
}

string get_last_cow(vector<vector<string> > new_cows){
    return *((*(new_cows.end() - 1)).end() - 1);
}

void find_and_erase(vector<string> * vec, string cow){
    (*vec).erase(find((*vec).begin(), (*vec).end(), cow));
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
        if (new_cows.size() > 0 && cowMap[get_last_cow(new_cows)].size() == 1){
            string lastCow = get_last_cow(new_cows);
            auto newCow = cowMap[lastCow][0];
            add_end(&new_cows, newCow);
            auto newCowPtr = find(cows.begin(), cows.end(), newCow);
            cows.erase(newCowPtr);
            find_and_erase(&(cowMap[lastCow]), newCow);
            find_and_erase(&(cowMap[newCow]), lastCow);
        }
        else {
            string curCow = cows[0];
            vector<string> connections = cowMap[curCow];
            if (connections.size() < 2){
                new_cows.push_back({curCow});
                cows.erase(cows.begin());
            }
            else {
                auto cow1 = min(connections[0], connections[1]);
                auto cow2 = max(connections[0], connections[1]);
                if ((cowMap[cow1].size() == 1) || cowMap[cow2].size() == 1) {
                    vector<string> to_add = (cowMap[cow1].size() == 1) ? vector<string> {cow1, curCow, cow2} : vector<string> {cow2, curCow, cow1};
                    new_cows.push_back(to_add);
                    find_and_erase(&(cowMap[cow1]), curCow);
                    find_and_erase(&(cowMap[cow2]), curCow);
                    cows.erase(cows.begin());
                    find_and_erase(&cows, cow1);
                    find_and_erase(&cows, cow2);
                    cowMap[curCow] = {};
                }
                else{
                    cows.erase(cows.begin());
                    cows.push_back(curCow);
                }
            }
        }   
    }

    


    for (auto &it : new_cows){
        if (*((it).end() - 1) < it[0]) reverse(it.begin(), it.end());
    }
    sort(new_cows.begin(), new_cows.end());
    for (auto cowgroup : new_cows){
        for (auto cow : cowgroup) cout << cow << endl;
    }
    
}

