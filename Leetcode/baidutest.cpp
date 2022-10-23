#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int MaxLevel(vector<int> &a, vector<int> &b, int t)
{
    int m = a.size();
    int n = b.size();
    int result = 0;
    int tused = 0;
    int i = 0, j = 0;
    while (tused < t && result < m + n)
    {
        if (a[i] <= b[j] || j == n)
        {
            tused += a[i];
            i++;
        }
        else if (a[i] > b[j] || i == m)
        {
            tused += b[j];
            j++;
        }
        result++;
    }

    return result;
}

int main()
{
    string input;
    // cout << "input" << endl;
    getline(cin, input);
    vector<int> g;
    if (input.size() > 0)
    {
        stringstream stringin(input);
        int num;
        while (stringin >> num)
        {
            g.push_back(num);
        }
    }
    int m = g[0];
    int n = g[1];
    int t = g[2];

    getline(cin, input);
    vector<int> a(m);
    int i = 0;
    if (input.size() > 0)
    {
        stringstream stringin(input);
        int num;
        while (stringin >> num)
        {
            a[i] = num;
            i++;
        }
    }

    getline(cin, input);
    vector<int> b(n);
    int j = 0;
    if (input.size() > 0)
    {
        stringstream stringin(input);
        int num;
        while (stringin >> num)
        {
            b[j] = num;
            j++;
        }
    }

    cout << MaxLevel(a, b, t) << endl;
}