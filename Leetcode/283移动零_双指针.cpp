#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        for (fast; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for (slow; slow < nums.size(); slow++)
        {
            nums[slow] = 0;
        }
    }
};

//int main() {
//    vector<int> nums = { 0, 1, 2, 2, 3, 3, 4, 5 };
//    Solution solution;
//    solution.moveZeroes(nums);
//    for (int i = 0; i < nums.size(); i++)
//    {
//        cout << nums[i] << '\t';
//    }
//}