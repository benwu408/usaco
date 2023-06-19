#include <iostream>
#include <tuple>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, tuple<string, int, int> > speed;
    bool found_none = false;
    int first_none = 0;
    for (int i = 1; i <= n; i ++){
        string type;
        int a;
        int b;

        cin >> type >> a >> b;

        int num = i;

        speed[num] = make_tuple(type, a, b);

        
        if (type == "none" && found_none == false){
            found_none = true;
            first_none = i;
        }
    }
    int last_none = 0;
    for (int i = n; i >= 1; i --){
        if (get<0>(speed[i]) == "none"){
            last_none = i;
            break;
        }

    }

    pair<int, int> first_range(get<1>(speed[last_none]), get<2>(speed[last_none]));
    std::cout << "going up to first" << endl;
    std::cout << last_none << " " << first_range.first << " " << first_range.second << endl;

    for (int i = last_none - 1; i >= 1; i --){

        if (get<0>(speed[i]) == "on"){
            first_range.first -= get<2>(speed[i]);
            first_range.second -= get<1>(speed[i]);
            if (first_range.first < 0){
                first_range.first = 0;
            }
            if (first_range.second < 0){
                first_range.second = 0;
            }

        }
        else if (get<0>(speed[i]) == "off"){
            first_range.first += get<1>(speed[i]);
            first_range.second += get<2>(speed[i]);
        }
        else{
            if (get<1>(speed[i]) > first_range.first){
                first_range.first = get<1>(speed[i]);
            }
            if (get<2>(speed[i]) < first_range.second){
                first_range.second = get<2>(speed[i]);
            }
            
        }
        std::cout << i << " " << first_range.first << " " << first_range.second << endl;
    }
    std::cout << "going down to last";
    pair<int, int> last_range(get<1>(speed[first_none]), get<2>(speed[first_none]));
    std::cout << first_none << " " << last_range.first << " " << last_range.second << " " << endl;
    for (int i = first_none + 1; i <= n; i ++){
        if (get<0>(speed[i]) == "on"){
            last_range.first += get<1>(speed[i]);
            last_range.second += get<2>(speed[i]);
        }
        else if (get<0>(speed[i]) == "off"){
            last_range.first -= get<2>(speed[i]);
            last_range.second -= get<1>(speed[i]);
            if (last_range.first < 0){
                last_range.first = 0;
            }
            if (last_range.second < 0){
                last_range.second = 0;
            }
        }
        else{
            if (get<1>(speed[i]) > last_range.first){
                last_range.first = get<1>(speed[i]);
            }
            if (get<2>(speed[i]) < last_range.second){
                last_range.second = get<2>(speed[i]);
            }
        }
        std::cout << i << " " << last_range.first << " " << last_range.second << endl;
    }

    std::cout << first_range.first << " " << first_range.second << endl;
    std::cout << last_range.first << " " << last_range.second << endl;

}