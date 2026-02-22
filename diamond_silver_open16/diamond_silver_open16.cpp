#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, k; cin >> n >> k;


    
    if (n == 0){
        cout << 0 << endl;
        return 0;
    }
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<int> diamonds(n);

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        diamonds[i] = x;
        // cout << x << endl;
    }

    sort(diamonds.begin(), diamonds.end());

    // for (auto it : diamonds) cout << it << " ";
    // cout << endl;

    int highest = 2;
    int current = 2;
    int count1 = 0;
    int count2 = 0;
    int count3 = 1;
    int count4 = 1;
    while (count4 < n - 1){
        count4 ++;
        current ++;
        // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
        if (diamonds[count4] - diamonds[count3] <= k){
            highest = max(highest, current);
            // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
        }
        else{
            while (diamonds[count4] - diamonds[count3] > k){
                count3 ++;
                current --;
                // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
            }
            highest = max(highest, current);
            // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
            while (count2 < count3 - 1){
                count2 ++;
                current ++;
                // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
                if (diamonds[count2] - diamonds[count1] <= k){
                    highest = max(highest, current);
                    // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
                }
                else{
                    while(diamonds[count2] - diamonds[count1] > k){
                        count1 ++;
                        current --;
                        // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
                    }
                    highest = max(highest, current);
                    // cout << count1 << " " << count2 << " " << count3 << " " << count4 << " " << current << " " << highest << endl;
                }
            }
        }
    }
    cout << highest << endl;
}