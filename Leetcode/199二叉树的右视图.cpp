#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)
        {
            que.push(root);
        }
        vector<int> result;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();                       //将前面的元素都删掉
                if (i == (size - 1))             //这一层的最后一个元素
                    result.push_back(node->val); // 将每一层的最后元素放入result数组中
                if (node->left)
                    que.push(node->left); //先放左边的
                if (node->right)
                    que.push(node->right); //后放右边的
            }
        }

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
    vector<int> result = solution.rightSideView(root);
    for (auto i : result)
    {
        cout << i << ' ';
    }
}