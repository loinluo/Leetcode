#include<iostream>
#include<stack>

using namespace std;

/*给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。*/

//class Solution {
//public:
//    string removeDuplicates(string s) {
//        stack<char> stIn;
//        stack<char> stOut;
//        string result;
//        for (char t : s) {
//            if (!stIn.empty() && t == stIn.top()) {
//                stIn.pop();
//            }
//            else {
//                stIn.push(t);
//            }            
//        }
//        while (!stIn.empty()) {
//            stOut.push(stIn.top());
//            stIn.pop();
//        }
//        while (!stOut.empty()) {
//            result.push_back(stOut.top());
//            stOut.pop();
//        }
//        return result;
//    }
//};

//class Solution {
//public:
//    string removeDuplicates(string s) {
//        stack<char> stIn;
//        string result;
//        for (char t : s) {
//            if (!stIn.empty() && t == stIn.top()) {
//                stIn.pop();
//            }
//            else {
//                stIn.push(t);
//            }
//        }
//        while (!stIn.empty()) {
//            result.push_back(stIn.top());
//            stIn.pop();
//        }
//
//        reverse(result.begin(), result.end());
//
//        return result;
//    }
//};

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (char t : s) {
            if (!result.empty() && t == result.back()) {
                result.pop_back();
            }
            else {
                result.push_back(t);
            }
        }
        return result;
    }
};

//int main() {
//    string s = "abbaca";
//    Solution solution;
//    cout << solution.removeDuplicates(s) << endl;
//}