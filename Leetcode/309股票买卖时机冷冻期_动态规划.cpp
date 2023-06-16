#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(4)); // 0: 持有股票状态(今日买入或之前持有)，1：保持卖出股票状态（已度过冷冻期）， 2：今日卖出股票，3：处于冷冻期
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        if (len > 1) {
            for (int i = 1; i < len; ++i) {
                dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]); //(1)昨天持有股票 今天不操作(2)昨天已经度过了冷冻期 今天买(3)昨天是冷冻期 今天买
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]); //(1)昨天不是冷冻期且没有股票 今天不操作 (2)昨天处于冷冻期 今天不操作
                dp[i][2] = dp[i - 1][0] + prices[i]; //昨天持有股票
                dp[i][3] = dp[i - 1][2]; //昨天卖出了股票
            }
        }
        return max(dp[len - 1][1], max(dp[len - 1][2], dp[len - 1][3]));
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