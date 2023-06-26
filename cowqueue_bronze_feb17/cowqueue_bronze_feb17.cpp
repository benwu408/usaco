#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int begin = 0;
    vector<pair<int, int> > cows;
    for (int i = 0; i < n; i ++){
        int arrival;
        int time;
        cin >> arrival >> time;
        cows.push_back(make_pair(arrival, time));
    }
    sort(cows.begin(), cows.end());

    for (int i = 0; i < n; i ++){
        // cout << it.first << " " << it.second << endl;
        int arrival = cows[i].first;
        int time = cows[i].second;
        if (arrival >= begin) begin = arrival + time;
        else begin = begin + time;

    }
    cout << begin << endl;
}