#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2));// 0：不持有股票（保持或卖出） 1：持有股票（保持或买入）
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        if (len > 1) {
            for (int i = 1; i < len; ++i) {
                dp[i][0] = max(dp[i - 1][0], prices[i] - fee + dp[i - 1][1]);
                dp[i][1] = max(dp[i - 1][1], -prices[i] + dp[i - 1][0]);
            }
        }
        return dp[len - 1][0];
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
    vector<int> prices = arr[0];
    int fee = arr[1][0];
    Solution solution;
    cout << solution.maxProfit(prices, fee) << endl; 
    return 0;
}