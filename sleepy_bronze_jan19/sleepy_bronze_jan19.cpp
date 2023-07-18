#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> cows;

    int count = 1;

    for (int i = 0; i < n; i ++){
        int cow;
        cin >> cow;
        if (i > 0){
            if (cow > cows[i - 1]) count ++;
            else count = 1;
        }
        cows.push_back(cow);
    }
    cout << n - count << endl;
}