#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int a, b, x, y; cin >> a >> b >> x >> y;
    int haul1 = abs(b - a);
    int haul2 = abs(a - x) + abs(b - y);
    int haul3 = abs(a - y) + abs(b - x);
    cout << min(haul1, min(haul3, haul2)) << endl;
}