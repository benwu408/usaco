#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int min_instability = 0;

    vector <int> people;
    for (int i = 0; i < n * 2; i ++){
        int person;
        cin >> person;
        people.push_back(person);
    }
    sort(people.begin(), people.end());


    for (int i = 0; i < n - 1; i ++){
        pair<int, int> min_dif = make_pair(INT32_MAX, 0);
        cout << people.size();
        for (auto it : people) {
            cout << it << endl;
        }
        for (int x = 0; x < people.size() - 1; x ++){
            if (people[x + 1] - people[x] < min_dif.first){
                min_dif = make_pair(people[x + 1] - people[x], x);
            }
        }
        min_instability += min_dif.first;
        people.erase(people.begin() + min_dif.second, people.begin() + min_dif.second + 2);
        sort(people.begin(), people.end());
    }
    // cout << "differences" << endl;
    // for (auto it : differences){
    //     cout << it.first << " " << it.second << endl;
    // }

    // cout << "people" << endl;
    // for (auto it : people){
    //     cout << it << endl;
    // }
    // int count = 0;
    // for (auto it : differences){1
    //     cout << count << endl;
    //     cout << it.first << " " << it.second << endl;
    //     if (count < n - 1) {
    //         if (people[it.second] > 0 && people[it.second + 1] > 0){
    //             min_instability += it.first;
    //             people[it.second] = 0;
    //             people[it.second + 1] = 0;
    //             count ++;
    //         }
    //     }
    // }
    cout << min_instability << endl;

}