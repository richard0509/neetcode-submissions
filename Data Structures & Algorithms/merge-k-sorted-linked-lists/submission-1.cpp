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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode();
        auto cur = ans;
        int n = lists.size();
        while (true) {

            int i = 0;
            int min = INT_MAX;
            int min_index = -1;

            while (i < n) {
                if (lists[i] != nullptr && lists[i]->val < min) {
                    min = lists[i]->val;
                    min_index = i;
                }
                i++;
            }

            if (min_index == -1) {
                break;
            }

            if (min_index != -1) {
                cur->next = lists[min_index];
                cur = cur->next;
                lists[min_index] = lists[min_index]->next;
            }
        }
        return ans->next;
    }
};
