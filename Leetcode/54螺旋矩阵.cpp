#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, column = 0;        
        vector<int> result(m * n, 0);
        int count = 0;
        while (m > 0 && n > 0) {
            int i = row;
            int j = column;
            for (j; j < column + n - 1; j++) {
                result[count++] = matrix[i][j];
            }
            for (i; i < row + m - 1; i++) {
                result[count++] = matrix[i][j];
            }
            if (m == 1 && n != 1) {
                result[count++] = matrix[i][j];
            }
            else {
                for (j; j > column; j--) {
                    result[count++] = matrix[i][j];
                }
            }            
            if (n == 1 && m != 1) {
                result[count++] = matrix[i][j];
            }
            else {
                for (i; i > row; i--) {
                    result[count++] = matrix[i][j];
                }
            }
            
            if (m == 1 && n == 1) {
                result[count] = matrix[i][j];
            }
            m -= 2;
            n -= 2;
            row++;
            column++;
        }
        return result;

    }
};


//int main() {
//    vector<vector<int>> matrix(3, vector<int>(5, 0));
//    int count = 1;
//    for (int i = 0; i < matrix.size(); i++) {
//        for (int j = 0; j < matrix[0].size(); j++) {
//            matrix[i][j] = count++;
//        }
//    }
//    Solution solution;
//    vector<int> result = solution.spiralOrder(matrix);
//    for (int i = 0; i < 15; i++)
//    cout << result[i] << '\t';
//}