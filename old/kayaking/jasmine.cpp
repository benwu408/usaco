#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>* nums, int index, int remaining) {
    if (index == (*nums).size()) return 0;

    vector<int> options;
    if (remaining) {
        options.push_back(helper(nums, index + 1, remaining - 1));
    }
    if ((*nums).end() - ((*nums).begin() + index) > remaining) {
        int difference = (*nums)[index + 1] - (*nums)[index];
        options.push_back(difference + helper(nums, index + 2, remaining));
    }

    return *min_element(options.begin(), options.end());
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < 2 * n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    cout << helper(&nums, 0, 2) << endl;
}