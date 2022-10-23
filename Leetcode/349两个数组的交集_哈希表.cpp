#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2;
        for (int i : nums2) {
            if (set1.find(i) != set1.end()) {
                set2.insert(i);
            }
        }
        return vector<int>(set2.begin(), set2.end());
    }
};

//int main() {
//    vector<int> nums1 = { 4, 9, 5 };
//    vector<int> nums2 = { 9, 4, 9, 8, 4 };
//    Solution solution;
//    vector<int> result;
//    result = solution.intersection(nums1, nums2);
//    for (int i : result) {
//        cout << i << ' ';
//    }
//}