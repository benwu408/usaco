#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<pair<int, int>, int> lawn;
    vector<int> visited_intervals;
    pair<int, int> current_loc = {0, 0};
    lawn[current_loc] = 0;
    int time = 0;
    for (int i = 0; i < n; i ++){
        char d;
        int s;
        cin >> d >> s;
        
        if (d == 'N'){
            for (int x = 1; x <= s; x ++){
                current_loc.second ++;
                time ++;
                if (lawn.find(current_loc) == lawn.end()){
                    lawn[current_loc] = time;
                }
                else{
                    visited_intervals.push_back(time - lawn[current_loc]);
                    lawn[current_loc] = time;
                }
            }
        }
        if (d == 'E'){
            for (int x = 1; x <= s; x ++){
                current_loc.first ++;
                time ++;
                if (lawn.find(current_loc) == lawn.end()){
                    lawn[current_loc] = time;
                }
                else{
                    visited_intervals.push_back(time - lawn[current_loc]);
                    lawn[current_loc] = time;
                }
            }
        }
        if (d == 'S'){
            for (int x = 1; x <= s; x ++){
                current_loc.second --;
                time ++;
                if (lawn.find(current_loc) == lawn.end()){
                    lawn[current_loc] = time;
                }
                else{
                    visited_intervals.push_back(time - lawn[current_loc]);
                    lawn[current_loc] = time;
                }
            }
        }
        if (d == 'W'){
            for (int x = 1; x <= s; x ++){
                current_loc.first --;
                time ++;
                if (lawn.find(current_loc) == lawn.end()){
                    lawn[current_loc] = time;
                }
                else{
                    visited_intervals.push_back(time - lawn[current_loc]);
                    lawn[current_loc] = time;
                }
            }
        }
    }
    if (visited_intervals.size() == 0){
        cout << -1 << endl;
    }
    else{
        cout << *min_element(visited_intervals.begin(), visited_intervals.end()) << endl;
    }
    
}