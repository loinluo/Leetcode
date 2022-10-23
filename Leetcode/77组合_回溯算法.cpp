#include <iostream>
#include <vector>

using namespace std;

/*给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。*/

class Solution
{
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {                           // 终止条件  直到k个数的集合放满
            result.push_back(path); // 存放结果  将这个集合放入结果中
            return;
        }
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);         // 处理节点   k个数的集合放入第一个元素
            backtracking(n, k, i + 1); // 递归  将这个集合填满k个元素
            path.pop_back();           // 回溯，撤销处理的节点 相当于没有改变path
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return result;
    }
};

int main()
{
    int n = 4, k = 3;
    Solution solution;
    vector<vector<int>> result;
    result = solution.combine(n, k);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}