#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> rooms;
    
    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        rooms.push_back(x);
    }

    int min_val = INT32_MAX;

    for (int i = 0; i < n; i ++){
        int current = 0;
        for (int a = 0; a < n; a ++){
            int dist = (a + n - i) % n;
            current += dist * rooms[a];
        }
        min_val = min(current, min_val);
    }
    cout << min_val << endl;
}