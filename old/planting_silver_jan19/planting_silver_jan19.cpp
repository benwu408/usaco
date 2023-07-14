#include <iostream>
#include <map>
using namespace std;

int main(){
    

    int n;
    cin >> n;

    map<int, int> connections;

    for (int i = 1; i <= n; i ++) connections[i] = 0;

    for (int i = 1; i < n; i ++){
        int a;
        int b;
        
        cin >> a >> b;

        connections[a] ++;
        connections[b] ++;
    } 
    int most_paths = (*max_element(connections.begin(), connections.end(), [](const pair<int, int> &x, const pair<int, int> &y) {return x.second < y.second;})).second;
    // for (auto it : connections){
    //     most_paths = max(most_paths, it.second);
    // }
    cout << most_paths + 1 << endl;
}