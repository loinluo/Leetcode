#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > result)
            {
                result = sum;
            }
            // sum < 0 时重置子序列的初始位置
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return result;
    }
    // 下面这个无法通过全是负数并且第二个负数比较大的序列 -2 -1
    /*{
        int result = nums[0];
        int len = nums.size();
        if (len == 1)
        {
            return result;
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (nums[i] < 0)
                {
                    continue;
                }
                int sum = nums[i];
                int flag = 0;
                for (int j = i + 1; j < len; j++)
                {
                    flag += nums[j];
                    if (flag < 0)
                    {
                        continue;
                    }
                    else
                    {
                        sum += flag;
                        flag = 0;
                    }
                }
                if (sum > result)
                {
                    result = sum;
                }
            }
        }
        return result;
    }*/
};

int main()
{
    vector<int> nums;
    string input;
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
    int result;
    Solution solution;
    result = solution.maxSubArray(nums);
    cout << result << endl;
}