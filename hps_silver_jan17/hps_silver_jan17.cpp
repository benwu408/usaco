#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> H(n);
    vector<int> P(n);
    vector<int> S(n);

    for (int i = 0; i < n; i ++){
        char a;
        cin >> a;
        if (i > 0){
            H[i] = H[i - 1];
            P[i] = P[i - 1];
            S[i] = S[i - 1];
        }

        if (a == 'H'){
            P[i] ++;
        }
        else if (a == 'P'){
            S[i] ++;
        }
        else{
            H[i] ++;
        }
    }
    int max_games = 0;
    for (int i = 0; i < n; i ++){
        if (H[i] + (P[n - 1] - P[i]) > max_games) max_games = H[i] + (P[n - 1] - P[i]);
        if (H[i] + (S[n - 1] - S[i]) > max_games) max_games = H[i] + (S[n - 1] - S[i]);
        if (P[i] + (H[n - 1] - H[i]) > max_games) max_games = P[i] + (H[n - 1] - H[i]);
        if (P[i] + (S[n - 1] - S[i]) > max_games) max_games = P[i] + (S[n - 1] - S[i]);
        if (S[i] + (H[n - 1] - H[i]) > max_games) max_games = S[i] + (H[n - 1] - H[i]);
        if (S[i] + (P[n - 1] - P[i]) > max_games) max_games = S[i] + (P[n - 1] - P[i]);
    }

    cout << max_games << endl;
    // for (auto x : H){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (auto x : P){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (auto x : S){
    //     cout << x << " ";
    // }
    // cout << endl;
}