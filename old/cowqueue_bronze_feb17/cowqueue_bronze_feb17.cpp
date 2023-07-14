#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int current_time = 0;
    vector<pair<int, int> > cows;
    for (int i = 0; i < n; i ++){
        int arrival;
        int duration;
        cin >> arrival >> duration;
        cows.push_back(make_pair(arrival, duration));
    }

    sort(cows.begin(), cows.end());

    for (auto pair : cows) {
        if (pair.first >= current_time) current_time = pair.first + pair.second;
        else current_time = current_time + pair.second;
    }
    
    cout << current_time << endl;
}