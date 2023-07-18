#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int BOARD_SIZE = 8;
const int NUM_QUEENS = 8;

struct Solution {
    set<pair<int, int>> restricted;
    

    Solution(set<pair<int, int>> restricted_) {
        restricted = restricted_;
    }

    int solve(vector<pair<int, int>> queens, pair<int, int> currentPoint) {
        if (currentPoint.first == BOARD_SIZE) return queens.size() == NUM_QUEENS ? 1 : 0;

        pair<int, int> nextPoint = currentPoint.second < BOARD_SIZE - 1 ? 
            make_pair(currentPoint.first, currentPoint.second + 1) : 
            make_pair(currentPoint.first + 1, 0);

        if (restricted.count(currentPoint) > 0) {
            return solve(queens, nextPoint);
        }

        for (auto pair : queens) {
            bool rowCol = pair.first == currentPoint.first || pair.second == currentPoint.second;
            bool diagonal = abs(pair.first - currentPoint.first) == abs(pair.second - currentPoint.second);
            if (rowCol || diagonal) {
                return solve(queens, nextPoint);
            }
        }

        int dontAdd = solve(queens, nextPoint);

        queens.push_back(currentPoint);
        int add = solve(queens, nextPoint);

        return add + dontAdd;
    }

};


int main() {
    set<pair<int, int>> restricted;
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            char x;
            cin >> x;
            if (x == '*') {
                restricted.insert(make_pair(r, c));
            }
        }
    }

    Solution s = Solution(restricted);
    int ans = s.solve({}, make_pair(0, 0));
    cout << ans << endl;
}