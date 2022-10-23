#include <iostream>
#include <vector>

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
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(target, sum, i, candidates);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(target, 0, 0, candidates);
        return result;
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution solution;
    vector<vector<int>> result;
    result = solution.combinationSum(candidates, target);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}