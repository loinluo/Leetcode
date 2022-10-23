#include<iostream>
#include<vector>
using namespace std;

//暴力
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        if (needle.empty()) {
//            return 0;
//        }
//        for (int i = 0; i < haystack.size(); i++) {
//            if (haystack[i] == needle[0]) {
//                if (needle.size() == 1) {
//                    return i;
//                }
//                else {
//                    for (int j = 1; j < needle.size(); j++) {
//                        if (haystack[i + j] != needle[j]) {
//                            break;
//                        }
//                        if (j == needle.size() - 1){
//                            return i;
//                        }
//                    }
//                }
//
//            }
//        }
//        return -1;
//    }
//};

//KMP算法
class Solution {
public:
    void getNext(vector<int>& next, const string& s) { //next为整型数组，s为needle
        next[0] = 0;
        int count = 0;
        for (int i = 1; i < s.size(); i++) {
            while (count > 0 && s[count] != s[i]) {
                count = next[count - 1];
            }
            if (s[i] == s[count]) {
                count++;
            }
            next[i] = count;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()){
            return 0;
        }
        //前缀表
        vector<int> table(needle.size());
        getNext(table, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = table[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;

    }
};

//int main() {
//    string haystack = "mississippi";
//    string needle = "issip";
//    Solution solution;
//    cout << solution.strStr(haystack, needle);
//}