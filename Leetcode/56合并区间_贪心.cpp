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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> element = intervals[0];
        if (intervals.size() == 1) {
            result.push_back(element);
            return result;
        }
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= element[1]) {
                if (intervals[i][1] >= element[1]) {
                    element[1] = intervals[i][1];
                }
            }
            else {
                result.push_back(element);
                element = intervals[i];
            }
            if (i == intervals.size() - 1)
            {
                result.push_back(element);
            }
        }
        return result;
    }
};

void print2DVector(vector<vector<int>>& result) {
    for (auto& i : result) {
        for (int j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

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
    vector<vector<int>> result = solution.merge(arr);
    print2DVector(result);

}