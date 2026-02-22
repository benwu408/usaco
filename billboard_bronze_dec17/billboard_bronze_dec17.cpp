#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector<int> bb1 = {x1, y1, x2, y2};
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> bb2 = {x1, y1, x2, y2};
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> truck = {x1, y1, x2, y2};

    int overlapx1, overlapy1;
    int overlapx2, overlapy2;

    if (truck[0] < bb1[2] && truck[0] > bb1[0]){
        if (truck[2] < bb1[2] && truck[2] > bb1[0]){
            overlapx1 = truck[2] - truck[0];
        }
        else overlapx1 = bb1[2] - truck[0];
    }
    else if (truck[2] < bb1[2] && truck[2] > bb1[0]){
        overlapx1 = truck[2] - bb1[0];
    }
    if (truck[1] < bb1[3] && truck[1] > bb1[1]){
        if (truck[3] < bb1[3] && truck[3] > bb1[1]){
            overlapy1 = truck[3] - truck[1];
        }
        else overlapy1 = bb1[3] - truck[1];
    }
    else if (truck[3] < bb1[3] && truck[3] > bb1[1]){
        overlapy1 = truck[3] - bb1[1];
    }
    if (truck[0] < bb2[2] && truck[0] > bb2[0]){
        if (truck[2] < bb2[2] && truck[2] > bb2[0]){
            overlapx2 = truck[2] - truck[0];
        }
        else overlapx2 = bb2[2] - truck[0];
    }
    else if (truck[2] < bb2[2] && truck[2] > bb2[0]){
        overlapx2 = truck[2] - bb2[0];
    }
    if (truck[1] < bb2[3] && truck[1] > bb2[1]){
        if (truck[3] < bb2[3] && truck[3] > bb2[1]){
            overlapy2 = truck[3] - truck[1];
        }
        else overlapy2 = bb2[3] - truck[1];
    }
    else if (truck[3] < bb2[3] && truck[3] > bb2[1]){
        overlapy2 = truck[3] - bb2[1];
    }
    cout << ((bb1[3] - bb1[0]) * (bb1[4] - bb1[2])) + ((bb2[3] - bb2[0]) * (bb2[4] - bb2[2])) - overlapx1 * overlapy1 - overlapx2 * overlapy2 << endl;
}