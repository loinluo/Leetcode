#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(4)); // 0: 第一次买入，1：第一次卖出， 2：第二次买入，3：第二次卖出
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        if (len > 1) {
            for (int i = 1; i < len; ++i) {
                dp[i][0] = max(dp[i - 1][0], -prices[i]);
                dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
                dp[i][2] = max(dp[i - 1][2], -prices[i] + dp[i - 1][1]);
                dp[i][3] = max(dp[i - 1][3], prices[i] + dp[i - 1][2]);
            } // 每一步都是选择最大收益，选择1：保持状态， 选择2：从上一步的前一个状态出发，在这一步执行操作
        }


        return dp[len - 1][3];
    }
};

int main() {
    string input;
    vector<int> prices;
    getline(cin, input);
    if (input.size() > 0) {
        int num;
        stringstream stringin(input);
        while (stringin >> num) {
            prices.push_back(num);
        }
    }
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}