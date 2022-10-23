#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;

    }
};

/*int main() {
    int a[] = { -1,0,3,5,9,12 };
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int target = 9;
    Solution solution;
    cout << solution.search(nums, target) << endl; 
}*/