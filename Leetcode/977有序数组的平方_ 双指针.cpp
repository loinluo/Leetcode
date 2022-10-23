#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;
        int index = nums.size() - 1;
        while (left <= right) {
            if ((nums[right] * nums[right]) > (nums[left] * nums[left])) {
                result[index] = nums[right] * nums[right];
                right--;
            }
            else {
                result[index] = nums[left] * nums[left];
                left++;
            }
            index--;
        }
        return result;
    }
};

//int main() {
//    vector<int> nums = { -4, -1, 0, 3, 10 };
//    Solution solution;
//    vector<int> result = solution.sortedSquares(nums);
//    for (int i : result) {
//        cout << i << ' ';
//    }
//    cout << endl;
//}