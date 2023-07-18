#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

void printVec(vector<string> vec) {
    for (auto str : vec) {
        cout << str << ", ";
    }
    cout << endl;
}

void printPerms(vector<vector<string>> perms) {
    for (auto perm : perms) {
        printVec(perm);
    }
}

void printDescriptors(map<string, set<string>> descriptors) {
    for (auto pair : descriptors) {
        cout << pair.first << ": ";
        for (auto a : pair.second) {
            cout << a << ", ";
        }
        cout << endl;
    }
}

vector<vector<string>> getPermutations(vector<string> traits) {
    cout << "hi" << endl;
    if (traits.size() == 1) return {traits, {}};

    auto traitsCopy = vector<string>(traits.begin(), traits.end());
    traitsCopy.erase(traitsCopy.begin());

    auto perms = getPermutations(traitsCopy);

    vector<vector<string>> allPerms;
    for (auto p : perms) {
        allPerms.push_back(vector<string>(p));
        p.insert(p.begin(), traits[0]);
        allPerms.push_back(vector<string>(p));
    }

    return allPerms;
}

int getGuesses(map<string, set<string>> descriptors, vector<string> order) {
    int guesses = 0;

    for (string trait : order) {

        if (descriptors[trait].size() <= 1) break;

        for (auto p : descriptors) {
            set<string> newSet;
            for (auto a : p.second) {
                if (descriptors[trait].find(a) != descriptors[trait].end()) newSet.insert(a);
            }
            descriptors[p.first] = newSet;
        }

        guesses++;
        descriptors.erase(trait);
    }

    return guesses + 1;
}

int main() {
    int n;
    cin >> n;

    set<string> traits;
    map<string, set<string>> descriptors;
    for (int i = 0; i < n; i++) {
        string animal;
        int num;
        cin >> animal >> num;

        for (int j = 0; j < num; j++) {
            string descriptor;
            cin >> descriptor;
            descriptors[descriptor].insert(animal);
            traits.insert(descriptor);
        }
    }

    vector<string> traitsVec = vector<string>(traits.begin(), traits.end());
    sort(traitsVec.begin(), traitsVec.end(), [&](const string str1, const string str2) {
        return descriptors[str1].size() > descriptors[str2].size();
    });

    printVec(traitsVec);

    auto perms = getPermutations(traitsVec);
    
    int maxGuesses = 0;
    for (auto perm : perms) {
        printVec(perm);
        if (perm.size() + 1 > maxGuesses) {
            int newGuessCount = getGuesses(descriptors, perm);
            maxGuesses = max(maxGuesses, newGuessCount);
        }
    }

    cout << maxGuesses << endl;
}