#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int k;
    int n;
    cin >> k >> n;

    set<pair<int, int>> pairs;
    vector<int> seen;
    for (int i = 0; i < n; i++) {
        int newCow;
        cin >> newCow;
        for (auto cow : seen) {
            pairs.insert(make_pair(newCow, cow));
        }
        seen.push_back(newCow);
    }

    for (int i = 1; i < k; i++) {
        vector<int> tempSeen;
        for (int i = 0; i < n; i++) {
            int newCow;
            cin >> newCow;
            for (auto cow : tempSeen) {
                pairs.erase(make_pair(cow, newCow));
            }
            tempSeen.push_back(newCow);
        }
    }

    cout << pairs.size() << endl;
}