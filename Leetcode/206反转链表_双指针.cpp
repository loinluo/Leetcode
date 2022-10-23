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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        else {
            ListNode* slow = head;
            ListNode* fast = head->next;
            slow->next = nullptr;
            while (fast != nullptr) {
                ListNode* temp = fast->next;
                fast->next = slow;
                slow = fast;
                fast = temp;
            }
            return slow;
        }
        
    }
};

//int main() {
//    
//    ListNode* sixth = new ListNode(5);
//    ListNode* fifth = new ListNode(3, sixth);
//    ListNode* forth = new ListNode(4, fifth);
//    ListNode* third = new ListNode(6, forth);
//    ListNode* second = new ListNode(2, third);
//    ListNode* head = new ListNode(1, second);
//    Solution solution;
//    int val = 6;
//    head = solution.reverseList(head);
//    ListNode* ptr = head;
//    while (ptr != nullptr)
//    {
//        cout << ptr->val << " "; 
//        ptr = ptr->next; 
//    }
//
//}