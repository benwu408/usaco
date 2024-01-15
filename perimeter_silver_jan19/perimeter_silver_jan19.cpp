#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

bool grid[1000][1000];
int n;
bool visited[1000][1000];
int curr_size = 0;
int perimeter = 0;
pair<int, int> best = make_pair(0, 0);

int num_exposed(int x, int y, bool color) {
    int total = 0;
    if (x == 0 || grid[y][x - 1] != color) total ++;
    if (y == 0 || grid[y - 1][x] != color) total ++;
    if (y == 999 || grid[y + 1][x] != color) total ++;
    if (x == 999 || grid[y][x + 1] != color) total ++;
    return total;
}

void floodfill(int x, int y, bool color) {
    if (x < 0 || y < 0 || x >= n || y >= n || grid[y][x] != color|| visited[y][x]) return;

    visited[y][x] = true;
    curr_size ++;
    perimeter += num_exposed(x, y, color);
    // cout << x << " " << y << " " << num_exposed(x, y, color) << endl;

    floodfill(x, y + 1, color);
    floodfill(x, y - 1, color);
    floodfill(x + 1, y, color);
    floodfill(x - 1, y, color);
}

int main() {

    cin >> n;

    for (int y = 0; y < n; y ++){
        for (int x = 0; x < n; x ++){
            char a;
            cin >> a;
            if (a == '#') grid[y][x] = true;
        }
    }

    for (int y = 0; y < n; y ++){
        for (int x = 0; x < n; x ++){
            if (!visited[y][x] && grid[y][x]) {
                curr_size = 0;
                perimeter = 0;

                floodfill(x, y, true);
                if (curr_size > best.first || (curr_size == best.first && perimeter < best.second)) best = make_pair(curr_size, perimeter);
            }
        }
    }
    cout << best.first << " " << best.second << endl;
    // cin >> n;
    // pair<int, int> best_blob = make_pair(0, 0);

    // set<pair<int, int> > to_search;

    // set<pair<int, int> > searched;

    // vector<vector<int> > machine;
    // cout << "a" << endl;

    // for (int x = 0; x < n; x ++){
    //     for (int y = 0; x < n; x ++) to_search.insert(make_pair(x, y));
    // }
    // cout << "a " << endl;
    // for (int y = 0; y < n; y ++){
    //     vector<int> line;
    //     for (int x = 0; x < n; x ++){
    //         char a;
    //         cin >> a;
    //         cout << a << endl;
    //         line.push_back(a);
    //     }
    //     machine.push_back(line);
    // }
    // cout << "x" << endl;
    // for (auto point : to_search){
    //     if (searched.find(point) == searched.end()){
    //         searched.insert(point);
    //         if (machine[point.second][point.first] == '#'){
    //             set<pair<int, int> > new_blob {point};
    //             set<pair<int, int> > agenda {point};
    //             int connections = 0;

    //             while (agenda.size() > 0){
    //                 point = *agenda.begin();
    //                 cout << point.first << " " << point.second << endl;
    //                 if (point.first > 0){
    //                     searched.insert(make_pair(point.first - 1, point.second));
    //                     if (machine[point.second][point.first - 1] == '#'){
    //                         connections ++;
    //                         if (searched.find(make_pair(point.first - 1, point.second)) == searched.end()){
    //                             new_blob.insert(make_pair(point.first - 1, point.second));
    //                             agenda.insert(make_pair(point.first - 1, point.second));
    //                         }
                            
    //                     }
    //                 }
    //                 if (point.first < n - 1){
    //                     searched.insert(make_pair(point.first + 1, point.second));
    //                     if (machine[point.second][point.first + 1] == '#'){
    //                         connections ++;
    //                         if (searched.find(make_pair(point.first + 1, point.second)) == searched.end()){
    //                             new_blob.insert(make_pair(point.first + 1, point.second));
    //                             agenda.insert(make_pair(point.first + 1, point.second));
    //                         }
    //                     }
    //                 }
    //                 if (point.second > 0){
    //                     searched.insert(make_pair(point.first, point.second - 1));
    //                     if (machine[point.second - 1][point.first] == '#'){
    //                         connections ++;
    //                         if (searched.find(make_pair(point.first, point.second - 1)) == searched.end()){
    //                             new_blob.insert(make_pair(point.first, point.second - 1));
    //                             agenda.insert(make_pair(point.first, point.second - 1));
    //                         }
    //                     }
    //                 }
    //                 if (point.second < n - 1){
    //                     searched.insert(make_pair(point.first, point.second + 1));
    //                     if (machine[point.second + 1][point.first] == '#'){
    //                         connections ++;
    //                         if (searched.find(make_pair(point.first, point.second + 1)) == searched.end()){
    //                             new_blob.insert(make_pair(point.first, point.second + 1));
    //                             agenda.insert(make_pair(point.first, point.second + 1));
    //                         }
                            
    //                     }
    //                 }
    //                 agenda.erase(agenda.begin());
    //             }
    //             int perim = (new_blob.size() * 4) - connections;
    //             if (new_blob.size() > best_blob.first || (new_blob.size() == best_blob.first && perim < best_blob.second)) best_blob = make_pair(new_blob.size(), perim);
    //             }
                
    //         }
    //     }
        
    
    // cout << best_blob.first << " " << best_blob.second << endl;
}