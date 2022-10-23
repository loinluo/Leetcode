#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > target && (nums[i] >= 0 || target >= 0))
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] > target && (nums[i] + nums[j] >= 0 || target >= 0))
                {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[i] + nums[j] < target - (nums[left] + nums[right]))
                    {
                        ++left;
                    }
                    else if (nums[i] + nums[j] > target - (nums[left] + nums[right]))
                    {
                        --right;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            --right;
                        }
                        ++left;
                        --right;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {2, 2, 2, 2, 2};
    int target = 8;
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}