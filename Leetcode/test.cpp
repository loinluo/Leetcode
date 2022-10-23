#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    int *p = &i;
    *p = *p * *p;
    cout << *p << endl;
}