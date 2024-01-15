#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > spotted;
    vector<vector<int> > plain;
    vector<int> cows(1000);

    // vector<char> s = {'A', 'T', 'C'};
    // do cows[s] = false;
    // while (next_permutation(s.begin(), s.end()));

    // s = {'A', 'T', 'G'};
    // do cows[s] = false;
    // while (next_permutation(s.begin(), s.end()));

    // s = {'A', 'G', 'C'};
    // do cows[s] = false;
    // while (next_permutation(s.begin(), s.end()));

    // s = {'G', 'T', 'C'};
    // do cows[s] = false;
    // while (next_permutation(s.begin(), s.end()));

    for (int a = 0; a < n; a ++){
        vector<int> cow;
        for (int b = 0; b < m; b ++){
            char x; cin >> x;
            if (x == 'A') cow.push_back(0);
            if (x == 'C') cow.push_back(1);
            if (x == 'G') cow.push_back(2);
            if (x == 'T') cow.push_back(3);
        }
        spotted.push_back(cow);
    }

    for (int a = 0; a < n; a ++){
        vector<int> cow;
        for (int b = 0; b < m; b ++){
            char x; cin >> x;
            if (x == 'A') cow.push_back(0);
            if (x == 'C') cow.push_back(1);
            if (x == 'G') cow.push_back(2);
            if (x == 'T') cow.push_back(3);
        }
        plain.push_back(cow);
    }
    // for (auto it : spotted){
    //     for (auto it1 : it){
    //         cout << it1 << " ";
    //     }
    //     cout << endl;
    // }
    // for (auto it : plain){
    //     for (auto it1 : it){
    //         cout << it1 << " ";
    //     }
    //     cout << endl;
    // }
    int count = 0;

    for (int a = 0; a < m - 2; a ++){
        for (int b = a + 1; b < m - 1; b ++){
            for (int c = b + 1; c < m; c ++){
                cout << a << " " << b << " " << c << endl;
                for (auto it : plain){
                    cows[16*(it[a]) + 4*(it[b]) + it[c]] = true;
                }
                bool works = true;
                for (auto it : spotted){
                    if (cows[16*(it[a]) + 4*(it[b]) + it[c]]){
                        works = false;
                        break;
                    }
                }
                for (auto it : plain){
                    cows[16*(it[a]) + 4*(it[b]) + it[c]] = false;
                }
                if (works) {
                    count ++;
                    
                }
            }
        }
    }
    cout << count << endl;
}