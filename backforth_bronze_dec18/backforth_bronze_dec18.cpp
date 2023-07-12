#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

set<int> readings;

void find_readings(vector<int> barn1, vector<int> barn2, int day, int tank1, int tank2){
    if (day == 5) {
        readings.insert(tank1);
    }
    else if (day % 2 == 1){
        for (int i = 0; i < barn1.size(); i ++){
            vector<int> newbarn1 = barn1;
            vector<int> newbarn2 = barn2;
            int newtank1 = tank1 - newbarn1[i];
            int newtank2 = tank2 + newbarn1[i];
            newbarn2.push_back(newbarn1[i]);
            newbarn1.erase(newbarn1.begin() + i);
            find_readings(newbarn1, newbarn2, day + 1, newtank1, newtank2);
        }
    }
    else {
        for (int i = 0; i < barn2.size(); i ++){
            vector<int> newbarn1 = barn1;
            vector<int> newbarn2 = barn2;
            int newtank1 = tank1 + newbarn2[i];
            int newtank2 = tank2 - newbarn2[i];
            newbarn1.push_back(newbarn2[i]);
            newbarn2.erase(newbarn2.begin() + i);
            find_readings(newbarn1, newbarn2, day + 1, newtank1, newtank2);
        }
    }
}

int main() {
    vector<int> barn1;
    vector<int> barn2;
    for (int i = 0; i < 10; i ++){
        int bucket;
        cin >> bucket;
        barn1.push_back(bucket);
    }

    for (int i = 0; i < 10; i ++){
        int bucket;
        cin >> bucket;
        barn2.push_back(bucket);
    }


    find_readings(barn1, barn2, 1, 1000, 1000);

    cout << readings.size() << endl;
}