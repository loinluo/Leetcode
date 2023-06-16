#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool compare(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        if (intervals.size() == 0) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right) {
                result += 1;
                if (intervals[i][1] < right) {
                    left = intervals[i][0];
                    right = intervals[i][1];
                }
            }
            else {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        return result;
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
    int result = solution.eraseOverlapIntervals(arr);
    cout << result << endl;
}