#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int min = prices[0];
    //     int maxProfit = 0;
    //     if (prices.size() > 1) {
    //         for (int i = 1; i < prices.size(); ++i) {
    //             if (prices[i] < min) {
    //                 min = prices[i];
    //             }
    //             maxProfit = prices[i] - min > maxProfit ? prices[i] - min : maxProfit;
    //         }
    //     }
    //     return maxProfit;
    // }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2)); //dp[i][0]: 第i天持有股票的最高收益 dp[i][1]: 第i天不持有股票的最高收益
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        if (prices.size() > 1) {
            for (int i = 1; i < prices.size(); ++i) {
                dp[i][0] = max(dp[i - 1][0], - prices[i]);
                dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
            }
        }
        return dp[prices.size() - 1][1];

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