#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x;
    int y;
    cin >> x >> y;
    int total_dist = 0;
    for (int i = 0; i < 11; i ++)
    {
        if (i%2 == 0){
            if (x + (pow(2, i)) >= y && x <= y){
                total_dist += abs(y-x);
                break;
            } 
            else{
                total_dist += 2 * pow(2, i);
            }
        }
        else{
            if (x - pow(2, i) <= y && x >= y){
                total_dist += abs(y-x);
                break;
            }
            else{
                total_dist += 2 * pow(2, i);
            }
        }
    }
    cout << total_dist;
}