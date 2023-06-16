#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i : stones) {
            sum += i;
        }
        int target = sum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
        for (int j = stones[0]; j <= target; j++) {
            dp[0][j] = stones[0];
        }   
        for (int i = 1; i < stones.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (j < stones[i]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
                }
            }
        }
        return sum - dp[stones.size() - 1][target] - dp[stones.size() - 1][target];
    }
};

vector<int> stringTo1DVector(string input) {
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
    vector<int> nums;
    getline(cin, input);
    nums = stringTo1DVector(input);
    Solution solution;
    cout << solution.lastStoneWeightII(nums) << endl;
}