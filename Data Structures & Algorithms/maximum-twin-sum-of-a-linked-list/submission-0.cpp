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
        std::vector<ListNode*> arr;
        int max = 0;
        while (head) {
            arr.emplace_back(head);
            head = head->next;
        }

        int n = arr.size();
        max = arr[0]->val + arr[n - 1]->val;
        for (int i = 1; i < n; i++) {
            max = std::max(max, arr[i]->val + arr[n - 1 - i]->val);
        }
        return max;
    }
};