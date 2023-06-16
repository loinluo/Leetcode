#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum < abs(target) || (sum + target) % 2 == 1) {
            return 0;
        }

        int target_new = (sum + target) / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target_new + 1));
        // 从[0, i]中选物品装满容量j有dp[i][j]中方法
        for (int j = 0; j <= target_new; j++) {
            dp[0][j] = 0;
        }
        dp[0][0] = 1;
        if (nums.size() <= 1) {
            return dp[0][0];
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= target_new; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][target_new];

    }    
};

int main() {
    string input;
    vector<vector<int>> arr;
    while (getline(cin, input)) {
        if (input.size() > 0) {
            int num;
            vector<int> temp;
            stringstream stringin(input);
            while (stringin >> num) {
                temp.push_back(num);
            }
            arr.push_back(temp);
        }
    }
    vector<int> nums = arr[0];
    int target = arr[1][0];
    Solution solution;
    cout << solution.findTargetSumWays(nums, target);
}