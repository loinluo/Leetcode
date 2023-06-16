#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     int fib(int n) {
//         if (n <= 1) {
//             return n;
//         }
//         return fib(n - 1) + fib(n - 2);
//     }
// };

int main() {
    int n;
    cin >> n;
    Solution solution;
    cout << solution.fib(n) << endl; 
}