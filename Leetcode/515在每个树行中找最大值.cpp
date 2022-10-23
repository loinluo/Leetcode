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
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<int> result;
        if (root != nullptr)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            int max = que.front()->val;
            for (int i = 0; i < size; i++)
            {
                TreeNode *Node = que.front();
                que.pop();
                if (Node->val > max)
                {
                    max = Node->val;
                }
                if (i == size - 1)
                {
                    result.push_back(max);
                }
                if (Node->left)
                {
                    que.push(Node->left);
                }
                if (Node->right)
                {
                    que.push(Node->right);
                }
            }
        }
        return result;
    }
};

int main()
{
    TreeNode *d = new TreeNode(5);
    TreeNode *e = new TreeNode(3);
    TreeNode *f = new TreeNode(9);
    TreeNode *b = new TreeNode(3, d, e);
    TreeNode *c = new TreeNode(2, nullptr, f);
    TreeNode *root = new TreeNode(1, b, c);
    Solution solution;
    vector<int> result = solution.largestValues(root);
    for (int i : result)
    {
        cout << i << ' ';
    }
}