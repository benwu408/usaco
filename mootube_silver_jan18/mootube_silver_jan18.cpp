#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

vector<vector<pair<int, int> > > connections(5001);

bool sort_func(pair<int, int> x, pair<int, int> y){ return (x.first > y.first);}

int num_connects(int v, int k, int last){
    int num = 0;
    for (auto vid : connections[v]){
        if (vid.first >= k && vid.second != last){
            num ++;
            num += num_connects(vid.second, k, v);
        }
        else if (vid.first < k) break;
    }
    return num;
}

int main(){
    int n, q; cin >> n >> q;

    for (int i = 0; i < n - 1; i ++){
        int p, q, r; cin >> p >> q >> r;

        connections[p].push_back(make_pair(r, q));
        connections[q].push_back(make_pair(r, p));
    }

    for (int i = 1; i <= n; i ++){
        sort(connections[i].begin(), connections[i].end(), sort_func);
    }
    

    for (int i = 0; i < q; i ++){
        int k, v; cin >> k >> v;
        cout << num_connects(v, k, 0) << endl;
    }
}
