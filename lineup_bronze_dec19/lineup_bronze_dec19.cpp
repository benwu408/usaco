#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print_vector(vector<string> vec){
    cout << "vector : ";
    for (auto str : vec) cout << str << " ";
    cout << endl << endl;
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

    vector<string> new_cows;

    while (cows.size() > 0){
        cout << cows[0] << endl;
        print_vector(new_cows);
        string curCow = cows[0];
        if (new_cows.size() > 0 && cowMap[*(new_cows.end() - 1)].size() == 1){
            string lastCow = *(new_cows.end() - 1);
            cout << "poooo" << endl;
            auto newCow = cowMap[lastCow][0];
            cout << newCow << endl;
            new_cows.push_back(newCow);
            auto newCowPtr = find(cows.begin(), cows.end(), newCow);
            cout << *newCowPtr << endl;
            cows.erase(newCowPtr);
            cowMap[lastCow] = {};
            cowMap[newCow].erase(find(cowMap[newCow].begin(), cowMap[newCow].end(), lastCow));
        }
        else {
            cout << "still poop" << endl;
            vector<string> connections = cowMap[curCow];
            int num_connect = connections.size();
            if (num_connect < 2){
                cout << "poop" << endl;
                new_cows.push_back(curCow);
                cows.erase(cows.begin());
            }
            else {
                auto cow1 = min(connections[0], connections[1]);
                auto cow2 = max(connections[0], connections[1]);
                if (cowMap[cow1].size() == 1) {
                    new_cows.push_back(cow1);
                    new_cows.push_back(curCow);
                    new_cows.push_back(cow2);
                    cowMap[cow1] = {};
                    cowMap[cow2].erase(find(cowMap[cow2].begin(), cowMap[cow2].end(), curCow));
                    
                }
                else {
                    new_cows.push_back(cow2);
                    new_cows.push_back(curCow);
                    new_cows.push_back(cow1);
                    cowMap[cow1].erase(find(cowMap[cow1].begin(), cowMap[cow1].end(), curCow));
                    cowMap[cow2] = {};
                }
                cows.erase(cows.begin());
                cows.erase(find(cows.begin(), cows.end(), cow1));
                cows.erase(find(cows.begin(), cows.end(), cow2));
                cowMap[curCow] = {};
            }

        }   
        
    }
    for (auto cow : new_cows) cout << cow << endl;
    
}

