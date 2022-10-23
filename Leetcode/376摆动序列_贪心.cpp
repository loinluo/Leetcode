#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int result = 1;
        int curDiff = 0;
        int preDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0))
            {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};

int main()
{
    int num;
    cout << "input nums size:" << endl;
    cin >> num;
    vector<int> nums(num, 0);
    cout << "input nums:" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> nums[i];
    }
    Solution solution;
    cout << solution.wiggleMaxLength(nums) << endl;
}