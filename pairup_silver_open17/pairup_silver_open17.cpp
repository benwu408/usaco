#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main(){
    map<int, int> cows;
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++){
        int x, y; cin >> x >> y;
        cows[y] = x;
    }

    map<int, int>::iterator it1 = cows.begin();
    map<int, int>::iterator it2 = cows.end();

    int max_time = 0;

    while (it1 != it2){
        max_time = max(max_time, (*it1).first + (*it2).first);
        if ((*it1).second > (*it2).second){
            (*it1).second -= (*it2).second;
            it2 --;
        }
        else if ((*it2).second > (*it1).second){
            (*it2).second -= (*it1).second;
            it1 ++;
        }
        else{
            break;
        }
    }

    cout << max_time << endl;
}