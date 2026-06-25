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
    int pairSum(ListNode* head) {
        ListNode* fast = head;    
        ListNode* slow = head;

        // find middle node
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse second half node
        ListNode* prev = nullptr;
        ListNode* cur = slow;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        // find the maximum twin sum
        ListNode* first = head;
        ListNode* second = prev;

        int sum = 0;
        while (second) {
            sum = std::max(sum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return sum;
    }
};