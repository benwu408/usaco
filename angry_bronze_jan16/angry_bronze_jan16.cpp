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
    // print_vector(cows);
    for (auto cow : cows){
        vector<int> blasted = {cow};
        // cout << "TESTING " << cow << endl;
        for (int i = 1; i < n + 1; i ++){
            // cout << "blast " << i << endl;
            bool left = true;
            bool right = true;
            int blast_start = blasted[0];
            int blast_end = blasted[blasted.size() - 1];
            // cout << "START " << blast_start << endl;
            // cout << "END " << blast_end << endl; 
            for (int x = 1; x <= i; x ++){
                // cout << "range " << x << endl; 
                if (find(cows.begin(), cows.end(), blast_start - x) != cows.end() && left){
                    // cout << "found " << (blast_start - x) << endl;
                    blasted.insert(blasted.begin(), blast_start - x);
                }
                // cout << blasted[-1] + x << endl;
                if (find(cows.begin(), cows.end(), blast_end + x) != cows.end() && right){
                    // cout << "found " << (blast_end + x) << endl;
                    blasted.push_back(blast_end + x);
                } 
                
                
            }
            if (blast_start == blasted[0] && blast_end == blasted[blasted.size() - 1]) break;
            
        }
        max_blasted = max(max_blasted, int(blasted.size()));
        // print_vector(blasted); 
    }
    cout << max_blasted << endl;
}