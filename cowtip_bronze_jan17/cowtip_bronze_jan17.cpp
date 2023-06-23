#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > rows;
    pair<int, int> lowest = make_pair(-1, -1);
    pair<int, int> rightest = make_pair(-1, -1);
    for (int y = 0; y < n; y ++){
        vector<int> row;
        for (int x = 0; x < n; x ++){
            char cow_char;
            cin >> cow_char;
            int cow = cow_char - '0';
            row.push_back(cow);
            if (cow == 1){
                if (y >= lowest.second) lowest = make_pair(x, y);
                if (x >= rightest.first) rightest = make_pair(x, y);
            }
        }
        rows.push_back(row);
    }
    int count = 0;
    for (auto row : rows){
        for (auto cow : row){
            cout << cow << " ";
        }
        cout << endl;
    }
    cout << "intial" << endl;
    cout << lowest.first << " " << lowest.second << endl;
    cout << rightest.first << " " << rightest.second << endl;
    cout << endl;

    while (lowest != make_pair(-1, -1) || rightest != make_pair(-1, -1)){
        cout << lowest.first << " " << lowest.second << endl;
        cout << rightest.first << " " << rightest.second << endl;
        if (lowest == rightest){
            pair<int, int> old_corner = lowest;
            rightest = make_pair(-1, -1);
            lowest = make_pair(-1, -1);
            for (int y = 0; y <= old_corner.second; y ++){
                for (int x = 0; x <= old_corner.first; x ++){
                    rows[y][x] = (rows[y][x] + 1)%2;
                    if (rows[y][x] == 1){
                        if (y >= lowest.second) lowest = make_pair(x, y);
                        if (x >= rightest.first) rightest = make_pair(x, y);
                    }
                }
            }
            count ++;
        }
        else{
            pair<int, int> old_low = lowest;
            pair<int, int> old_right = rightest;
            rightest = make_pair(-1, -1);
            lowest = make_pair(-1, -1);
            for (int y = 0; y <= old_low.second; y ++){
                for (int x = 0; x <= old_right.first; x ++){
                    if ((x > old_low.first && y <= old_right.second) || (y > old_right.second && x <= old_low.second)){
                        rows[y][x] = (rows[y][x] + 1)%2;
                    }
                    if (rows[y][x] == 1){
                        if (y > lowest.second) lowest = make_pair(x, y);
                        if (x > rightest.first) rightest = make_pair(x, y);
                    }
                }
            }
            count += 2;
        }
    }
    cout << count << endl;
    
}