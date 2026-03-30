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
            int min_index = -1;

            while (i < n) {
                // is not empty, have value to compare to
                if (lists[i] != nullptr) {
                    // (the first one) or (is smaller than current min value)
                    if (min_index == -1 || lists[i]->val < lists[min_index]->val) {
                        min_index = i;
                    }
                }
                i++;
            }

            if (min_index == -1) {
                break;
            } else {
                cur->next = lists[min_index];
                cur = cur->next;
                lists[min_index] = lists[min_index]->next;
            }
        }
        return ans->next;
    }
};
