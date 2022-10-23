#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> map;
        int result = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                map[i + j]++;
            }
        }
        for (int i : nums3) {
            for (int j : nums4) {
                if (map[- i - j]) {
                    result += map[- i - j];
                }
            }
        }
        return result;
    }
};

//int main() {
//    vector<int> nums1 = { -1, -1 };
//    vector<int> nums2 = { -1, 1 };
//    vector<int> nums3 = { -1, 1 };
//    vector<int> nums4 = { 1, -1 };
//    Solution solution;
//    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;
//}