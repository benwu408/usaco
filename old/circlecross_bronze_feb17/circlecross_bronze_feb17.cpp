#include <iostream>
#include <set>
using namespace std;

int main() {
    string path;
    cin >> path;

    set<pair<char, char> > crosses;
    set<char> old;

    for (int i = 0; i < 52; i ++){
        bool cow = true;
        for (auto it : old){
            if (it == path[i]){
                
                cow = false;
                break;
            }
        }
        if (cow){
            old.insert(path[i]);
            for (int n = i + 1; n < 52; n ++){
                
                if (path[n] == path[i]){
                    break;
                    


                bool add = true;
                set<pair<char, char> > new_crosses;
                for (auto it : crosses){
                    if (it.first == path[i] && it.second == path[n]){
                        add = false;
                    }
                    else if (it.first == path[n] && it.second == path[i]){
                        add = false;
                        new_crosses.insert(it);
                    }
                    else{
                        new_crosses.insert(it);
                    }
                }
                if (add)
                new_crosses.insert(make_pair(path[i], path[n]));
                crosses = new_crosses;
                
            }
        }
        
    }

    
    cout << crosses.size() << endl;
}