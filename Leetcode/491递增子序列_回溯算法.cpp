#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, int startIndex)
    {
        if (path.size() >= 2)
        {

            result.push_back(path);
        }
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((path.empty() || nums[i] >= path.back()) && uset.find(nums[i]) == uset.end())
            {
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
            else
            {
                continue;
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtracking(nums, 0);
        return result;
    }
};

int main()
{
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> result;
    Solution solution;
    result = solution.findSubsequences(nums);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}