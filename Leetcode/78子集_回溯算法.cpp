#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, int startIndex, int length)
    {
        if (path.size() == length)
        {
            result.push_back(path);
            return;
        }
        if (path.size() > length)
        {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1, length);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        for (int i = 0; i <= nums.size(); i++)
        {
            backtracking(nums, 0, i);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}