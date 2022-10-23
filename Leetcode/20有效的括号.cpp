#include<iostream>
#include<stack>

using namespace std;

/*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//将问题转化为栈问题，后进先出

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char t : s) {
            if (t == '(' || t == '[' || t == '{') {
                paren.push(t);
            }
            else if (t == ')' && !paren.empty() && paren.top() == '(') {
                paren.pop();
            }
            else if (t == ']' && !paren.empty() && paren.top() == '[') {
                paren.pop();
            }
            else if (t == '}' && !paren.empty() && paren.top() == '{') {
                paren.pop();
            }
            else {
                paren.push(t);
            }
        }
        return paren.empty();
    }
};

//int main() {
//    string s = "](";
//    Solution solution;
//    cout << solution.isValid(s) << endl;
//}