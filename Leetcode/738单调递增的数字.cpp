#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int flag = s.size();
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] < s[i - 1]) {
                flag = i;
                s[i - 1] -= 1;
            }
        }
        for (int i = flag; i < s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};

int main() {
    string input;
    vector<vector<int>> arr;
    while (getline(cin, input)) {
        stringstream iss(input);
        vector<int> temp;
        int num;
        while (iss >> num) {
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
    Solution solution;
    int result = solution.monotoneIncreasingDigits(arr[0][0]);
    cout << result << endl;
}