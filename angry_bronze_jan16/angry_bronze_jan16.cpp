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

    for (int a = 0; a < n; a ++){
        int cow = cows[a];
        vector<int> blasted = {cow};

        bool left = true;
        bool right = true;

        for (int i = 1; i < n + 1; i ++){
            
            int blast_start = blasted[0];
            int blast_end = blasted[blasted.size() - 1];
            int blast_start_index = find(cows.begin(), cows.end(), blast_start) - cows.begin();
            int blast_end_index = find(cows.begin(), cows.end(), blast_end) - cows.begin();
            

            if (left){
                int count = 0;
                int found = true;
                while (found && blast_start_index - count - 1 >= 0){
                    if (cows[blast_start_index - count - 1] >= blast_start - i){
                        blasted.insert(blasted.begin(), cows[blast_start_index - count - 1]);
                        count ++;
                    }
                    else{
                        found = false;
                    }
                }
            }
            if (right){
                int count = 0;
                int found = true;
                while (found && blast_end_index + count + 1 < cows.size()){
                    if (cows[blast_end_index + count + 1] <= blast_end + i){
                        blasted.push_back(cows[blast_end_index + count + 1]);
                        count ++;
                    }
                    else{
                        found = false;
                    }
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
