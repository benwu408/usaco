#include <iostream>
using namespace std;

int main() {
    int leftest = INT32_MAX;
    int rightest = INT32_MIN;
    int highest = INT32_MIN;
    int lowest = INT32_MAX;

    int llx1, lly1, urx1, ury1, llx2, lly2, urx2, ury2;
    cin >> llx1 >> lly1 >> urx1 >> ury1 >> llx2 >> lly2 >> urx2 >> ury2;

    for (int x = llx1; x <= urx1; x ++){
        for (int y = lly1; y <= ury1; y ++){
            // cout << x << " " << y << endl;
            if ((x >= urx2 || x <= llx2) || (y >= ury2 || y <= lly2)){
                // cout << "pass" << endl;
                leftest = min(leftest, x);
                rightest = max(rightest, x);
                highest = max(highest, y);
                lowest = min(lowest, y);
            }
        }
    }
    // cout << leftest << " " << rightest << " " << lowest << " " << highest << endl;
    if (leftest == INT32_MAX && highest == INT32_MIN) cout << 0;
    else cout << (rightest - leftest) * (highest - lowest) << endl;


}