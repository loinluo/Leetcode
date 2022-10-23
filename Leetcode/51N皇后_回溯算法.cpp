#include <iostream>
#include <vector>

using namespace std;

// 首先画树图，观察什么是层，每层循环的是什么
class Solution
{
private:
    vector<vector<string>> result;
    bool isValid(int row, int col, vector<string> &chessboard, int n)
    {
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q')
            { // 在同一列的情况
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        { // 在左上角的情况
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        { // 在右上角的情况
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(int n, int row, vector<string> &chessboard)
    { // 层数为棋盘的第几行
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q'; // 如果这个位置不会被其他皇后攻击，放置新皇后
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // 回溯， Q恢复为普通棋盘
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chessboard(n, string(n, '.')); // 初始化棋盘
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main()
{
    int n = 4;
    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(n);
    for (auto i : result)
    {
        for (string j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}