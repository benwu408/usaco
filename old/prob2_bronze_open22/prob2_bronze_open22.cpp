#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, char> cows;

    int n;
    cin >> n;
    int min_lying = 1000;

    for (int i = 0; i < n; i ++){
        char dir;
        int p;
        cin >> dir >> p;

        cows[p] = dir;
    }


    for (auto cow : cows){
        int count = 0;
        for (auto cow1 : cows){
            if (cow1.second == 'G' && cow.first < cow1.first){
                count ++;
            }
            if (cow1.second == 'L' && cow.first > cow1.first){
                count ++;
            }
        }
        if (count < min_lying){
            min_lying = count;
        }
    }
    cout << min_lying << endl;
}