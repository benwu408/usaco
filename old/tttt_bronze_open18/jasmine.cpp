#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<string> string_rows; // ['XXX', 'XYZ', 'ZZZ']
    for (int i = 0; i < 3; i++)  {
        string nextRow;
        cin >> nextRow;
        string_rows.push_back(nextRow);
    }

    vector<unordered_set<char>> all_sets;

    // make set versions of all row and column combos
    vector<unordered_set<char>> rows;
    vector<unordered_set<char>> columns(3);

    for (int x = 0; x < 3; x ++){
        unordered_set<char> row (string_rows[x].begin(), string_rows[x].end());
        rows.push_back(row);
        
        for (int i = 0; i < 3; i ++){
            columns[i].insert(string_rows[x][i]);
        }
    }

    all_sets.insert(all_sets.end(), rows.begin(), rows.end());
    all_sets.insert(all_sets.end(), columns.begin(), columns.end());

    // make set versions of all diagonals
    vector<unordered_set<char>> diagonals(2);
    for (int i = 0; i < 3; i++) {
        diagonals[0].insert(string_rows[i][i]);
        diagonals[0].insert(string_rows[i][2 - i]);
    }

    all_sets.insert(all_sets.end(), diagonals.begin(), diagonals.end());

    set<char> ind;
    set<pair<char, char> > doub;
    for (auto it : all_sets){
        if (it.size() == 1){
            ind.insert(*it.begin());
        }
        else if (it.size() == 2) {
            auto first = *(it.begin());
            auto second = *(next(it.begin()));
            doub.insert(make_pair(min(first, second), max(first, second)));
        }
    }
    cout << ind.size() << endl << doub.size() << endl;
}