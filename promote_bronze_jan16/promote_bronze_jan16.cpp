#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int> > levels;

    for (int i = 0; i < 4; i ++){
        int a;
        int b;
        cin >> a >> b;
        levels.push_back(make_pair(a, b));
    }

    cout  
    << levels[1].second - (levels[1].first - (levels[2].second - (levels[2].first - (levels[3].second - levels[3].first))))
    << endl
    << levels[2].second - (levels[2].first - (levels[3].second - levels[3].first))
    << endl 
    << levels[3].second - levels[3].first 
    << endl;


}