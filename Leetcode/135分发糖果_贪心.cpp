#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> num_candy(ratings.size(), 1);
        int res = 0;
        // for (int i = 0; i < ratings.size(); i++)
        // {
        //     if (i > 0)
        //     {
        //         if (ratings[i] > ratings[i - 1])
        //         {
        //             if (num_candy[i] <= num_candy[i - 1])
        //             {
        //                 num_candy[i] = num_candy[i - 1] + 1;
        //             }
        //         }
        //     }
        //     if (i < ratings.size() - 1)
        //     {
        //         if (ratings[i] > ratings[i + 1])
        //         {
        //             if (num_candy[i] <= num_candy[i + 1])
        //             {
        //                 num_candy[i] = num_candy[i + 1] + 1;
        //                 int j = i;
        //                 while (j > 0 && num_candy[j] == num_candy[j - 1] && ratings[j - 1] > ratings[j])
        //                 {
        //                     num_candy[j - 1] += 1;
        //                     j--;
        //                 }
        //             }
        //         }
        //     }
        // }
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                if (num_candy[i] <= num_candy[i - 1])
                {
                    num_candy[i] = num_candy[i - 1] + 1;
                }
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                if (num_candy[i] <= num_candy[i + 1])
                {
                    num_candy[i] = max(num_candy[i], num_candy[i + 1] + 1);
                }
            }
        }

        for (int i = 0; i < ratings.size(); i++)
        {
            res += num_candy[i];
        }
        return res;
    }
};

int main()
{
    string input;
    vector<vector<int>> arr;
    while (getline(cin, input))
    {
        if (input.size() > 0)
        {
            stringstream stringin(input);
            int num;
            vector<int> a;
            while (stringin >> num)
            {
                a.push_back(num);
            }
            arr.push_back(a);
        }
    }
    vector<int> ratings = arr[0];
    Solution solution;
    cout << solution.candy(ratings) << endl;
    return 0;
}