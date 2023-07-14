#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int find_perms(vector<pair<int, int> > queens, vector<pair<int, int> > reserved, pair<int, int> point){
    if (queens.size() == 8) return 1;
    if (point == make_pair(0, 8)) return 0;
    pair<int, int> next_point = make_pair(point.first + 1, point.second);
    if (next_point.first == 8){
        next_point = make_pair(0, point.second + 1);
    }
    for (auto queen : queens){
        if (queen.first == point.first || queen.second == point.second || (abs(queen.first - point.first) == abs(queen.second - point.second))){
            return find_perms(queens, reserved, next_point);
        }
    }
    for (auto reserve : reserved){
        if (reserve == point){
            return find_perms(queens, reserved, next_point);
        }
    }
    vector<pair<int, int> > new_queens = queens;
    new_queens.push_back(point);
    return find_perms(new_queens, reserved, next_point) + find_perms(queens, reserved, next_point);
    }


int main() {
    vector<pair<int, int> > reserved;
    for (int y = 0; y < 8; y ++){
        for (int x = 0; x < 8; x ++){
            char point;
            cin >> point;
            if (point == '*') reserved.push_back(make_pair(x, y));
        }
    }

    cout << find_perms(vector<pair<int, int> > {}, reserved, make_pair(0, 0)) << endl;


}