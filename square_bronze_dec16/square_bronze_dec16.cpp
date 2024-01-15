#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int x11, y11, x21, y21, x12, y12, x22, y22; cin >> x11 >> y11 >> x21 >> y21 >> x12 >> y12 >> x22 >> y22;
    int x_side = max(max(max(x11, x21), x12), x22) - min(min(min(x11, x21), x12), x22);
    int y_side = max(max(max(y11, y21), y12), y22) - min(min(min(y11, y21), y12), y22);
    cout << pow((max(x_side, y_side)), 2) << endl;
}