#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a;
    int b;
    int c;

    
    cin >> a >> b >> c;

    int first_out = 2;
    int second_out = max(c - b - 1, b - a - 1);

    if (c - b - 1 == 0 && b - a - 1 == 0){
        first_out = 0;
        second_out = 0;
    } else if (c - b - 1 == 1 || b - a - 1 == 1){
        first_out = 1;
    } 

    cout << first_out << endl << second_out << endl;
}