#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> number = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string path;
    vector<string> result;
    void backtracking(string digits, int index)
    {
        if (path.size() == digits.size())
        {
            result.push_back(path);
            return;
        }
        for (char i : number[digits[index] - '0' - 2])
        {
            path.push_back(i);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};

int main()
{
    string digits = "";
    Solution solution;
    vector<string> result;
    result = solution.letterCombinations(digits);
    for (string i : result)
    {
        cout << i << ' ';
    }
}