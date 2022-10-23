#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        //删除头结点开始所有满足要求的节点
//        while (head != NULL && head->val == val) {
//            ListNode* temp = head;
//            head = head->next;
//            delete temp;
//        }
//        ListNode* cur = head;
//        while (cur != NULL && cur->next != NULL) {
//            if (cur->next->val == val) {
//                ListNode* temp = cur->next;
//                cur->next = cur->next->next;
//                delete temp;
//            }
//            else {
//                cur = cur->next;
//            }
//
//        }
//        return head;
//    }
//};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
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
//    head = solution.removeElements(head, val);
//    ListNode* ptr = head;
//    while (ptr != nullptr)
//    {
//        cout << ptr->val << " "; 
//        ptr = ptr->next; 
//    }
//
//}


