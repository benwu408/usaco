#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main(){
    float n; cin >> n;
    vector<float> questions(n);

    for (float i = 0; i < n; i ++){
        float x; cin >> x;
        questions[i] = x;
    }

    float min = questions[n - 1];
    pair<float, set<float>> best = {-1, {}};
    float total = 0;

    for (float i = n - 1; i >= 0; i --){
        float curr = questions[i];
        total += curr;
        if (curr < min){
            min = curr;
        }
        float curr_avg = (total - min)/(n - i - 1);
        if (curr_avg > best.first){
            best = {curr_avg, {i}};
        }
        else if (curr_avg == best.first){
            best.second.insert(i);
        }
        // cout << total << " " << curr << " " << min << endl;
        // cout << curr_avg << endl;
    }

    for (auto it : best.second) {
        if (it != 0){
            cout << it << endl;
        }
        
    }
}