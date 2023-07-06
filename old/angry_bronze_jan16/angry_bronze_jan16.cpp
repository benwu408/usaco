#include <iostream>
#include <vector>
#include <set>
using namespace std;

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

        bool left = true;
        bool right = true;

        for (int i = 1; i < n + 1; i ++){
            
            int blast_start = blasted[0];
            int blast_end = blasted[blasted.size() - 1];

            for (int x = 1; x <= i; x ++){
                if (find(cows.begin(), cows.end(), blast_start - x) != cows.end() && left){
                    blasted.insert(blasted.begin(), blast_start - x);
                }
                
                if (find(cows.begin(), cows.end(), blast_end + x) != cows.end() && right){
                    blasted.push_back(blast_end + x);
                }
                
                
            }
            if (blast_start == blasted[0] && blast_end == blasted[blasted.size() - 1]) break;
            if (blast_start == blasted[0]) left = false;
            if (blast_end == blasted[blasted.size() - 1]) right = false;
            
        }
        max_blasted = max(max_blasted, int(blasted.size()));

    }
    cout << max_blasted << endl;
}
