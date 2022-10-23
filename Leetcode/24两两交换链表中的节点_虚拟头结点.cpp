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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* dummyHead = new ListNode(0);
        if (head != nullptr && head->next != nullptr) {
            dummyHead->next = head->next;
        }
        else {
            dummyHead->next = head;
        }
        
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->next != nullptr) {
                if (cur->next->next->next != nullptr) {
                    ListNode* temp = cur->next->next;
                    cur->next->next = cur;
                    cur->next = temp->next;
                    cur = temp;
                }
                else {
                    ListNode* temp = cur->next->next;
                    cur->next->next = cur;
                    cur->next = temp;
                    cur = temp; // 否则会一直循环
                }
            }
            else {
                cur->next->next = cur;
                cur->next = nullptr;
            }

        }
        return dummyHead->next;
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
//    Solution solution;
//    head = solution.swapPairs(head);
//    ListNode* ptr = head;
//    while (ptr != nullptr)
//    {
//        cout << ptr->val << " ";
//        ptr = ptr->next;
//    }
//
//}