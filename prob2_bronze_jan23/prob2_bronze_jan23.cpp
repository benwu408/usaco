#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

vector<string> perms;

bool is_valid(vector<vector<int> >cows, string used_ac, vector<vector<int> > acs){
    vector<int> temps(101);
    for (int i = 0; i < used_ac.size(); i ++){
        if (used_ac[i] == '1'){
            for (int a = acs[i][0]; a <= acs[i][1]; a ++){
                temps[a] += acs[i][2];
            }
        }
    }
    for (auto cow : cows){
        for (int i = cow[0]; i <= cow[1]; i ++){
            if (temps[i] < cow[2]) return false;
        }
    }
    return true;
}
void search(string current, int m){
    string next = current;
    if (current.size() == m) perms.push_back(next);
    else{
        search(next + "1", m);
        search(next + "0", m);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > cows;
    vector<vector<int> > acs;

    for (int i = 0; i < n; i ++){
        int s, t, c;
        cin >> s >> t >> c;

        cows.push_back({s, t, c});
    }

    for (int i = 0; i < m; i ++){
        int a, b, p, m;
        cin >> a >> b >> p >> m;

        acs.push_back({a, b, p, m});
    }

    search("", m);
    // for (auto it : perms) cout << it << endl;
    int min_cost = INT32_MAX;

    for (auto perm : perms){
        if (is_valid(cows, perm, acs)){
            // cout << perm << endl;
            int cost = 0;
            for (int i = 0; i < m; i ++){
                if (perm[i] == '1') cost += acs[i][3];
            }
            min_cost = min(cost, min_cost);
        }
    }
    cout << min_cost << endl;

}