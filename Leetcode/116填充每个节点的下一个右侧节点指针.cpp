#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        if (root != nullptr)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                node->next = (i == size - 1) ? nullptr : que.front();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};

int main()
{
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    Node *b = new Node(2, d, e, nullptr);
    Node *c = new Node(3, f, g, nullptr);
    Node *root = new Node(1, b, c, nullptr);
    Solution solution;
    Node *node = solution.connect(root);
    queue<Node *> que;
    que.push(node);
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = que.front();
            que.pop();
            que.push(node->left);
            que.push(node->right);
            if (i == 0)
            {
                if (node->next)
                {
                    cout << node->val << ' ' << node->next->val << ' ';
                }
                else
                {
                    cout << node->val << ' ' << '#' << ' ';
                }
            }
            else if (node->next)
            {
                cout << node->next->val << ' ';
            }
            else
            {
                cout << '#' << ' ';
            }
        }
    }
}
