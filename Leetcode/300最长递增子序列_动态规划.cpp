#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1); //dp[i]表示前i个数，以nums[i]结尾的最长递增子序列 
        dp[0] = 1;
        int result = 1;
        if (len > 1) {
            for (int i = 1; i < len; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (nums[i] > nums[j]) { //如果nums[i]比nums[j]大，则nums[i]可以接在以nums[j]为结尾的最长子序列的后面，长度为dp[j] + 1，比较是否比现在大
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                if (dp[i] > result) {
                    result = dp[i];
                }
            }
        }
        return result;
    }
};

int main() {
    string input;
    vector<int> nums;
    getline(cin, input);
    if (input.size() > 0) {
        int num;
        stringstream stringin(input);
        while (stringin >> num) {
            nums.push_back(num);
        }
    }
    Solution solution;
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}