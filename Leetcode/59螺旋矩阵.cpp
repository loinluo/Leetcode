#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,0)); // ≥ı ºªØresult
        int row = 0, column = 0;
        int turn = n / 2;
        int offset = 1;
        int count = 1;
        while (turn--){
            int i = row;
            int j = column;           
            for (j; j < column + n - offset; j++) {
                result[row][j] = count++;
            }
            for (i; i < row + n - offset; i++) {
                result[i][j] = count++;
            }
            for (j; j > column; j--) {
                result[i][j] = count++;
            }
            for (i; i > row; i--) {
                result[i][j] = count++;
            }
            row++;
            column++;
            offset += 2;
        }
        if (n % 2 == 1)
            result[n / 2][n / 2] = count;
        return result;
    }
};

//int main() {
//    int n = 4;
//    Solution solution;
//    vector<vector<int>> result = solution.generateMatrix(n);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++)
//        {
//            cout << result[i][j]<<'\t';
//        }
//        cout << endl;
//    }
//        
//    
//}