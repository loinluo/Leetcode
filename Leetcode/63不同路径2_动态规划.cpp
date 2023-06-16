#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            else {
                dp[i][0] = 1;
            }
        }
        for (int j = 0; j < cols; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            else {
                dp[0][j] = 1;
            }            
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};

int findFirstBracket(string input) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '[') {
            return i + 1;
        }
    }
    return -1;
}

// read the string in the representation of bracket to a vector<vector<int>>
vector<vector<int>> stringToVector(string input) {
    vector<vector<int>> result;
    // remove the first and last bracket
    input = input.substr(1, input.size() - 2);
    stringstream stringin(input);
    string temp;
    while (getline(stringin, temp, ']')) {
        if (temp.size() > 0) {
            // remove the first bracket
            int index = findFirstBracket(temp);
            temp = temp.substr(index, temp.size() - 1);
            stringstream stringin2(temp);
            int num;
            vector<int> arr1d;
            while (getline(stringin2, temp, ',')) {
                if (temp.size() > 0) {
                    num = stoi(temp);
                    arr1d.push_back(num);
                }
            }
            result.push_back(arr1d);
        }
        
    }
    return result; 
}

int main() {
    string input;
    vector<vector<int>> grid;
    // while (getline(cin, input)) {
    //     if (input.size() > 0) {
    //         stringstream stringin(input);
    //         int num;
    //         vector<int> temp;
    //         while (stringin >> num) {
    //             temp.push_back(num);
    //         }
    //         grid.push_back(temp);
    //     }
    // }
    getline(cin, input);
    grid = stringToVector(input);
    Solution solution;
    cout << solution.uniquePathsWithObstacles(grid) << endl;
    

}