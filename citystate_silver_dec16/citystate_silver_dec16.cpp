#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(){
    int n; cin >> n;
    map<string, vector<string> > state_to_cities;
    int count = 0; 
    for (int i = 0; i < n; i ++){
        string city, state; cin >> city >> state;
        if (state_to_cities.find(city.substr(0, 2)) != state_to_cities.end()){
            for (auto city1 : state_to_cities[city.substr(0, 2)]){
                if (city1.substr(0, 2) == state && state != city.substr(0, 2)) {
                    count ++;
                    // cout << city << " " << state << " -- " << city1 << " " << city.substr(0, 2) << endl;
                }
            }
        }
        if (state_to_cities.find(state) != state_to_cities.end()) state_to_cities[state].push_back(city);
        else state_to_cities[state] = vector<string> {city};
    }

    cout << count << endl;
}