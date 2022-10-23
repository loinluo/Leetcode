#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) // 从前面的开始都不行 至少需要从i+1开始
            {
                curSum = 0;
                start = i + 1;
            }
        }
        if (totalSum < 0)
        {
            return -1;
        }
        return start;
    }
    /*{
        int left = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            if (gas[i] < cost[i])
                continue;
            int flag = i;
            for (int j = i; j < i + gas.size(); j++)
            {
                int index;
                if (j >= gas.size())
                    index = j - gas.size();
                else
                    index = j;
                left += gas[index];
                left -= cost[index];
                if (left < 0)
                {
                    flag = -1;
                }
            }
            if (flag != -1)
                return flag;
        }
        return -1;
    }*/
};

int main()
{
    string input;
    vector<vector<int>> arr;
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
            arr.push_back(a);
        }
    }
    vector<int> gas = arr[0];
    vector<int> cost = arr[1];
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost) << endl;
    return 0;
}