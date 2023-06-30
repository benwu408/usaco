#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

void print_vector(vector<int> vec) {
    for (auto it : vec){
        cout << it << " ";
    }
    cout << endl;
}

int find_best(vector<int> people1, int prev_singles) {
    if (people1.size() == 0 || people1.size() == 1) return 0;

    else if (prev_singles == 0) return (people1[1] - people1[0]) + find_best(vector<int> (people1.begin() + 2, people1.end()), 0);

    else if (prev_singles == 2 && people1.size() == 2) return 0;

    else{
        return min(people1[1] - people1[0] + find_best(vector<int> (people1.begin() + 2, people1.end()), prev_singles),
        find_best(vector<int> (people1.begin() + 1, people1.end()), prev_singles - 1));
    }
}

int main() {
    int n;
    cin >> n;

    

    vector <int> people;

    for (int i = 0; i < n * 2; i ++){
        int person;
        cin >> person;
        people.push_back(person);
    }

    sort(people.begin(), people.end());



    cout << find_best(people, 2) << endl;
    
    


}