#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
            
        }
        if (dp[target] == target) {
            return true;
        }
        return false;
    }
};

vector<int> stringTo1DVector(string input) {
    // remove the brackets
    input = input.substr(1, input.size() - 2);
    stringstream stringin(input);
    string temp;
    vector<int> result;
    while (getline(stringin, temp, ',')) {
        if (temp.size() > 0) {
            int num = stoi(temp);
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    string input;
    getline(cin, input);
    vector<int> nums;
    // int num;
    // stringstream stringin(input);
    // while (stringin >> num) {
    //     nums.push_back(num);
    // }
    Solution solution;
    cout << solution.canPartition(nums) << endl;
}