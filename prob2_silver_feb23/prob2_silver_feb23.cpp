#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<pair<long long, pair<long long, long long> > > grazes;
long long g, n;

long double dist(pair<long double, long double> a, pair<long double, long double> b){
    // cout << (sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2))) << endl;
    return (sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2)));
}

pair<long long, long long> bin_search(long long time){
    // cout << "i" << endl;
    // for (auto it : grazes){
    //     cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    // }
    // cout << 'a' << endl;
    // cout << grazes[0].first << endl;
    if (time < grazes[0].first) return {-1, 0};
    // cout << "i" << endl;
    if (time > grazes[g - 1].first) return {g - 1, g};
    // cout << "i" << endl;
    long long low = 0;
    long long high = g - 1;
    long long mid = (high + low)/2;

    while (high != low + 1){
        if (grazes[mid].first > time){
            high = mid;
            mid = (high + low)/2;
        }
        else if (grazes[mid].first < time){
            low = mid;
            mid = (high + low)/2;
        }
        else{
            return {mid, mid};
        }

    }
    return {low, high};
}

int main(){
    cin >> g >> n;

    // vector<pair<long long, pair<long long, long long> > > grazes;
    long long count = 0;

    for (long long i = 0; i < g; i ++){
        long long x, y, time;
        cin >> x >> y >> time;

        grazes.push_back({time, {x, y}});
    }
    sort(grazes.begin(), grazes.end());
    // for (auto it : grazes){
    //     cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    // }
    // for (auto it : grazes) cout << it.first << endl;
    for (long long i = 0; i < n; i ++){
        long long x, y, time;
        cin >> x >> y >> time;
        bool add = false;
        // cout << "it" << endl;
        pair<long long, long long> closest = bin_search(time);
        // cout << closest.first << " " << closest.second << endl;
        // cout << dist(grazes[closest.first].second, {x, y}) << " " << abs(time - grazes[closest.first].first) << endl;
        // cout << dist(grazes[closest.second].second, {x, y}) << " " << abs(time - grazes[closest.second].first) << endl;
        // cout << closest.first << " " << grazes[closest.first].first << " " << time << " " << grazes[closest.second].first << " " << closest.second << endl;
        // if (closest.second == g){ 
        //     if (dist(grazes[closest.first].second, {x, y}) > abs(time - grazes[closest.first].first)) count ++;
        // }
        // else if (closest.first == -1){
        //     if (dist(grazes[closest.second].second, {x, y}) > abs(time - grazes[closest.second].first)) count ++;
        // }
        // else {
        //         if (dist(grazes[closest.first].second, {x, y}) > abs(time - grazes[closest.first].first) || 
        //         dist(grazes[closest.second].second, {x, y}) > abs(time - grazes[closest.second].first)) count ++;
        //     }
        if (closest.first > -1 && closest.second < g){
            if (closest.second != closest.first && closest.second - closest.first != 1) cout << "ohno" << endl; 
            if (grazes[closest.first].first > time || grazes[closest.second].first < time) cout << "ahh " << grazes[closest.first].first << " " << time << grazes[closest.second].first << endl;
        }
        if (closest.first > -1 && (dist(grazes[closest.first].second, {x, y}) > abs(time - grazes[closest.first].first + (long double)(0)))) add = true;
        else if (closest.second < g && (dist(grazes[closest.second].second, {x, y}) > abs(time - grazes[closest.second].first + (long double)(0)))) add = true;
        if (add) count ++;
    }
    cout << count << endl;
}