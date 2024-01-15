#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<char> cows = {'X'};

    for (int i = 0; i < n; i ++){
        char x;
        cin >> x;
        cows.push_back(x);
    }

    // for (auto cow : cows){
    //     cout << cow << " ";
    // }
    // cout << endl;

    vector<set<int> > roads(n + 1);
    // for (int i = 1; i <= n; i ++){
    //     roads[i].insert(i);
    // }
    vector<int> comps(n + 1);

    for (int i = 0; i < n - 1; i ++){
        int a, b;
        cin >> a >> b;
        roads[a].insert(b);
        roads[b].insert(a);
    }

    // for (int i = 1; i <= n; i ++){
    //     cout << i << ": ";
    //     for (auto x : roads[i]) cout << x << " ";
    //     cout << endl;
    // }

    set<int> available;
    for (int i = 1; i <= n; i ++){
        available.insert(i);
    }


    int count = 0;
    while (available.size() > 0){
        vector<int> to_search = {*available.begin()};
        char type = cows[*available.begin()];
        comps[*available.begin()] = count;
        available.erase(available.begin());
        // cout << count << endl << endl;
        while (to_search.size() > 0){
            auto current = to_search[0];
            to_search.erase(to_search.begin());

            for (auto farm : roads[current]){
                
                if (available.find(farm) != available.end() && cows[farm] == type){
                    // cout << farm << endl;
                    available.erase(available.find(farm));
                    to_search.push_back(farm);
                    comps[farm + 1] = count;
                }
            }
        }
        count ++;
    }

    // for (auto cow : comps){
    //     cout << cow << " ";
    // }
    // cout << endl;

    for (int i = 0; i < m; i ++){
        int a, b;
        char c;
        cin >> a >> b >> c;

        if (cows[a] == c || comps[a] != comps[b]) cout << 1;
        else cout << 0;
    }
    cout << endl;
}