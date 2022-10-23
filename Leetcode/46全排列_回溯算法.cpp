#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    unordered_set<int> uset;
    void backtracking(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (uset.find(nums[i]) == uset.end())
            {
                path.push_back(nums[i]);
                uset.insert(nums[i]);
                backtracking(nums);
                path.pop_back();
                uset.erase(nums[i]);
            }
            else
            {
                continue;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        backtracking(nums);
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    Solution solution;
    result = solution.permute(nums);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}