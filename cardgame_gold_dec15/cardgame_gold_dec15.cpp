#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_set>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> cards(2 * n + 1);
    vector<int> elsie1;
    vector<int> elsie2;
    vector<int> bessie;
    int count = 0;
    unordered_set<int> used;

    for (int i = 0; i < n / 2; i ++){
        int x; cin >> x;
        cards[x] = 1;
        elsie1.push_back(x);
    }
    for (int i = 0; i < n / 2; i ++){
        int x; cin >> x;
        cards[x] = 1;
        elsie2.push_back(x);
    }
    sort(elsie1.begin(), elsie1.end());
    sort(elsie2.begin(), elsie2.end(), greater<int> ());
    // for (int i = 0; i < 2 * n + 1; i ++){
    //     cout << "index " << i << ": " << cards[i] << endl; 
    // }
    // cout << endl;
    for (int i = 1; i <= 2 * n; i ++){
        if (cards[i] == 0) bessie.push_back(i);
        // cout << i << endl;
    }
    // cout << "first half: " << endl;
    int bigger = n/2;
    for (auto it : elsie1){
        if (bigger >= n) break;
        // cout << "bessie: " << bessie[bigger] << " -- elsie: " << it << endl;
        if (bigger >= n) break;
        if (bessie[bigger] <= it){
            while (bigger < n && bessie[bigger] <= it) bigger ++;
            if (bigger < n){
                count ++;
                bigger ++;
            }
        } 
        else{
            count ++;
            bigger ++;
        }
    }
    // cout << "second half: " << endl;
    int smaller = n/2 - 1;
    for (auto it : elsie2){
        if (smaller < 0) break;
        // cout << "bessie: " << bessie[smaller] << " -- elsie: " << it << endl;
        
        if (bessie[smaller] >= it){
            while (smaller > -1 && bessie[smaller] >= it) smaller --;
            if (smaller > -1){
                count ++;
                smaller --;
            }
        } 
        else{
            count ++;
            smaller --;
        }
    }

    // for (auto it : elsie) cout << it << endl;
    // cout << endl;
    // for (auto it : bessie) cout << it << endl;
    // cout << endl;
    // for (int i = 0; i < n / 2; i ++){
        
    //     int target = elsie[i];
    //     // cout << target << endl;
    //     int low = n/2;
    //     int high = n - 1;
    //     int mid = (high + low) / 2;

    //     while (high - low > 1){
    //         if (bessie[mid] > target){
    //             high = mid;
    //             mid = (high + low) / 2;
    //         }
    //         else{
    //             low = mid;
    //             mid = (high + low) / 2;
    //         }
    //     }
    //     // cout << "low, high: " << bessie[low] << bessie[high] << endl;
    //     // cout << "target: " << target << endl; 
    //     // cout << "used :" << endl;
    //     // for (auto it : used) cout << it << endl;
    //     // cout << endl;
    //     if (bessie[low] > target){
    //         while (used.find(bessie[low]) != used.end()){
    //             low ++;
    //         }
    //         if (low < n){
    //             count ++;
    //             used.insert(bessie[low]);
    //         }
    //     }
    //     else if (bessie[low] <= target && bessie[high] > target){
    //         while (used.find(bessie[high]) != used.end()){
    //             high ++;
    //         }
    //         if (high < n){
    //             count ++;
    //             used.insert(bessie[high]);
    //         }
    //     }
    // }
    // for (int i = n/2; i < n; i ++){
        
    //     int target = elsie[i];
    //     // cout << target << endl;
    //     int low = 0;
    //     int high = n/2 - 1;
    //     int mid = (high +  low) / 2;

    //     while (high - low > 1){
    //         if (bessie[mid] < target){
    //             low = mid;
    //             mid = (high + low) / 2;
    //         }
    //         else{
    //             high = mid;
    //             mid = (high + low) / 2;
    //         }
    //     }
    //     // cout << "low, high: " << bessie[low] << bessie[high] << endl;
    //     // cout << "target: " << target << endl; 
    //     // cout << "used :" << endl;
    //     // for (auto it : used) cout << it << endl;
    //     // cout << endl;
    //     if (bessie[high] < target){
    //         while (used.find(bessie[high]) != used.end()){
    //             high --;
    //         }
    //         if (high > -1){
    //             count ++;
    //             used.insert(bessie[high]);
    //         }
    //     }
    //     else if (bessie[low] < target && bessie[high] >= target){
    //         while (used.find(bessie[low]) != used.end()){
    //             low --;
    //         }
    //         if (low > -1){
    //             count ++;
    //             used.insert(bessie[low]);
    //         }
    //     }
    // }
    cout << count << endl;

}