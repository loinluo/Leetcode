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
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

//int main() {
//
//    ListNode* sixth = new ListNode(5);
//    ListNode* fifth = new ListNode(3, sixth);
//    ListNode* forth = new ListNode(4, sixth);
//    ListNode* third = new ListNode(6, forth);
//    ListNode* second = new ListNode(2, third);
//    ListNode* head = new ListNode(1, second);
//    fifth->next = second;
//    Solution solution;
//    ListNode* cycle = solution.detectCycle(head);
//    ListNode* ptr = head;
//    int post = 0;
//    while (ptr != nullptr && ptr != cycle)
//    {
//        post++;
//        ptr = ptr->next;
//    }
//    if (ptr == nullptr) {
//        post = -1;
//    }
//    cout << post << endl;
//
//}