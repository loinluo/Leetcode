#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

string LegalPara(string &s)
{
    int count = 0;
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == '(')
            count++;
        if (s[i] == ')')
            count--;
        if (count < 0)
            return "false";
    }
    if (count == 0)
        return "true";
    return "false";
}

int main()
{
    string s;
    cout << "input:" << endl;
    cin >> s;
    cout << LegalPara(s) << endl;
}