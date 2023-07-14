#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<set<int> > times(1000);

    int n;
    cin >> n;

    set<int> filled;

    int start = INT32_MAX;
    int finish = INT32_MIN;

    for (int i = 0; i < n; i ++){
        int begin, end;
        cin >> begin >> end;
        for (int a = begin; a < end; a ++){
            if (a < start) start = a;
            if (a > finish) finish = a;
            times[a].insert(i);
            filled.insert(a);
        }
    }   

    int num_filled = filled.size();

    int min_removed = INT32_MAX;

    int current_non_fill = INT32_MAX;

    int current_single = -1;

    set<int> singles;

    int best_single;

    for (int i = start; i <= finish; i ++){
        if (times[i].size() == 1){
            singles.insert(*times[i].begin());
            if (*times[i].begin() == current_single) current_non_fill ++;
            else{
                min_removed = min(min_removed, current_non_fill);
                current_non_fill = 1;
                current_single = *times[i].begin();
            }
        }
    }
    min_removed = min(min_removed, current_non_fill);
    if (singles.size() != n) cout << num_filled << endl;
    else cout << num_filled - min_removed << endl;
}