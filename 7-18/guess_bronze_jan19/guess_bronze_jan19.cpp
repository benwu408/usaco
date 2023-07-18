#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<string> animals;
    map<string, set<string>> animalMap;
    for (int i = 0; i < n; i++) {
        string animal;
        int num;
        cin >> animal >> num;
        animals.push_back(animal);

        for (int j = 0; j < num; j++) {
            string trait;
            cin >> trait;
            animalMap[animal].insert(trait);
        }
    }

    int maxOverlap = 0;
    for (int i = 0; i < animals.size(); i++) {
        for (int j = i + 1; j < animals.size(); j++) {
            int overlap = 0;
            for (auto a : animalMap[animals[i]]) {
                if (animalMap[animals[j]].find(a) != animalMap[animals[j]].end()) overlap++;
            }
            maxOverlap = max(maxOverlap, overlap);
        }
    }

    cout << maxOverlap + 1 << endl;
}