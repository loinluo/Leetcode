#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//只计算正收益
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};

/*class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        int flag = -1;
        if (prices.size() == 1)
        {
            return result;
        }
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i] && flag == -1)
            {
                result += flag * prices[i];
                flag *= -1;
            }
            if (prices[i + 1] < prices[i] && flag == 1)
            {
                result += prices[i];
                flag *= -1;
            }
        }
        if (flag == 1)
        {
            result += prices[prices.size() - 1];
        }
        return result;
    }
};*/

int main()
{
    vector<int> prices;
    string input;
    getline(cin, input);
    if (input.size() > 0)
    {
        stringstream stringin(input);
        int num;
        while (stringin >> num)
        {
            prices.push_back(num);
        }
    }
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
}