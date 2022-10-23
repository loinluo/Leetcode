#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        for (fast; fast < nums.size(); fast++)
        {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
            
        return slow;
    }
};

//int main() {
//    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
//    int val = 2;
//    Solution solution;
//    int length = solution.removeElement(nums, val);
//    cout << length << endl;
//    for (int i = 0; i < length; i++) {
//        cout << nums[i] << '\t';
//    }
//}