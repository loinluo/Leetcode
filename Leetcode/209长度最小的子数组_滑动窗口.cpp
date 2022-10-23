#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int start = 0, end = 0;
        int length = 0;
        for (end; end < nums.size(); end++) {
            sum += nums[end];
            while (sum >= target) {
                length = end - start + 1;
                result = length < result ? length : result;
                sum -= nums[start++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }    
};

//int main() {
//    int a[] = { 2,3,1,2,4,3 };
//    vector<int> nums(a, a + sizeof(a) / sizeof(int));
//    int target = 7;
//    Solution solution;
//    cout << solution.minSubArrayLen(target, nums) << endl;
//}