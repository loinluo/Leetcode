#include <iostream>
#include <vector>

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
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

int main()
{
    TreeNode *c = new TreeNode(3);
    TreeNode *b = new TreeNode(2, c, nullptr);
    TreeNode *root = new TreeNode(1, nullptr, b);
    Solution solution;
    vector<int> result = solution.postorderTraversal(root);
    for (int i : result)
    {
        cout << i << ' ';
    }
}