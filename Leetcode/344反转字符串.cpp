#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        //以中点为界交换前后元素
        int num = s.size();
        for (int i = 0; i < num / 2; i++) {
            char temp = s[num - i - 1];
            s[num - i - 1] = s[i];
            s[i] = temp;
        }
    }
};

//int main() {
//    vector<char> s = { 'h','e','l','l','o'};
//    Solution solution;
//    solution.reverseString(s);
//    for (char t : s) {
//        cout << t << ' ';
//    }
//
//}