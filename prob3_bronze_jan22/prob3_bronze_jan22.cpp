#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int second_biggest(vector<long long> x, long long biggest){
    long long second = -1;
    for (auto it : x){
        if (it < 0) return INT32_MIN;
        if (it > second && it < biggest) second = it;
    }
    if (second == -1) return biggest;
    return second;
}

int main(){
    int t; cin >> t;
    for (int u = 0; u < t; u ++){
        bool works = true;
        int n; cin >> n;
        vector<long long> cows;
        long long count = 0;
        for (int i = 0; i < n; i ++){
            long long cow; cin >> cow; cows.push_back(cow);
        }
        int big = -1;
        int big2 = -1;
        int it;
        for(int i = 0; i < n; i ++){
            if (cows[i] > big){
                big2 = big;
                big = cows[i];
                it = i;
            }
            else if (cows[i] > big2){
                big2 = cows[i];
            }
        }
        while (big2 != -1 && works){
            // cout << big << " " << big2 << endl;
            // int it = find(cows.begin(), cows.end(), big) - cows.begin();
            if (it == n - 1){
                works = false;
                break;
            }
            cows[it] -= (big - big2);
            cows[it + 1] -= (big-big2);
            count += 2*(big-big2);

            big = -1;
            big2 = -1;
            for(int i = 0; i < n; i ++){
                int cow = cows[i];
                if (cow < 0){
                    works = false;
                    break;
                }
                if (cow > big){
                    big2 = big;
                    big = cow;
                    it = i;
                }
                else if (cow > big2 && cow < big){
                    big2 = cow;
                }
            }
        }
        if (works) cout << count << endl;
        else cout << -1 << endl;
    }
}