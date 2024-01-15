#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int grid[100][100];
int rows;
int columns;
bool visited[100][100];
set<int> walls[100][100];

void fill(int r, int c, int color){
    cout << r << " " << c << endl;
    if ((r < 0 || r >= rows || c < 0 || c <= columns)
    || visited [r][c]
    ){
        return;
    }
    cout << "b" << endl;
    visited[r][c] = true;
    grid[r][c] = color;
    
    if (walls[r][c].find(1) == walls[r][c].end()) fill(r - 1, c, color);
    if (walls[r][c].find(2) == walls[r][c].end()) fill(r, c + 1, color);
    if (walls[r][c].find(3) == walls[r][c].end()) fill(r + 1, c, color);
    if (walls[r][c].find(4) == walls[r][c].end()) fill(r, c - 1, color);
    return;
}

int main(){
    int n, k, r; cin >> n >> k >> r;

    int distant = 0;
    vector<pair<int, int> > cows;

    for (int i = 0; i < r; i ++){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        r2--;
        c1--;
        c2--;
        if (r1 == r2){
            if (c1 < c2){
                walls[r1][c1].insert(2);
                walls[r2][c2].insert(4);
            } 
            else{
                walls[r1][c1].insert(4);
                walls[r2][c2].insert(2);
            }
        }
        else{
            if (r1 < r2){
                walls[r1][c1].insert(3);
                walls[r2][c2].insert(1);
            } 
            else{
                walls[r1][c1].insert(1);
                walls[r2][c2].insert(3);
            }
        }
    }

    int rows = n;
    int columns = n;

    for (int i = 1; i < k + 1; i ++){
        int r, c; cin >> r >> c;
        r--;
        c--;
        cows.push_back(make_pair(r, c));
        if (!visited[r][c]){
            cout << "a" << endl;
            fill(r, c, i);
        }
    }

    for (int a = 0; a < k - 1; a ++){
        for (int b = a + 1; b < k; b ++){
            if (grid[cows[a].first][cows[a].second] != grid[cows[b].first][cows[b].second]) distant ++;
        }
    }

    for (int r = 0; r < 3; r ++){
        for (int c = 0; c < 3; c ++){
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }

    cout << distant << endl;
}