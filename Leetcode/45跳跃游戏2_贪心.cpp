#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int curCover = 0;
        int count = 0;
        int nextCover = 0;
        for (int i = 0; i < nums.size() - 1; i++) // 在i = nums.size()的时候就不用再加1了，这个1之前就加过了
        {
            nextCover = max(nums[i] + i, nextCover);
            if (i == curCover)
            {
                curCover = nextCover;
                count++;
            }
        }
        return count;
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
    cout << solution.jump(nums) << endl;
    return 0;
}