#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void getNext(string s, vector<int>& next) {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.empty()) {
            return false;
        }
        int length = s.size();
        vector<int> next(length);
        getNext(s, next);
        if (next[length - 1] != 0 && length % (length - next[length - 1]) == 0) {
            return true;
        }

        return false;

    }
};

//int main() {
//    string s = "mississippi";
//    Solution solution;
//    cout << solution.repeatedSubstringPattern(s);
//}