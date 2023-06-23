#include <iostream>
#include <set>
using namespace std;

set<int> new_set = {4,3,2,1};

int main(){
    for (auto it : new_set){
        cout << it << endl;
    }
    new_set.erase(--new_set.end());
    for (auto it : new_set){
        cout << it << endl;
    }
    cout << min(-1, 4);
}
