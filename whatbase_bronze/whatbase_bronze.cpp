#include <iostream>
#include <cmath>
using namespace std;

pair<int, int> find_bases(int a1, int a2, int a3, int b1, int b2, int b3){
    for (int x = 10; x <= 15000; x ++){
        // cout << a1 << a2 << a3 << " " << b1 << b2 << b3 << endl;

        long long n = (a1*x*x) + (a2*x) + a3;
        // cout << n << endl;
        // cout << 4*(b1)*(b3-n) << endl;
        
        long double a = sqrt(pow(b2, 2) - (4*(b1)*(b3-n)));
        long double y = (-b2 + a)/(2*b1);
        // cout << a << endl;
        // cout << 24*(b3 - n) << endl;
        
        // cout << x << " " << y << " " << n << endl;
        // cout << endl;
        if (floor(y) == y && y >= 10 && y <= 15000) return make_pair(x, int(y));
    }
    return make_pair(0, 0);
}

int main() {
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i ++){
        char a1, a2, a3, b1, b2, b3;
        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
        // // cout << a1 << a2 << a3 << b1 << b2 << b3 << endl;
        pair<int, int> ans = find_bases(int(a1 - '0'), int(a2 - '0'), int(a3 - '0'), int(b1 - '0'), int(b2 - '0'), int(b3 - '0'));
        cout << ans.first << " " << ans.second << endl;
    }
}