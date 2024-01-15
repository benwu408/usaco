#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<pair<int, int> > cows;
vector<set<int> > connections(100000);
vector<int> nets(100000);

void search(int cow, int ntwrk, vector<int> &bounds){
    nets[cow] = ntwrk;
    bounds[0] = min(bounds[0], cows[cow].first);
    bounds[1] = max(bounds[1], cows[cow].first);
    bounds[2] = min(bounds[2], cows[cow].second);
    bounds[3] = max(bounds[3], cows[cow].second);
    // cout << bounds[0] << bounds[1] << bounds[2] << bounds [3] << endl;
    for (auto connect : connections[cow]){
        if (nets[connect] == 0) search(connect, ntwrk, bounds);
    }
}

int main() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;
        cows.push_back(make_pair(x, y));
    }
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        connections[a].insert(b);
        connections[b].insert(a);
    }
    int k = 0;
    int min_perim = INT32_MAX;
    for (int i = 0; i < n; i ++){
        if (nets[i] == 0){
            vector<int> bound = {INT32_MAX, 0, INT32_MAX, 0};
            search(i, ++k, bound);
            // cout << bound[0] << " " << bound[1] << " " << bound[2] << " " << bound[3] << endl;
            min_perim = min(min_perim, (bound[1] - bound[0]) + (bound[3] - bound[2]));
        }
    }
    cout << min_perim * 2 << endl;


    // vector<pair<int, int> > cows;
    // vector<bool> has_group(n);
    // for (int i = 0; i < n; i ++){
    //     int x, y; cin >> x >> y;
    //     cows.push_back(make_pair(x, y));
    // }

    // vector<vector<int> > group_edge;
    // int group_num = 0;
    // set<pair<set<int>, vector<int> > > groups;
    // for (int i = 0; i < m; i ++){
    //     int a, b; cin >> a >> b;
    //     a --;
    //     b --;

    //     if (has_group[a] && has_group[b]){
    //         pair<set<int>, vector<int> > * a_group;
    //         pair<set<int>, vector<int> > * b_group;
    //         for (auto group : groups){
    //             if (group.first.find(a) != group.first.end()) a_group = &group;
    //             if (group.first.find(b) != group.first.end()) b_group = &group;
    //         }
    //         if (a_group != b_group){
    //             a_group->first.insert(b_group->first.begin(), b_group->first.end());
    //             a_group->second[0] = min(a_group->second[0], b_group->second[0]);
    //             a_group->second[1] = max(a_group->second[1], b_group->second[1]);
    //             a_group->second[2] = min(a_group->second[2], b_group->second[2]);
    //             a_group->second[3] = max(a_group->second[3], b_group->second[3]);
    //             groups.erase(groups.find(*b_group));
    //         }
    //     }
    //     else if (has_group[a] || has_group[b]){
    //         int grouped, non_grouped;
    //         if (has_group[a]){
    //             grouped = a;
    //             non_grouped = b;
    //         }
    //         else{
    //             grouped = b;
    //             non_grouped = a;
    //         }
    //         for (auto group : groups){
    //             if (group.first.find(grouped) != group.first.end()){
    //                 group.first.insert(non_grouped);
    //                 group.second[0] = min(group.second[0], cows[non_grouped].first);
    //                 group.second[1] = max(group.second[1], cows[non_grouped].first);
    //                 group.second[2] = min(group.second[2], cows[non_grouped].second);
    //                 group.second[3] = max(group.second[3], cows[non_grouped].second);
    //             }
    //         }
    //         has_group[non_grouped] = true;
    //     }
    //     else {
    //         groups.insert(
    //             make_pair(
    //                 set<int> {a, b},
    //                 vector<int>{
    //                     min(cows[a].first, cows[b].first),
    //                     max(cows[a].first, cows[b].first),
    //                     min(cows[a].second, cows[b].second),
    //                     max(cows[a].second, cows[b].second)
    //                 }
    //             )
    //         );
    //         has_group[a] = true;
    //         has_group[b] = true;
    //     }
        // if (cow_group[a] != -1 && cow_group[b] != -1){
        //     if (cow_group[a] != cow_group[b]){
        //         int less = min(cow_group[a], cow_group[b]);
        //         int more = max(cow_group[a], cow_group[b]);

        //         group_edge[less][0] = min(group_edge[less][0], group_edge[more][0]);
        //         group_edge[less][1] = max(group_edge[less][1], group_edge[more][1]);
        //         group_edge[less][2] = min(group_edge[less][2], group_edge[more][2]);
        //         group_edge[less][3] = max(group_edge[less][3], group_edge[more][3]);
        //         group_edge[more] = {-1, -1, -1, -1};
        //         for (auto group : cow_group){
        //             if (group == more) group = less;
        //         }
        //     }
        // }
        // else if (cow_group[a] != -1) {
        //     cow_group[b] = cow_group[a];
        //     group_edge[cow_group[a]][0] = min(group_edge[cow_group[a]][0], cows[b].first); 
        //     group_edge[cow_group[a]][1] = max(group_edge[cow_group[a]][1], cows[b].first); 
        //     group_edge[cow_group[a]][2] = min(group_edge[cow_group[a]][2], cows[b].second); 
        //     group_edge[cow_group[a]][3] = max(group_edge[cow_group[a]][3], cows[b].second); 
        // }
        // else if (cow_group[b] != -1) {
        //     cow_group[a] = cow_group[b];
        //     group_edge[cow_group[b]][0] = min(group_edge[cow_group[b]][0], cows[a].first); 
        //     group_edge[cow_group[b]][1] = max(group_edge[cow_group[b]][1], cows[a].first); 
        //     group_edge[cow_group[b]][2] = min(group_edge[cow_group[b]][2], cows[a].second); 
        //     group_edge[cow_group[b]][3] = max(group_edge[cow_group[b]][3], cows[a].second); 
        // }
        // else{
        //     cow_group[a] = group_num;
        //     cow_group[b] = group_num;
        //     vector<int> new_edges;
        //     new_edges.push_back(min(cows[a].first, cows[b].first));
        //     new_edges.push_back(max(cows[a].first, cows[b].first));
        //     new_edges.push_back(min(cows[a].second, cows[b].second));
        //     new_edges.push_back(max(cows[a].second, cows[b].second));
        //     group_edge.push_back(new_edges);
        //     group_num ++;
        // }


}
    // int smallest = INT32_MAX;
    // for (auto group : groups){
    //     smallest = min(smallest, (group.second[1] - group.second[0]) + (group.second[3] - group.second[2]));
    // }
    // cout << smallest*2 << endl;
