#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2};
    Solution solution;
    vector<vector<int>> result;
    result = solution.subsetsWithDup(nums);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}