#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//��ϣ������δ��ɣ���Ҫȥ���ظ���鷳
// class Solution {
// public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                for (int k = j + 1; k < nums.size(); k++) {
//                    if (nums[i] + nums[j] + nums[k] == 0) {
//                        if (map[nums[k]] == 0) {
//                            vector<int> a = { nums[i], nums[j], nums[k] };
//                            result.emplace_back(a);
//                            map[nums[k]]++;
//                        }
//                    }
//                }
//            }
//        }
//        return result;
//    }
//};

//˫ָ�뷨
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            if (nums[i] > 0)
            {
                return result; //��һ��Ԫ�ش���0ֱ�ӷ���
            }
            if (i > 0 && nums[i] == nums[i - 1])
            { //���Ժ�������ϣ����Բ�����nums[i] == nums[i+1]��ֱ�������� �����ǰһ����ͬ������治����ô��϶����ظ���
                continue;
            }
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left])
                    { //�ҵ�ǰָ����ͬԪ�ص����һ��
                        left++;
                    }
                    while (right > left && nums[right - 1] == nums[right])
                    { //�ҵ���ָ����ͬԪ�صĵ�һ��
                        right--;
                    }
                    left++;
                    right--; //��ָ�����м��ƶ����������ѭ��
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 0};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}