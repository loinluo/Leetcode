#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hashmap(26, 0);
        for (int i = 0; i < s.size(); i++) {
            hashmap[s[i] - 'a'] = i;
        }
        vector<int> result;
        int max = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count++;
            if (hashmap[s[i] - 'a'] > max) {
                max = hashmap[s[i] - 'a'];
            }
            if (i == max) {
                result.push_back(count);
                count =  0;
            }
        }
        return result;
    }
};

int main() {
    string input;
    getline(cin, input);
    Solution solution;
    vector<int> result = solution.partitionLabels(input);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << endl;

}