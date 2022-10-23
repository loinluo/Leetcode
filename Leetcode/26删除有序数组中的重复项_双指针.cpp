#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unsigned int fast = 0;
        unsigned int slow = 0;
        unsigned int length = nums.size();
        for (fast; fast < length; fast++)
        {
            if (fast + 1 < nums.size())
            {
                if (nums[fast + 1] != nums[fast])
                {
                    nums[slow] = nums[fast];
                    slow++;

                }
            }
            else
            {
                nums[slow] = nums[fast];
            }
            
        }
        return slow + 1;

    }
};

//int main() {
//    vector<int> nums = { 0, 1, 2, 2, 3, 3, 4, 5 };
//    Solution solution;
//    cout << solution.removeDuplicates(nums) << endl;
//}