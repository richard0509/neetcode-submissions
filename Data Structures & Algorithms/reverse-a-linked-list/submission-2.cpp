/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        } 
        ListNode* cur = head;
        ListNode* tmp = head->next;
        head->next = nullptr;
        while (tmp != nullptr) {
            cur = tmp;
            tmp = tmp->next;
            cur->next = head;
            head = cur;
        }
        return head;
    }
};
