#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

void print_vec(vector<int> vec){
    for (auto it : vec){
        cout << it << " ";
    }
    cout << endl;
}

// bool find_station(int start, int end, map<int, vector<int> > connections){
//     if (start == end) return true;

//     else if (connections[start].size() == 1) return false;

//     for (auto it : connections[start]){
//         if (it == end) return true;
//     }
//     bool found = false;
//     for (auto it : connections[start]){
//         if (find_station(it, end, connections)){
//             found = true;
//             break;
//         }
//     }
//     return found;
// }

int main() {
    int n;
    cin >> n;

    map<int, set<int> > connects;

    for (int i = 1; i <= n; i ++){
        set<int> vec;
        connects[i] = vec;
    }

    
    

    for (int i = 0; i < n; i ++){
        int begin;
        int end;
        cin >> begin >> end;

        connects[end].insert(begin);
    }

    // for (auto it : connects){
    //     cout << it.first << endl;
    //     print_vec(it.second);

    // }

    // for (int i = 1; i <= n; i ++){
    //     bool connected = true;
    //     for (int x = 1; x <= n; x ++){
    //         if (!find_station(x, i, connects)){
    //             connected = false;
    //             cout << "FAILED " << x << " - " << i << endl;
    //             break;
    //         }
    //         cout << "PASSED " << x << " - " << i << endl;
    //     }
    //     if (connected){
    //         cout << i << endl;
    //         break;
    //     }
    // }
    bool change = true;
    while (change){
        map<int, set<int> > new_connects = connects;
        for (auto it : connects){
            for (auto itr : it.second){
                for (auto itt : connects[itr]){
                    new_connects[it.first].insert(itt);
                }
            }
        }
        if (new_connects == connects){
            change = false;
        } else connects = new_connects;
    }

    for (auto it : connects){
        if (it.second.size() == n - 1) cout << it.first << endl;
    }
    
}