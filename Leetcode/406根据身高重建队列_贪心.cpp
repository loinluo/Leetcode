#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }
};

void PrintVec2D(vector<vector<int>> &res)
{
    for (auto &rowV : res)
    {
        for (auto &el : rowV)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}

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
    vector<vector<int>> people = arr;
    vector<vector<int>> res;
    Solution solution;
    res = solution.reconstructQueue(people);
    PrintVec2D(res);
    return 0;
}