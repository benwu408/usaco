#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<vector<int>, set<int> > > cows;

    for (int i = 0; i < n; i ++){
        int x, y, p;
        cin >> x >> y >> p;

        cows.push_back(make_pair(vector<int> {x, y, p}, set<int> {}));
    }

    for (int a = 0; a < n - 1; a ++){
        for (int b = a + 1; b < n; b ++){
            float dist = sqrt(pow(cows[a].first[0] - cows[b].first[0], 2) + pow(cows[a].first[1] - cows[b].first[1], 2));
            if (dist <= cows[a].first[2]) cows[a].second.insert(b);
            if (dist <= cows[b].first[2]) cows[b].second.insert(a);
        }
    }
    int max_reached = 0;

    for (int i = 0; i < n; i ++){
        set<int> reached {i};
        set<int> to_search {i};

        while(to_search.size() > 0){
            set<int> new_cows;
            for (auto cow1 : to_search){
                for (auto cow2 : cows[cow1].second){
                    if (reached.find(cow2) == reached.end()){
                        reached.insert(cow2);
                        new_cows.insert(cow2);
                    }
                }
            }
            to_search = new_cows;
        }
        max_reached = max(max_reached, int(reached.size()));
    }
    cout << max_reached << endl;

}