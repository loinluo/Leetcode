#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void order(Node *cur, vector<vector<int>> &result, int depth)
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
        for (auto i : cur->children)
        {
            order(i, result, depth + 1);
        }
    }
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;
        order(root, result, 0);
        return result;
    }
};

int main()
{
    Node *e = new Node(5);
    Node *f = new Node(6);
    vector<Node *> children2 = {e, f};
    Node *b = new Node(3, children2);
    Node *c = new Node(2);
    Node *d = new Node(4);
    vector<Node *> children1 = {b, c, d};
    Node *root = new Node(1, children1);
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);
    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}