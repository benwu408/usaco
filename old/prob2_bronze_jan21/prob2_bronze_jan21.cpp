#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int even = 0;
    int odd = 0;

    for (int i = 0; i < n; i ++){
        int x;
        cin >> x; 
        if (x%2 == 0) even ++;
        else odd ++;
    }

    int count = 0;
    while (even > 0 || odd > 0){
        if (count%2 == 0){
            if (even > 0) even --;
            else if (odd > 1) odd -= 2;
            else{
                break;
            }
            count ++;
        }
        else{
            if (odd > 0){
                odd --;
            }
            else break;
            count ++;
        }
    }
    if (odd%2 == 1){
        count --;
    }
    cout << count << endl;
}