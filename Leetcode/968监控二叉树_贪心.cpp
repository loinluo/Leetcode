#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
private:
    int result;
    int traversal(TreeNode* cur) {
        // 0: 未被监控，且无相机
        // 1: 未被监控，但有相机
        // 2: 已被监控
        if (cur == nullptr) {
            return 2;
        } // 终止条件
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if (left == 2 && right == 2) {
            return 0;
        }
        else if (left == 0 || right == 0) {
            result ++;
            return 1;
        }
        else {
            return 2;
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0) { // 根节点未被监控，且无相机
            result++;
        }
        return result;
    }
};

vector<string> stringToVector(string s) {
    vector<string> result;
    string element;
    for (char c : s) {
        if (c == '[' || c == ' ') {
            continue;
        }
        else if (c == ',' || c == ']') {
            result.push_back(element);
            element = "";
        }
        else {
            element.push_back(c);
        }

    }

    return result;
}

TreeNode* newNode (string s) {
    if (s == "0") {
        TreeNode* node = new TreeNode();
        return node;
    }
    else {
        return nullptr;
    }
}

TreeNode* vectorToTree (vector<string> &vec) {
    vector<TreeNode*> nodes;
    for (string s : vec) {
        nodes.push_back(newNode(s));
    }

    int i = 0;
    int j = 1;
    while (j < nodes.size()) {
        if (nodes[i] != nullptr) {
            nodes[i]->left = nodes[j];
            nodes[i]->right = nodes[j+1];
            j += 2;
        }
        i++;
    }

    return nodes[0];
}

void order(TreeNode *cur, vector<vector<string>> &result, int depth) {
    if (cur == nullptr) {
        return;
    }

    if (result.size() == depth) {
        result.push_back(vector<string>());
    } // 初始化result[depth]

    result[depth].push_back(to_string(cur->val));
    order(cur->left, result, depth + 1);
    order(cur->right, result, depth + 1);
}

vector<vector<string>> levelOrder(TreeNode *root) {
    vector<vector<string>> result;
    int depth = 0;
    order(root, result, depth);
    return result;
}

void levelOrderPrint(TreeNode *root) {
    vector<vector<string>> result = levelOrder(root);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}


int main() {
    string input;
    vector<vector<string>> arr;
    while (getline(cin, input)) {
        if (input.size() > 0) {
            arr.push_back(stringToVector(input));
        }
    }

    Solution solution;
    TreeNode* node = vectorToTree(arr[0]);
    cout << solution.minCameraCover(node) << endl;

}