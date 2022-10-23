#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        int count = 0;
        queue<TreeNode *> que;
        if (root != nullptr)
        {
            count++;
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *Node = que.front();
                que.pop();
                if (Node->left)
                {
                    que.push(Node->left);
                    count++;
                }
                if (Node->right)
                {
                    que.push(Node->right);
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *b = new TreeNode(2, d, e);
    TreeNode *c = new TreeNode(3, f, nullptr);
    TreeNode *root = new TreeNode(1, b, c);
    Solution solution;
    cout << solution.countNodes(root) << endl;
}