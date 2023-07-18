#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<pair<int, int> > cowsxy;
vector<pair<int, int> > cowsyx;

int find_best(vector<int> current_limits, int num_removed, vector<pair<int, int> > listxy, vector<pair<int, int> > listyx){
    // cout << "list x y " << endl;
    // for (auto it : listxy){
    //     cout << it.first << " " << it.second << endl;
    // }
    // cout << endl;
    // cout << "list y x " << endl;
    // for (auto it : listyx) { 
    //     cout << it.first << " " << it.second << endl;
    // }
    // cout << endl;
    // cout << "limits" << endl;
    // for (auto it : current_limits) cout << it << endl;
    // cout << endl;
    if (num_removed == 3){
        return (current_limits[0] - current_limits[2]) * (current_limits[1] - current_limits[3]);
    }
    
    int lowest = INT32_MAX;
    
    set<pair<int, int> > edges;
    edges.insert(listxy.front());
    edges.insert(listxy.back());
    edges.insert(make_pair(listyx.front().second, listyx.front().first));
    edges.insert(make_pair(listyx.back().second, listyx.back().first));

    for (auto edge : edges){
        vector<pair<int, int> > newxy = listxy;
        vector<pair<int, int> > newyx = listyx;
        newxy.erase(find(newxy.begin(), newxy.end(), edge));
        newyx.erase(find(newyx.begin(), newyx.end(), make_pair(edge.second, edge.first)));
        vector<int> next = current_limits;
        next[0] = newyx.back().first;
        next[1] = newxy.back().first;
        next[2] = newyx.front().first;
        next[3] = newxy.front().first;
        lowest = min(lowest, find_best(next, num_removed + 1, newxy, newyx));
    }

    return lowest;
    // vector<int> next1 = current_limits;
    // vector<pair<int, int> > listxy1 = listxy;
    // vector<pair<int, int> > listyx1 = listyx;
    
    // listxy1.erase(find(listxy1.begin(), listxy1.end(), make_pair(listyx1.back().second, listyx1.back().first)));
    // listyx1.pop_back();
    // next1[0] = listyx1.back().first;
    // next1[1] = listxy1.back().first;
    // next1[2] = listyx.front().second;
    // next1[3] = listxy1.front().second;
    // lowest = min(lowest, find_best(next1, num_removed + 1, listxy1, listyx1));
    // vector<int> next2 = current_limits;
    // vector<pair<int, int> > listxy2 = listxy;
    // vector<pair<int, int> > listyx2 = listyx;
    
    // listyx2.erase(find(listyx2.begin(), listyx2.end(), make_pair(listxy2.back().second, listxy2.back().first)));
    // listxy2.pop_back();
    // next2[0] = listyx1.back().first;
    // next2[1] = listxy1.back().first;
    // next2[2] = listyx.front().second;
    // next2[3] = listxy1.front().second;
    // lowest = min(lowest, find_best(next2, num_removed + 1, listxy2, listyx2));
    // vector<int> next3 = current_limits;
    // vector<pair<int, int> > listxy3 = listxy;
    // vector<pair<int, int> > listyx3 = listyx;
    
    // listxy3.erase(find(listxy3.begin(), listxy3.end(), make_pair(listyx3.front().second, listyx3.front().first)));
    // listyx3.erase(listyx3.begin());
    // next3[0] = listyx1.back().first;
    // next3[1] = listxy1.back().first;
    // next3[2] = listyx.front().second;
    // next3[3] = listxy1.front().second;
    // lowest = min(lowest, find_best(next3, num_removed + 1, listxy3, listyx3));
    // vector<int> next4 = current_limits;
    // vector<pair<int, int> > listxy4 = listxy;
    // vector<pair<int, int> > listyx4 = listyx;
    
    // listyx4.erase(find(listyx4.begin(), listyx4.end(), make_pair(listxy4.front().second, listxy4.front().first)));
    // listxy4.erase(listxy4.begin());
    // next4[0] = listyx1.back().first;
    // next4[1] = listxy1.back().first;
    // next4[2] = listyx.front().second;
    // next4[3] = listxy1.front().second;
    // lowest = min(lowest, find_best(next4, num_removed + 1, listxy4, listyx4));
    
    // cout << "lowest" << " " << lowest << endl;
    // return lowest;
}
int main(){
    int n;
    cin >> n;

    

    for(int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;

        cowsxy.push_back(make_pair(x, y));
        cowsyx.push_back(make_pair(y, x));
    }

    sort(cowsxy.begin(), cowsxy.end());
    sort(cowsyx.begin(), cowsyx.end());

    
    vector<int> current = {cowsyx.back().first, cowsxy.back().first, cowsyx.front().first, cowsxy.front().first};
    // cowsxy.erase(find(cowsxy.begin(), cowsxy.end(), make_pair(cowsyx.back().second, cowsyx.back().first)));
    // cowsyx.pop_back();
    // cowsyx.erase(find(cowsyx.begin(), cowsyx.end(), make_pair(cowsxy.back().second, cowsxy.back().first)));
    // cowsxy.pop_back();
    // cowsxy.erase(find(cowsxy.begin(), cowsxy.end(), make_pair(cowsyx.front().second, cowsyx.front().first)));
    // cowsyx.erase(cowsyx.begin());
    // cowsyx.erase(find(cowsyx.begin(), cowsyx.end(), make_pair(cowsxy.front().second, cowsxy.front().first)));
    // cowsxy.erase(cowsxy.begin());
    // for (auto it : current){
    //     cout << it << endl;
    // }
    // for (auto it : cowsxy){
    //     cout << it.first << " " << it.second << endl;
    // }
    // for (auto it : cowsyx) { 
    //     cout << it.first << " " << it.second << endl;
    // }
    // cout << endl;
    cout << find_best(current, 0, cowsxy, cowsyx) << endl;
}