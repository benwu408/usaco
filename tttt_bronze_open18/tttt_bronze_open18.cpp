#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    string rowa;
    string rowb;
    string rowc;
    cin >> rowa >> rowb >> rowc;
    vector<string> string_rows;
    string_rows.push_back(rowa);
    string_rows.push_back(rowb);
    string_rows.push_back(rowc);

    vector<unordered_set<char> > all_sets;
    unordered_set<char> col1;
    unordered_set<char> col2;
    unordered_set<char> col3;
    for (int x = 0; x < 3; x ++){
        unordered_set<char> new_set_hor (string_rows[x].begin(), string_rows[x].end());
        all_sets.push_back(new_set_hor);
        
        for (int i = 0; i < 3; i ++){
            if (i == 0){
                col1.insert(string_rows[x][i]);
            }
            else if (i == 1){
                col2.insert(string_rows[x][i]);
            }
            else{
                col3.insert(string_rows[x][i]);
            }
        }
    }
    all_sets.push_back(col1);
    all_sets.push_back(col2);
    all_sets.push_back(col3);
    unordered_set<char> diag1;
    unordered_set<char> diag2;
    diag1.insert(string_rows[0][0]);
    diag1.insert(string_rows[1][1]);
    diag1.insert(string_rows[2][2]);
    diag2.insert(string_rows[0][2]);
    diag2.insert(string_rows[1][1]);
    diag2.insert(string_rows[2][0]);
    all_sets.push_back(diag1);
    all_sets.push_back(diag2);

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