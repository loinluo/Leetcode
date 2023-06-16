#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        vector<int> counts = {0, 0};
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                counts[0] += 1;
            }
            else if (bills[i] == 10)
            {
                if (counts[0] >= 1)
                {
                    counts[0] -= 1;
                    counts[1] += 1;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (counts[0] >= 1 && counts[1] >= 1)
                {
                    counts[0] -= 1;
                    counts[1] -= 1;
                }
                else if (counts[0] >= 3)
                {
                    counts[0] -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
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
    vector<int> bills = arr[0];
    Solution solution;
    cout << solution.lemonadeChange(bills) << endl;
    return 0;
}