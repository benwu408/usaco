#include <iostream>
using namespace std;

int main() {
    int x;
    int y;
    int m;

    cin >> x >> y >> m;

    int max = 0;

    int maxx = m/x;
    int maxy = m/y;
    
    for (int i = 0; i <= maxx; i ++){
        int total = (x * i) + (((m - (x * i))/y)*y);
        if (total > max){
            max = total;
        }
    }
    for (int i = 0; i <= maxy; i ++){
        int total = (y * i) + (((m - (y * i))/x)*x);
        if (total > max){
            max = total;
        }
    }
    cout << max;
}