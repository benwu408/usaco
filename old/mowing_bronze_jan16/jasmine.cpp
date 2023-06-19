#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void update_loc(pair<int, int>* current_loc, char d) {
    switch(d) {
        case 'N':
            (*current_loc).second++;
            return;
        case 'E':
            (*current_loc).first++;
            return;
        case 'S':
            (*current_loc).second--;
            return;
        case 'W':
            (*current_loc).first--;
            return;
        default:
            throw ("unknown direction");
    }
}

int main() {
    int n;
    cin >> n;

    map<pair<int, int>, int> lawn;
    pair<int, int> current_loc = {0, 0};
    lawn[current_loc] = 0;

    int current_time = 0;
    int min_interval = INT32_MAX;
    
    for (int i = 0; i < n; i++){
        char d;
        int s;
        cin >> d >> s;

        for (int x = 1; x <= s; x ++){
            update_loc(&current_loc, d);
            current_time ++;
            if (lawn.find(current_loc) != lawn.end() && current_time - lawn[current_loc] < min_interval) {
                min_interval = current_time - lawn[current_loc];
            }
            lawn[current_loc] = current_time;
        }
    }
    if (min_interval == INT32_MAX){
        cout << -1 << endl;
    }
    else{
        cout << min_interval << endl;
    }
    
}