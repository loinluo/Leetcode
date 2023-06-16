#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) {
            return cost[0];
        }
        if (n == 2) {
            return min(cost[0], cost[1]);
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[n];
    }
};

int main() {
    string input;
    vector<int> cost;
    getline(cin, input);
    if (input.size() > 0) {
        stringstream stringin(input);
        int num;
        while (stringin >> num) {
            cost.push_back(num);
        }
    }
    Solution solution;
    cout << solution.minCostClimbingStairs(cost) << endl;
    return 0;
}