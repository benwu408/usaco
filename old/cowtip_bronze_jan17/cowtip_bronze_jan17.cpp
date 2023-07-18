#include <iostream>
#include <vector>
using namespace std;

pair<int, int> flipAndFindLowest(vector<vector<int>>* rows, pair<int, int> old_corner) {
    pair<int, int> lowest = make_pair(-1, -1);
    for (int y = 0; y < (*rows).size(); y ++){
        for (int x = 0; x < rows[0].size(); x ++){
            if (old_corner.first >= 0 && x <= old_corner.first && y <= old_corner.second) {
                (*rows)[y][x] = ((*rows)[y][x] + 1)%2;
            }
            if ((*rows)[y][x] == 1){
                if (y >= lowest.second) lowest = make_pair(x, y);
            }
        }
    }
    return lowest;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > rows (n);
    for (int y = 0; y < n; y ++){
        for (int x = 0; x < n; x ++){
            char cow_char;
            cin >> cow_char;
            rows[y].push_back(cow_char - '0');
        }
    }

    pair<int, int> lowest = make_pair(-1, -1);
    int count = 0;

    lowest = flipAndFindLowest(&rows, make_pair(-1, -1));
    while (lowest.first != -1) {
        lowest = flipAndFindLowest(&rows, lowest);
        count ++;
        
    }
    cout << count << endl;
}