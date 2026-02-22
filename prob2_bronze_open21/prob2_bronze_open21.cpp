#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > cows;
map<string, int> cow_pos;

void update(string cow1, string cow2, int relation){
    cows[cow_pos[cow1]][cow_pos[cow2]] = char(relation);
    cows[cow_pos[cow2]][cow_pos[cow1]] = char((relation + 1) % 2);
}

int main(){
    int k, n; cin >> k >> n;


    for (int i = 0; i < n; i ++){
        string cow; cin >> cow;
        cows.push_back({});
        cow_pos[cow] = i;
        for (int a = 0; a < n; a ++){
            if (a == i) cows[cows.size() - 1].push_back(5);
            else cows[cows.size() - 1].push_back(-1);
        }
    }

    for (int i = 0; i < k; i ++){
        // for (auto it : cows){
        //     for (auto it1 : it) cout << it1;
        //     cout << endl;
        // }
        vector<string> line;
        for (int a = 0; a < n; a ++){
            string cow; cin >> cow; line.push_back(cow);
        }
        // cout << 1 << endl;
        // for (auto it : line) cout << it << " ";
        // cout << endl;
        for (int a = n - 1; a > 0; a --){
            // cout << a << endl;
            // if (cows[cow_pos[line[a]]][cow_pos[line[a - 1]]]== 1){
            //     for (int b = a + 1; b < n; b ++){
            //         update(line[b], line[a - 1], 1);
            //     }
            //     for (int b = a - 2; b >= 0; b --){
            //         update(line[a], line[b], 1);
            //     }
            // }
            // else if (cows[cow_pos[line[a]]][cow_pos[line[a + 1]]] == 0){
            //     for (int b = a + 2; b < n; b ++){
            //         update(line[b], line[a], 1);
            //     }
            //     for (int b = a - 1; b >= 0; b --){
            //         update(line[a + 1], line[b], 1);
            //     }
            // }
            if (line[a] < line[a - 1]){
                for (int b = a - 1; b >= 0; b --){
                    for (int c = a; c < n; c ++){
                        update(line[c], line[b], 1);
                    }
                }
            }
            
        }
    }
    for (auto it : cows){
        for (auto it1 : it){
            if (it1 == 5) cout << 'B';
            else if (it1 == -1) cout << "?";
            else cout << it1;
        } 
        cout << endl;
    }

    


}