#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    map<int, pair<int, int> > x;
    for (int i = 0; i < 20; i ++){
        int a, b, c; cin >> a >> b >> c;
        x[a] = make_pair(b, c);
    }
    for (auto it : x){
        cout << it.first << ": " << it.second.first << " " << it.second.second << endl;
    }
}