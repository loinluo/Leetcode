#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

/*����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�*/
class Solution {
public:
    //С����
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

        // �ù̶���СΪk��С���ѣ�ɨ������Ƶ�ʵ���ֵ
        for (unordered_map<int, int>::iterator it = counter.begin(); it != counter.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // ����ѵĴ�С������K������е�������֤�ѵĴ�СһֱΪk
                pri_que.pop();
            }
        }

        // �ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
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