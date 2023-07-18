#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string simplified1 = "";

    int n;
    cin >> n;

    for (int i = 0; i < n/2; i ++){
        char a, b;
        cin >> a >> b;
        // cout << a << " " << b << endl;
        if ((a == 'G') && (b == 'H')) simplified1 += "b";
        else if ((a == 'H') && (b == 'G')) simplified1 += "a";
    }
    // cout << simplified1 << endl;

    string simplified2 = "";

    for (auto it : simplified1){
        if (it != simplified2.back()) simplified2 += it;
    }
    // cout << simplified2 << endl;

    while (simplified2.back() == 'a') simplified2.pop_back();

    cout << simplified2.size() << endl;

}