#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        for (int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummyHead->next;
    }
};

//int main() {
//    
//    ListNode* sixth = new ListNode(5);
//    ListNode* fifth = new ListNode(3, sixth);
//    ListNode* forth = new ListNode(4, fifth);
//    ListNode* third = new ListNode(6, forth);
//    ListNode* second = new ListNode(2, third);
//    ListNode* head = new ListNode(1, sixth);
//    Solution solution;
//    int n = 1;
//    head = solution.removeNthFromEnd(sixth, n);
//    ListNode* ptr = head;
//    while (ptr != nullptr)
//    {
//        cout << ptr->val << " "; 
//        ptr = ptr->next; 
//    }
//
//}