#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, int> alphabet{
        {'a', 0},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 0},
        {'t', 0},
        {'u', 0},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 0},
        {'z', 0}
    };

    for (int i = 0; i < n; i ++){
        map<char, int> alphabet1{
        {'a', 0},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 0},
        {'t', 0},
        {'u', 0},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 0},
        {'z', 0}
        };

        string word1;
        string word2;
        cin >> word1 >> word2;

        for (int i = 0; i < word1.size(); i ++){
            alphabet1[word1[i]] ++;
        }
        
        for (int i = 0; i < word2.size(); i ++){
            alphabet1[word2[i]] ++;
        }
        
        for (auto i : alphabet1) {
            if (i.second > 0){
                alphabet[i.first] ++;
            }
        }

        }
    for (auto i : alphabet){
        cout << i.second << endl;
    }
    }
}