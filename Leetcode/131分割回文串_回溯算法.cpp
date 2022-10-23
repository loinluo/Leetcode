#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> path;
    vector<vector<string>> result;
    void backtracking(string s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalidrome(s, startIndex, i)) //如果s的[startIndex, i]的子串为回文
            {
                string str = s.substr(startIndex, i - startIndex + 1); //截取起点startIndex，终点i（长度i - startIndex + 1）的字符串
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1); //找到一个回文子串后，以i+1为起点开始找回文子串
            path.pop_back();        //回溯
        }
    }
    bool isPalidrome(string s, int startIndex, int i)
    {
        int left = startIndex;
        int right = i;
        for (left, right; left <= right; left++, right--)
        {
            if (s[left] != s[right])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return result;
    }
};

int main()
{
    string s = "aab";
    Solution solution;
    vector<vector<string>> result = solution.partition(s);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}