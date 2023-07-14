#include <iostream>
using namespace std;

int main() {
    int lawn_x1, lawn_y1, lawn_x2, lawn_y2;
    cin >> lawn_x1 >> lawn_y1 >> lawn_x2 >> lawn_y2;

    int cover_x1, cover_y1, cover_x2, cover_y2;
    
    int nextInt;

    cin >> nextInt;
    cover_x1 = max(lawn_x1, nextInt);

    cin >> nextInt;
    cover_y1 = max(lawn_y1, nextInt);

    cin >> nextInt;
    cover_x2 = min(lawn_x2, nextInt);

    cin >> nextInt;
    cover_y2 = min(lawn_y2, nextInt);

    if (cover_x1 == lawn_x1 && cover_x2 == lawn_x2) {
        int height = lawn_y2 - lawn_y1;
        int cover = cover_y2 - cover_y1;
        cout << (height - cover) * (lawn_x2 - lawn_x1) << endl;
    } else if (cover_y1 == lawn_y1 && cover_y2 == lawn_y2) {
        int width = lawn_x2 - lawn_x1;
        int cover = cover_x2 - cover_x1;
        cout << (width - cover) * (lawn_y2 - lawn_y1) << endl;
    } else {
        cout << (lawn_x2 - lawn_x1) * (lawn_y2 - lawn_y1) << endl;
    }
}