#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<long long, long long> min_days(double h1, double h2, double a1, double a2){
    // cout << h1 << " " << h2 << " " << a1 << " " << a2 << endl;
    if (h1 > h2){
        if (a1 > a2) return make_pair(0, INT64_MAX);
        else return make_pair(0, (floor((h1 - h2 - .000001)/(a2 - a1))));
    }
    else{
        if (a1 > a2){
            return make_pair (ceil(((1 + h2 - h1)/(a1 - a2))), INT64_MAX);
        }
        else{
            return {-1, -1};
        }
    }
}

int main(){
    long long t; cin >> t;
    for (long long u = 0; u < t; u ++){
        long long n; cin >> n;
        vector<long long> heights;
        vector<long long> growth;
        vector<long long> reqs;
        map<int, int> reqs1;
        pair<long long, long long> bounds = make_pair(0, INT64_MAX);
        for (long long i = 0; i < n; i ++){
            long long x; cin >> x;
            heights.push_back(x);
        }
        for (long long i = 0; i < n; i ++){
            long long x; cin >> x;
            growth.push_back(x);
        }
        for (long long i = 0; i < n; i ++){
            long long x; cin >> x;
            reqs.push_back(x);
            reqs1[x] = i;
        }
        for (long long i = 0; i < n - 1; i ++){
            long long p1 = reqs1[i];
            long long p2 = reqs1[i + 1];
            // cout << u << endl;
            // cout << p1 << p2 << endl;
            auto current_bounds = min_days(heights[p1], heights[p2], growth[p1], growth[p2]);
            // cout << "bounds: " << current_bounds.first << " " << current_bounds.second << endl;
            if (make_pair(int(current_bounds.first), int(current_bounds.second)) == make_pair(-1, -1)){
                bounds = make_pair(1, 0);
                break;
            }
            bounds.first = max(bounds.first, current_bounds.first);
            bounds.second = min(bounds.second, current_bounds.second);
            if (bounds.first > bounds.second) break;
        }
        if (bounds.first > bounds.second) cout << -1 << endl;
        else cout << bounds.first << endl;
    }
    // long long t; cin >> t;
    // for (long long r = 0; r < t; r ++){
    //     cout << "test : " << r << endl;
    //     bool works = true;
    //     long long n; cin >> n;
    //     vector<long long> height;
    //     vector<long long> growth;
    //     vector<long long> taller;
    //     for (long long a = 0; a < n; a ++){
    //         long long x; cin >> x;
    //         height.push_back(x);
    //     }
    //     for (long long a = 0; a < n; a ++){
    //         long long x; cin >> x;
    //         growth.push_back(x);
    //     }
    //     for (long long a = 0; a < n; a ++){
    //         long long x; cin >> x;
    //         taller.push_back(x);
    //     }
    //     long long earliest = 0;
    //     long long latest = long long32_MAX;
    //     for (long long i = n - 1; i >= 0; i --){
    //         cout << "i: " << i << endl;
    //         long long plant = find(taller.begin(), taller.end(), i) - taller.begin();
    //         cout << "plant: " << plant << endl;
    //         for (long long a = 0; a < n; a ++){
    //             if (taller[a] > i){

    //                 if (height[plant] > height[a] && growth[plant] > growth[a]){;}
    //                 else if (height[plant] > height[a] && growth[plant] < growth[a]) latest = min(long long(floor((height[i] - height[a])/(growth[a] - growth[i]))), latest);
    //                 else if (height[plant] < height[a] && growth[plant] > growth[a]) earliest = max(long long(ceil((height[a] - height[i])/(growth[i] - growth[a]))), earliest);
    //                 else{
    //                     cout << -1 << endl;
    //                     works = false;
    //                     break;
    //                 }
    //                 if (earliest > latest){
    //                     cout << -1 << endl;
    //                     works = false;
    //                     break;
    //                 }
    //             }
    //         }
    //         if (!works) break;
    //     }
    //     if (works) cout << earliest << endl;
    // }
}