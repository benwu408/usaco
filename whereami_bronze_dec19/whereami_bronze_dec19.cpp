#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    // int n;
    // cin >> n;

    // vector<int> mailboxes;
    // unordered_set<int> colors;
    // int max_common = 0;

    // for (int i = 0; i < n; i ++){
    //     char mailbox;
    //     cin >> mailbox;
    //     colors.insert(mailbox);
    //     mailboxes.push_back(mailbox);
    // }
    // int max = 0;
    // for (auto color : colors){
    //     vector<int> mailbox_indexes;
    //     vector<int>::iterator it;
    //     it = find(mailboxes.begin(), mailboxes.end(), color);
    //     while (it != mailboxes.end()){
    //         mailbox_indexes.push_back(*it);
    //         it = find(it + 1, mailboxes.end(), color);
    //     }
        
    //     unordered_set<vector<int> > prev_paths = {{mailboxes[mailbox_indexes[0]]}};
    //     for (int i = 0; i < n; i ++){
    //         unordered_set<vector<int> > paths;
    //         for (auto it : mailbox_indexes){
    //             if (it + i < mailboxes.size()){
    //                 paths.insert(vector<int> (mailboxes.begin() + it, mailboxes.begin() + it + i + 1));
    //             }
    //             else paths.insert(vector<int> (mailboxes.begin() + it, mailboxes.end()));
    //             if (paths.size() < mailbox_indexes.size()) prev_paths = paths;
    //             else break;
    //         }
    //     }
        
    //     for (auto it : prev_paths){
    //         if (it.size() > max) max = it.size();
    //     }
    // }
    // cout << max;
    int n;
    cin >> n;

    vector<char> mailboxes;
    unordered_set<vector<char> > sequences;

    for (int i = 0; i < n; i ++){
        char box;
        cin >> box;
        mailboxes.push_back(box);
    }
}