#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//����һ�������ģ�����û��ֱ�ӷ��ڶ��ף�������������ı����ȰѶ���ǰ������
class Solution {
private:
    class MyQue {
    public:
        deque<int> que;
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }

        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }

        int front() {
            return que.front();
        }

    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }        
        result.push_back(que.front());
        
        for (int i = 1; i < nums.size() - k + 1; i++) {
            que.pop(nums[i - 1]);
            que.push(nums[i + k - 1]);
            result.push_back(que.front());
        }

        return result;
    }
};

//int main() {
//    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
//    int k = 3;
//    Solution solution;
//    vector<int> result;
//    result = solution.maxSlidingWindow(nums, k);
//    for (int i : result) {
//        cout << i << ' ';
//    }
//    cout << endl;
//}