#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        
        int res = 1; // 初始至少一支箭

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) { // 无重合部分，需要的弓箭数+1
                res++;
            }
            else {
                points[i][1] = min(points[i - 1][1], points[i][1]); // 有重合部分，上限设为两个上限的最小值，因为这支箭只能射到两个上限的最小值
            }

        }
        return res;
    }
};

int main() {
    string input;
    vector<vector<int>> arr;
    while (getline(cin, input)) {
        if (input.size() > 0) {
            stringstream stringin(input);
            int num;
            vector<int> a;
            while (stringin >> num) {
                a.push_back(num);
            }
            arr.push_back(a);
        }
    }
    Solution solution;
    cout << solution.findMinArrowShots(arr) << endl;

}