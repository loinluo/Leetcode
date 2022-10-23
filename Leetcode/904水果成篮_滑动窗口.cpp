#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int result = 0;
        int start = 0, end = 0;
        int length = 0;
        for (end; end < fruits.size(); end++) {
            basket[fruits[end]]++;
            length++;
            while (basket.size() > 2) {
                basket[fruits[start]]--;
                if (basket[fruits[start]] == 0)
                    basket.erase(fruits[start]); // ������Ϊ0ʱ����Ԫ�ش��������Ƴ�
                start++;
                length--;
            }
            result = length > result ? length : result;
        }
        return result;
    }
};

//int main() {
//    int a[] = { 3,3,3,1,2,1,1,2,3,3,4 };
//    vector<int> nums(a, a + sizeof(a) / sizeof(int));
//    Solution solution;
//    cout << solution.totalFruit(nums) << endl;
//}