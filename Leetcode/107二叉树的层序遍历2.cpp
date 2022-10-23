#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}                                  // 构造方式1：0接两个空指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}                             //构造方式2：x接两个空指针
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} //构造方式3：x接左右指针的值
};

class Solution
{
public:
    void Order(TreeNode *cur, vector<vector<int>> &result, int depth)
    {
        if (cur == nullptr)
        {
            return;
        }
        if (result.size() == depth)
        {
            result.push_back(vector<int>());
        }
        result[depth].push_back(cur->val);
        Order(cur->left, result, depth + 1);
        Order(cur->right, result, depth + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        Order(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    TreeNode *c = new TreeNode(20, d, e);
    TreeNode *b = new TreeNode(9);
    TreeNode *root = new TreeNode(3, b, c);
    Solution solution;
    vector<vector<int>> result = solution.levelOrderBottom(root);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}