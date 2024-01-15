#include <vector>
#include <map>
#include <iostream>
#include <set>
using namespace std;

void pour(pair<int, int>& bucket1, pair<int, int>& bucket2){
    if (bucket1.second <= bucket2.first - bucket2.second){
        bucket2.second += bucket1.second;
        bucket1.second = 0;
    }
    else{
        int diff = bucket2.first - bucket2.second;
        bucket2.second += diff;
        bucket1.second -= diff;
    }
}

int main(){
    vector<pair<int, int> > buckets(3);
    for (int i = 0; i < 3; i ++){
        int c, m; cin >> c >> m;
        buckets[i] = make_pair(c, m);
    }

    for (int i = 0; i < 100; i ++){
        int x = i % 3;
        if (x == 0){
            pour(buckets[0], buckets[1]);
        }
        else if (x == 1){
            pour(buckets[1], buckets[2]);
        }
        else if (x == 2){
            pour(buckets[2], buckets[0]);
        }
    }
    cout << buckets[0].second << endl << buckets[1].second << endl << buckets[2].second << endl;
}