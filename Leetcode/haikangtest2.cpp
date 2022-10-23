#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *joint(ListNode *m, ListNode *n)
{
    ListNode *ptr = n;
    ListNode *ptr2 = m;
    while (ptr != nullptr)
    {
        if (ptr->val < ptr2->val)
        {
            int temp = ptr2->val;
            ptr2->val = ptr->val;
            ptr2->next = new ListNode(temp, ptr2->next);
        }
        else
        {
            while (ptr->val >= ptr2->val)
            {
                ptr2 = ptr2->next;
            }
            int temp = ptr2->val;
            ptr2->val = ptr->val;
            ptr2->next = new ListNode(temp, ptr2->next);
        }
        ptr = ptr->next;
    }
    return m;
}

int main()
{
    string input;
    cout << "input" << endl;
    getline(cin, input);
    ListNode *m = new ListNode();
    ListNode *temp1 = m;
    if (input.size() > 0)
    {
        stringstream stringin(input);
        int num;
        while (stringin >> num)
        {
            temp1->next = new ListNode();
            temp1->val = num;
            temp1 = temp1->next;
        }
    }
    getline(cin, input);
    ListNode *n = new ListNode();
    ListNode *temp2 = n;
    if (input.size() > 0)
    {
        stringstream stringin(input);
        int num;
        while (stringin >> num)
        {
            temp2->next = new ListNode();
            temp2->val = num;
            temp2 = temp2->next;
        }
    }
    ListNode *ptr = m;
    while (ptr)
    {
        cout << ptr->val;
        ptr = ptr->next;
    }
}