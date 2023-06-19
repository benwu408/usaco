#include <iostream>
using namespace std;
#include <string>

int main() {
    int m;
    int n;
    int k;
    cin >> m >> n >> k;
    for (int a = 0; a < m; a ++)
    {
        string line;
        cin >> line;
        for (int b = 0; b < k; b ++)
        {
            for (int c = 0; c < n; c ++)
            {
                char symbol = line[c];
                string next(k, symbol);
                cout << next;
            }
            cout << endl;
        }
    }
}