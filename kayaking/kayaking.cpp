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
    // print_vector(people1);
    // cout << prev_singles << endl;
    if (prev_singles == 0 && people1.size() == 2){
        return people1[1] - people1[0];
    } 
    else if (people1.size() == 1) return 0;
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
    // vector <int> differences;
    for (int i = 0; i < n * 2; i ++){
        int person;
        cin >> person;
        people.push_back(person);
        // if (i > 0){
        //     differences.push_back(person - people[i - 1]);
        // }
    }

    sort(people.begin(), people.end());

    // print_vector(people);


    cout << find_best(people, 2) << endl;
    
    



    // for (int i = 0; i < n - 1; i ++){
    //     pair<int, int> min_dif = make_pair(INT32_MAX, 0);
    //     // cout << people.size();
    //     // for (auto it : people) {
    //     //     cout << it << endl;
    //     // }
    //     for (int x = 0; x < people.size() - 1; x ++){
    //         if (people[x + 1] - people[x] < min_dif.first){
    //             min_dif = make_pair(people[x + 1] - people[x], x);
    //         }
    //     }
    //     min_instability += min_dif.first;
    //     people.erase(people.begin() + min_dif.second, people.begin() + min_dif.second + 2);
    //     sort(people.begin(), people.end());
    // }
    // cout << "differences" << endl;
    // for (auto it : differences){
    //     cout << it.first << " " << it.second << endl;
    // }

    // cout << "people" << endl;
    // for (auto it : people){
    //     cout << it << endl;
    // }
    // int count = 0;
    // for (auto it : differences){
    //     if (count < n - 1) {
    //         if (people[it.second] > 0 && people[it.second + 1] > 0){
    //             min_instability += it.first;
    //             people[it.second] = 0;
    //             people[it.second + 1] = 0;
    //             count ++;
    //         }
    //     }
    // }
    // for (int i = 0; i < n - 1; i ++){
    //     pair<int, int> min_dif = make_pair(INT32_MAX, 0);
    //     for (int x = 0; x < (n * 2) - 1; x ++){
    //         if (differences[x] < min_dif.first){
    //             min_dif.first = differences[x]
    //         } 
    //     }
    // }

    // cout << min_instability;

}