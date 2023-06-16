#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
    vector<int> counts(string str) {
        int count_0 = 0, count_1 = 0;
        for (char c : str) {
            if (c == '0') {
                ++count_0;
            }
            else {
                ++count_1;
            }
        }
        vector<int> result = {count_0, count_1};
        return result;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp((m + 1), vector<int>((n + 1), 0));
        for (string& s : strs) {
            vector<int> count = counts(s);
            
            for (int i = m; i >= count[0]; --i) {
                for (int j = n; j >= count[1]; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - count[0]][j - count[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<string> strs;
    string input;
    string element;
    getline(cin, input);
    stringstream stringin(input);
    while (stringin >> element) {
        strs.push_back(element);
    }
    int m, n;
    cin >> m >> n;
    Solution solution;
    cout << solution.findMaxForm(strs, m, n) << endl;
}