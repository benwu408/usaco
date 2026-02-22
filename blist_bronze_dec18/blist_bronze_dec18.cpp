#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> needed(1001);
    int max_buckets = 0;
    int current_buckets = 0;

    int n; cin >> n;
    for (int i = 0; i < n; i ++){
        int s, t, b; cin >> s >> t >> b;
        needed[s] = b;
        needed[t] = -1 * b;
    }

    for (auto x : needed){
        current_buckets += x;
        max_buckets = max(current_buckets, max_buckets);
    }

    cout << max_buckets << endl;
}