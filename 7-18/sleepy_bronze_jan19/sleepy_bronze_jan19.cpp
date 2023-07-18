#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    bool inOrder = true;
    int idx = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i - 1] > nums[i]) {
            idx = i;
            break;
        }
    }

    cout << idx << endl;
}