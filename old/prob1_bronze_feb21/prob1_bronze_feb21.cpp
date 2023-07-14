#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;

void print_map(map<string, int> map1){
    for (auto it : map1){
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    map<string, int> years {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};

    map<string, int> cows {{"Bessie", 0}};

    int n;
    cin >> n;

    for (int a = 0; a < n; a ++){
        string cow;
        bool order = false;
        string year;
        string other;
        for (int b = 0; b < 8; b ++){
            string word;
            cin >> word;
            if (b == 0) cow = word;
            if (b == 3 && word == "next") order = true;
            if (b == 4) year = word;
            if (b == 7) other = word;
        }
        int other_year = cows[other] % 12;
        // print_map(cows);
        // cout << other_year << endl;
        while(other_year < 0) other_year += 12;

        // cout << cow << " " << order << " " << year << " " << other << " " << other_year << endl;
        if (order){
            if (years[year] > other_year) cows[cow] = cows[other] + (years[year] - other_year);
            else if (years[year] == other_year) cows[cow] = cows[other] + 12;
            else cows[cow] = cows[other] + (12 - (other_year)) + years[year];
        }
        else{
            if (other_year > years[year]) cows[cow] = cows[other] - (other_year - years[year]);
            else if (other_year == years[year]) cows[cow] = cows[other] - 12;
            else cows[cow] = cows[other] - other_year - (12 - years[year]);
        }
        if (cow == "Elsie") break;
    }
    cout << abs(cows["Elsie"]) << endl;
    // print_map(cows);
}