#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

struct Cow {
    int start;
    int end;
    int cool;
};

struct AC {
    int start;
    int end;
    int cool;
    int price;
};

bool is_valid(vector<Cow >cows, string used_ac, vector<AC > acs){
    vector<int> temps(100);
    for (int i = 0; i < used_ac.size(); i ++){
        if (used_ac[i] == '1'){
            for (int a = acs[i].start; a <= acs[i].end; a ++){
                temps[a - 1] += acs[i].cool;
            }
        }
    }
    for (auto cow : cows){
        for (int i = cow.start; i <= cow.end; i ++){
            if (temps[i - 1] < cow.cool) return false;
        }
    }
    return true;
}

vector<string> search(string current, int m){
    vector<string> result;
    if (current.size() == m) return {current};

    for (string a : {"1", "0"}) {
        auto recurse = search(current + a, m);
        result.insert(result.end(), recurse.begin(), recurse.end());
    }

    return result;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<Cow > cows;
    vector<AC > acs;

    for (int i = 0; i < n; i ++){
        int s, t, c;
        cin >> s >> t >> c;

        cows.push_back(Cow {s, t, c});
    }
    for (int i = 0; i < m; i ++){
        int a, b, p, m;
        cin >> a >> b >> p >> m;

        acs.push_back(AC{a, b, p, m});
    }

    auto perms = search("", m);
    int min_cost = INT32_MAX;

    for (auto perm : perms){
        if (is_valid(cows, perm, acs)){
            int cost = 0;
            for (int i = 0; i < m; i ++){
                if (perm[i] == '1') cost += acs[i].price;
            }
            min_cost = min(cost, min_cost);
        }
    }
    cout << min_cost << endl;

}