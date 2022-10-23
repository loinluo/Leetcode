#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

/*给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。*/
class Solution {
public:
    //小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result(k);
        unordered_map<int, int> counter;
        for (int i : nums) {
            counter[i] ++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = counter.begin(); it != counter.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

        
    }
};

int main() {
    vector<int>nums = { 1,1,1,2,2,3 };
    int k = 2;
    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    for (int i : result) {
        cout << i << ' ';
    }
}