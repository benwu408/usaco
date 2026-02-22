#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> cards(2*n + 1);
    vector<int> bessie(n);
    vector<int> elsie;

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        cards[x] = 1;
        bessie[i] = x;
    }
    for (int i = 1; i < 2*n + 1; i ++){
        if (cards[i] == 0) elsie.push_back(i);
    }

    int count = 0;
    
    for (auto it : bessie){
        for (int i = 0; i < n; i ++){
            // cout << it << elsie[i] << endl;
            if (elsie[i] > it){
                count ++;
                elsie[i] = 0;
                break;
            }
        }
    }
    cout << count << endl;
}