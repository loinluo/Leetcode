#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (s == "+") {
                    st.push(b + a);
                }
                if (s == "-") {
                    st.push(b - a);
                }
                if (s == "*") {
                    st.push(b * a);
                }
                if (s == "/") {
                    st.push(b / a);
                }
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};

//int main() {
//    vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
//    Solution solution;
//    cout << solution.evalRPN(tokens) << endl;
//}