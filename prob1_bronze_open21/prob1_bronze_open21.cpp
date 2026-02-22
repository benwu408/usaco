#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n, l; cin >> n >> l;
    vector<int> papers(n);
    vector<int> num_under(n + 1);


    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        papers[i] = x;
        if (x <= n){
            num_under[x + 1] ++;
        }
    }
    for (int i = 1; i <= n; i ++){
        num_under[i] += num_under[i - 1];
    }
    // for (auto it : num_under) cout << it << " ";
    // cout << endl;
    int maxh = 0;
    int total_under = 0;
    bool works = true;
    int minim = INT32_MAX;
    sort(papers.begin(), papers.end(), greater<int> ());
    for (int i = 1; i <= n; i ++){
        int next = papers[i - 1];
        minim = min(minim, next);
        if (minim < i - 1 || num_under[i] > l + n - i){
            break;
        }
        // for (int a = 0; a < i; a ++){
        //     if (papers[a] < i - 1){
        //         works = false;
        //         break;
        //     }
        //     else if (papers[a] == i - 1) total_under ++;
        //     if (total_under > l){
        //         works = false;
        //         break;
        //     }
        // }
        maxh = i;
        total_under = 0;
    }
    cout << maxh << endl;
}