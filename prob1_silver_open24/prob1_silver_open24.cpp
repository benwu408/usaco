#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    cout << "n: " << n << endl;

    map<int, vector<int> > interviewing;
    int next = k;
    vector<int> times(n);
    int time_passed = 0;

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        times[i] = x;
        if (i < k) interviewing[x] = {i};
    }
    int final_time;
    vector<int> final;
    while (next <= n){
        vector<int> interviewer = (*interviewing.begin()).second;
        time_passed = (*interviewing.begin()).first;
        cout << "time passed: " << time_passed << endl;
        interviewing.erase(interviewing.begin());
        int count = 1;
        while ((*interviewing.begin()).first == time_passed){
            count ++;
            interviewer.insert(interviewer.end(), (*interviewing.begin()).second.begin(), (*interviewing.begin()).second.end());
            interviewing.erase(interviewing.begin());
        }
        cout << "count: " << count << endl;
        for (int i = 0; i < count; i ++){
            if (next + i == n){
                final = interviewer;
                final_time = time_passed;
                break;
            }
            if (interviewing.find(time_passed + times[next + i]) != interviewing.end()) interviewing[time_passed + times[next + i]] = interviewer;
            else interviewing[time_passed + times[next + i]].insert(interviewing[time_passed + times[next + i]].end(), interviewer.begin(), interviewer.end());
        }
        next += count;
        cout << "next: " << next << endl;
    }
    cout << final_time << endl;
    vector<int> can_be(k);
    for (auto x : final) can_be[x] = 1;
    for (auto x : can_be) cout << x << " ";

}