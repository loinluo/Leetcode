#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        // 先将字符串vector中的每个字符串进行排序，排完序后都对应相同的key
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        vector<vector<string>> result;
        // 将每一个key下对应的所有value赋给result中的一个元素
        for (auto value = map.begin(); value != map.end(); value++) {
            result.emplace_back(value->second);
        }
        return result;
    }
};

//int main() {
//    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
//    Solution solution;
//    vector<vector<string>> result = solution.groupAnagrams(strs);
//    vector<string> temp;
//    for (auto i = result.begin(); i != result.end(); i++) {
//        temp = *i;
//        for (auto j = temp.begin(); j != temp.end(); j++) {
//            cout << *j << ' ';
//        }
//        cout << endl;
//    }
//}