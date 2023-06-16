#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);
        int result = 1;
        if (len > 1) {
            for (int i = 1; i < len; ++i) {
                if (nums[i] > nums[i - 1]) {
                    dp[i] = dp[i - 1] + 1;
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
    cout << solution.findLengthOfLCIS(nums) << endl;
    return 0;
}