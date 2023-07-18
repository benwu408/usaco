#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int most_shared = 0;
    map<string, set<string>> animals;
    map<string, int> animal_shared;

    for (int i = 0; i < n; i ++){
        string animal;
        int a;
        cin >> animal;
        cin >> a;

        animals[animal] = set<string> {};
        map<string, int> shared = animal_shared;
        for (int b = 0; b < a; b ++){
            string trait;
            cin >> trait;

            animals[animal].insert(trait);
            for (auto &it : shared){
                if (animals[it.first].find(trait) != animals[it.first].end()) {
                    it.second ++;
                    most_shared = max(most_shared, it.second);
                }
            }
        }
        animal_shared[animal] = 0;
    }
    cout << most_shared + 1 << endl;
}