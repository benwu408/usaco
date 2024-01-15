#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(){
    int n, k; cin >> n >> k;


    int curr_line = 0;

    for (int i = 0; i < n; i ++){
        string x; cin >> x;
        // cout << curr_line << " " << x.size() << endl;
        if (curr_line + x.size() > k){
            cout << endl << x;
            curr_line = x.size();
        }
        else if (curr_line + x.size() <= k){
            if (curr_line > 0) cout << " ";
            cout << x;
            // cout << "a";
            // cout << curr_line << endl;
            curr_line += x.size();
            // cout << curr_line << endl;
        }

    }
    cout << endl;
}