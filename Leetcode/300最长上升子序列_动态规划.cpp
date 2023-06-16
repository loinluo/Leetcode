#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        

    }
};

int main() {
    string input;
    vector<vector<int>> arr;
    while (getline(cin, input)) {
        if (input.size() > 0) {
            stringstream stringin(input);
            int num;
            vector<int> temp;
            while (stringin >> num) {
                temp.push_back(num);
            }
            arr.push_back(temp);
        }   
    }
    vector<int> nums = arr[0];
    Solution solution;
    cout << solution.lengthOfLIS(nums) << endl;

}