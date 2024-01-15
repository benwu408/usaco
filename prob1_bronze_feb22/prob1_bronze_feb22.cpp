#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int a = 0; a < t; a ++){
        int n;
        cin >> n;
        vector<int> log;
        int sum = 0;

        for (int i = 0; i < n; i ++){
            int x;
            cin >> x;
            // cout << x << " ";
            log.push_back(x);
            sum += x;
        }
        // cout << endl;

        for (int r = n; r >= 1; r --){
            if (r * (sum/r) == sum){
                // cout << "r: " << r << endl;
                int target = sum/r;
                int current = 0;
                bool works = true;
                for (auto entry : log){
                    if (entry + current == target){
                        current = 0;
                    }
                    else if (entry + current > target){
                        works = false;
                        break;
                    }
                    else current += entry;
                }
                if (works && current == 0){
                    cout << n - r << endl;
                    break;
                }
            }
        }
    }
}