#include<iostream>
#include<stack>

using namespace std;

/*������Сд��ĸ��ɵ��ַ��� S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����*/

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