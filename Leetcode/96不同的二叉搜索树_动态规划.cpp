#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int numTrees (int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];

    }
};

int main() {
    int n;
    cin >> n;
    Solution solution;
    cout << solution.numTrees(n) << endl;
}