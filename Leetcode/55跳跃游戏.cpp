#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        if (nums.size() == 1)
        {
            return true;
        }
        for (int i = 0; i <= cover; i++)
        {
            cover = max(nums[i] + i, cover);
            if (cover >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    string input;
    vector<int> nums;
    getline(cin, input);
    if (input.size() > 0)
    {
        stringstream stringin(input);
        int num;
        while (stringin >> num)
        {
            nums.push_back(num);
        }
    }
    Solution solution;
    cout << solution.canJump(nums) << endl;
}