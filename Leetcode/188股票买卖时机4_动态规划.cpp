#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution{
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2 * k + 1));
        for (int i = 1; i < 2 * k; i+=2) {
            dp[0][i] = -prices[0]; //在第一天按照流程，不做操作为0，买入为负的价格，再卖出为零，再买入为新的负的价格
        }
        if (len > 1) {
            for (int i = 1; i < len; ++i) {
                dp[i][0] = 0; // 不做任何操作
                for (int j = 1; j <= k; ++j) {
                    dp[i][2 * j - 1] = max(dp[i - 1][2 * j - 1], dp[i - 1][2 * j - 2] - prices[i]); //第i+1天第j次买入状态的最大值，由前i天的状态推出，前i天的最大值和当天在前一天的前一个状态重新执行买入操作进行比较
                    dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] + prices[i]); //第i+1天第j次卖出状态的最大值
                }
            }
        }
        return dp[len - 1][2 * k];
    }
};

int main() {
    string input;
    vector<vector<int>> arr;
    while (getline(cin, input)) {
        if (input.size() > 0) {
            int num;
            vector<int> row;
            stringstream stringin(input);
            while (stringin >> num) {
                row.push_back(num);
            }
            arr.push_back(row);
        }
    }
    int k = arr[0][0];
    vector<int> prices = arr[1];
    Solution solution;
    cout << solution.maxProfit(k, prices) << endl;

}