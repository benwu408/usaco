#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print_vector(vector<int> vec) {
    for (auto it : vec){
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int max_blasted = 0;

    vector<int> cows;

    for (int i = 0; i < n; i ++){
        int cow;
        cin >> cow;

        cows.push_back(cow);
    }

    sort(cows.begin(), cows.end());

    for (auto cow : cows){
        vector<int> blasted = {cow};
        cout << "TESTING " << cow << endl;
        for (int i = 1; i < n + 1; i ++){
            cout << "blast " << i << endl;
            bool left = true;
            bool right = true;
            for (int x = 1; x <= i; x ++){
                if (find(cows.begin(), cows.end(), blasted[0] - x) != cows.end() && left){
                    cout << "found " << (blasted[0] - x) << endl;
                    blasted.insert(blasted.begin(), blasted[0] - x);
                } else left = false;
                // cout << blasted[-1] + x << endl;
                if (find(cows.begin(), cows.end(), blasted[blasted.size() - 1] + x) != cows.end() && right){
                    cout << "found " << (blasted.size() - 1) << endl;
                    blasted.push_back(blasted[blasted.size() - 1] + x);
                } else right = false;
                if (!left && !right) break;
                
            }
            
        }
        max_blasted = max(max_blasted, int(blasted.size()));
        print_vector(blasted); 
    }
    cout << max_blasted << endl;
}