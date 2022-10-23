#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        for (int i = 0; i < k; i++)
        {
            int minIndex = 0;
            for (int j = 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[minIndex])
                {
                    minIndex = j;
                }
            }
            nums[minIndex] = -nums[minIndex];
        }
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        return sum;
    }
};

int main()
{
    vector<vector<int>> arrays;
    string input;
    while (getline(cin, input))
    {
        if (input.size() > 0)
        {
            stringstream stringin(input);
            int num;
            vector<int> a;
            while (stringin >> num)
            {
                a.push_back(num);
            }
            arrays.push_back(a);
        }
    }
    vector<int> nums = arrays[0];
    int k = arrays[1][0];
    Solution solution;
    cout << solution.largestSumAfterKNegations(nums, k) << endl;
    return 0;
}
