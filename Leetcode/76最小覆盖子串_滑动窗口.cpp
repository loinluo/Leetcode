#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        int rest = 0;
        for (char c : t) {
            need[c]++;
        }
        rest = t.size();
        int start = 0, end = 0;
        int length = INT32_MAX;
        int result = 0;

        for (end; end < s.size(); end++) {
            if (need[s[end]] > 0)
                rest--;              
            need[s[end]]--;
            if (rest == 0) {
                while (start < end && need[s[start]] < 0) {
                    need[s[start]]++;
                    start++;
                }
                if (end - start + 1 < length) {
                    length = end - start + 1;
                    result = start;
                }
                need[s[start]]++;
                start++;
                rest++;
            }
        }
        return length == INT32_MAX ? "" : s.substr(result, length);
    }
};

//int main() {
//    string s = "cabwefgewcwaefgcf", t = "cae";
//    Solution solution;
//    cout << solution.minWindow(s,t) << endl;
//}