#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result(2, -1);
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                int i = middle;
                while (i >= 0 && nums[i] == target) {
                    i--;
                }
                result[0] = i + 1;
                i = middle;
                while (i <= nums.size() - 1 && nums[i] == target) {
                    i++;
                }
                result[1] = i - 1;

                return result;
            }
        }
        return result;

    }
};

//int main() {
//    int a[] = { 5,7,7,8,8,10 };
//    vector<int> nums(a, a + sizeof(a) / sizeof(int));
//    int target = 7;
//    Solution solution;
//    vector<int>result = solution.searchRange(nums, target);
//    cout << result[0] << result[1] << endl;
//}