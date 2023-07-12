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



        bool left = true;
        bool right = true;

        int blast_start = cow;
        int blast_end = cow;
        int blast_start_index = a;
        int blast_end_index = a;

        for (int i = 1; i < n + 1; i ++){
            
            int next_start = blast_start;
            int next_end = blast_end;
            int next_start_index = blast_start_index;
            int next_end_index = blast_end_index;

            if (left){
                int count = 0;
                int found = true;
                while (found && blast_start_index - count - 1 >= 0){
                    if (cows[blast_start_index - count - 1] >= blast_start - i){
                        next_start = cows[blast_start_index - count - 1];
                        next_start_index = blast_start_index - count - 1;
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
                        next_end = cows[blast_end_index + count + 1];
                        next_end_index = blast_end_index + count + 1;
                        count ++;
                    }
                    else{
                        found = false;
                    }
                }
                
            }

            if (next_start == blast_start && blast_end == next_end) break;
            if (blast_start == next_start) left = false;
            if (blast_end == next_end) right = false;
            blast_end = next_end;
            blast_end_index = next_end_index;
            blast_start = next_start;
            blast_start_index = next_start_index;
            
            
        }
        
        
        max_blasted = max(max_blasted, 1 + blast_end_index - blast_start_index);

    }
    cout << max_blasted << endl;
}
