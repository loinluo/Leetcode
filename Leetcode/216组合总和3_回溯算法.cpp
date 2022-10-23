#include <iostream>
#include <vector>

using namespace std;

// 找出所有相加之和为 n 的 k 个数的组合 只使用数字1到9 每个数字 最多使用一次  返回 所有可能的有效组合的列表
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int k, int n, int sum, int startIndex)
    {
        if (path.size() == k)
        {
            if (sum == n)
                result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(k, n, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, 0, 1);
        return result;
    }
};

int main()
{
    vector<vector<int>> result;
    int k = 9, n = 45;
    Solution solution;
    result = solution.combinationSum3(k, n);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}