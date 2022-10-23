#include <iostream>
#include <vector>
#include <algorithm>
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
            if (i != 0 && nums[i] == nums[i - 1] && uset.find(i - 1) == uset.end()) // 注意第三个条件
            {
                continue;
            }
            if (uset.find(i) == uset.end())
            {
                uset.insert(i);
                path.push_back(nums[i]);
                backtracking(nums);
                uset.erase(i);
                path.pop_back();
            }
            else
            {
                continue;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtracking(nums);
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result;
    Solution solution;
    result = solution.permuteUnique(nums);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}