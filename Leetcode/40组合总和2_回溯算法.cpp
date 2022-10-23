#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int target, int sum, int startIndex, vector<int> &candidates)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        if (sum > target)
        {
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++)
        {
            if (i > startIndex && candidates[i] == candidates[i - 1]) // 去除重复的情况
            {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(target, sum, i + 1, candidates);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(target, 0, 0, candidates);
        return result;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution solution;
    vector<vector<int>> result;
    result = solution.combinationSum2(candidates, target);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}