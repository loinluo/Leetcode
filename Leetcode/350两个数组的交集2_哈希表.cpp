#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> nums1_map;
        vector<int> result;
        for (int i : nums1) {
            nums1_map[i] ++;
        }
        for (int j : nums2) {
            if (nums1_map[j]) {
                result.emplace_back(j);
                nums1_map[j]--;
            }
        }
        return result;
    }
};

//int main() {
//    vector<int> nums1 = { 4, 9, 5 };
//    vector<int> nums2 = { 9, 4, 9, 8, 4 };
//    Solution solution;
//    vector<int> result;
//    result = solution.intersect(nums1, nums2);
//    for (int i : result) {
//        cout << i << ' ';
//    }
//}