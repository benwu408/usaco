#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<pair<long long, long long> > patches;
long long n, m;


bool works(long long d){
    long long available = n;
    long long last = INT64_MIN;
    long long cur_patch = 0;

    for (auto it : patches){
        while (max(last + d, it.first) <= it.second){
            last = (max(last + d, it.first));
            available --;
            if (available <= 0) break;
        }
        if (available <= 0) break;
    }
    return (available <= 0);
}

int main(){

    cin >> n >> m;

    

    for (long long i = 0; i < m; i ++){
        long long a, b;
        cin >> a >> b;
        patches.push_back({a, b});
    }

    sort(patches.begin(), patches.end());

    long long high = INT64_MAX;
    long long low = 0;
    long long mid = (high + low)/2;

    while (high - low > 1){
        if (works(mid)){
            low = mid;
            mid = (high + low)/2;
        }
        else{
            high = mid - 1;
            mid = (high + low)/2;
        }
    }
    cout << high << endl;
    // for (auto it : patches) cout << it.first << " " << it.second << endl;

    // long long d = 1;
    // bool works = true;
    // cout << endl << endl << endl;
    // while (works){
    //     long long available = n;
    //     long long last = INT32_MIN;
    //     cout << patches.size() << " size" << endl;
    //     for (auto patch : patches){
    //         if (available <= 0) break;
    //         long long begin = patch.first;
    //         long long end = patch.second;
    //         cout << end << " " << begin << endl;
    //         if (begin - last < d) {
    //             cout << "here" << endl;
    //             cout << begin << last << endl;
    //             cout << begin - last << " " << d << endl;
    //             begin = last + d;
    //         }
    //         // cout << end << " " << begin << endl;
    //         available -= 1 + (end - begin)/d;
    //         last = end - ((end - begin) % d);
    //     }
    //     // cout << available << endl;
    //     if (available > 0){
    //         works = false;
    //         d --;
    //     }
    //     else d ++;
    // }
    // cout << d << endl;
}