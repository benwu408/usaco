#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    int b;
    
    cin >> n >> b;
    vector<pair<int, int> > points;
    vector<int> hor_walls;
    vector<int> ver_walls;

    for (int i = 0; i < n; i ++){
        cout << i << endl;
        int x;
        int y;
        cin >> x >> y;
        cout << x << " " << y << endl;
        cout << 0 << endl;
        points.push_back(make_pair(x, y));

        hor_walls.push_back(y + 1);
        cout << 1 << endl;
        ver_walls.push_back(x + 1);
        cout << 2 << endl;
        cout << 3 << endl;
        for (auto it : points){
            cout << it.first << ' ' << it.second << endl;
        }
    }

    cout << "hello";
    sort(points.begin(), points.end());
    cout << "hi";
    
    sort(hor_walls.begin(), hor_walls.end());
    hor_walls.pop_back();
    sort(ver_walls.begin(), ver_walls.end());
    ver_walls.pop_back();

    int min_max = INT32_MAX;
    cout << "points" << endl;
    for (auto point : points)
    cout << point.first << " " << point.second << endl;
    for (auto horwall : hor_walls){
        vector <int> quadrants = {0, 0, 0, 0};
        for (auto point : points){
            if (point.second < horwall)
            quadrants[3] ++;
            else
            quadrants[0] ++;
        }
        for (auto it : quadrants)
        cout << it << " starting " << endl;
        int count = 0;
        for (auto verwall : ver_walls){
            if (points[count].second < horwall){
                quadrants[3] --;
                quadrants[2] ++;
            }
            else{
                quadrants[0] --;
                quadrants[1] ++;
            }
            int max = 0;
            for (auto it : quadrants){
                cout << it << endl;
                if (it > max)
                max = it;
            }
            min_max = min(max, min_max);
            count ++;
        }
        
    }
    cout << min_max << endl;
}