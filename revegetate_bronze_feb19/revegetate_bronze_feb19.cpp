#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> pastures(n + 1);
    vector<pair<int, int> > cows;
    map<int, vector<int> > connects;


    int next = 2;

    for (int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        if (connects.find(a) == connects.end()) connects[a] = vector<int> {b};
        else connects[a].push_back(b);
        if (connects.find(b) == connects.end()) connects[b] = vector<int> {a};
        else connects[b].push_back(a);
    }

    for (int i = 1; i <= n; i ++){
        for (int a = 1; a <= n; a ++){
            bool works = true;
            for (auto it : connects[i]){
                if (pastures[it] == a){
                    works = false;
                    break;
                }
            }
            if (works){
                pastures[i] = a;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        cout << pastures[i];
    }
    cout << endl;
}