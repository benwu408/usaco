#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> cows;

    for (int i = 0; i < n; i ++){
        string cow;
        int milk;
         
        cin >> cow >> milk;

        if (cows.find(cow) == cows.end()) cows[cow] = milk;
        else cows[cow] += milk;
    }
    
    vector<pair <int, string> > cows1;

    for (auto it : cows){
        cows1.push_back(make_pair(it.second, it.first));
    }

    sort(cows1.begin(), cows1.end());

    int min = INT32_MAX;
    int min2 = -1;
    string cow = "Tie";

    for (auto it : cows1){
        if (min == INT32_MAX) min = it.first;
        if (it.first != min && min2 == -1) {
            min2 = it.first;
            cow = it.second;
        }
        else if (it.first > min2 && min2 != -1) break;
    }
    if (cows1.size() > 1) cout << cow << endl;
    else cout << (*cows1.begin()).second << endl;
}