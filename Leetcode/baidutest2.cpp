#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <functional>

using namespace std;

vector<int> sortsoildier(vector<int> &a, vector<int> &b)
{
    vector<int> result = a;
    if (b[0] == 1)
    {
        sort(result, result + b[1], greater<int>());
    }
    else
    {
        sort(result, result + b[1], less<int>());
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
    int n = g[0];
    int m = g[1];

    getline(cin, input);
    vector<int> a(n);
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

    for (int i = 0; i < m; i++)
    {
        getline(cin, input);
        vector<int> b(2);
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
        sortsoildier(a, b);
    }

    for (int i : a)
    {
        cout << i << ' ';
    }
}