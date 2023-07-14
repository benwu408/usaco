#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > points;
    vector<pair<pair<int, int>, pair<int, int> > > hor_lines;

    for (int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;

        for (auto point : points){
            if (point.second == y) hor_lines.push_back(make_pair(point, make_pair(x, y)));
        }

        points.push_back(make_pair(x, y));
    }

    int biggest = 0;

    for (auto line : hor_lines){
        for (auto point : points){
            if (point.first == line.first.first) biggest = max(biggest, abs(line.first.first - line.second.first) * abs(line.first.second - point.second));
            else if (point.first == line.second.first) biggest = max(biggest, abs(line.first.first - line.second.first) * ( abs(line.first.second - point.second)));
        }
    }

    cout << biggest << endl;
}