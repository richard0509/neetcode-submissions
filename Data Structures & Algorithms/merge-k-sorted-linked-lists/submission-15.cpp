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
        if (lists.empty()) {
            return nullptr;
        }

        // O(log(n))
        while (lists.size() != 1) {
            std::vector<ListNode*> mergedList;
            int k = lists.size();
            for (int i = 0; i < k; i += 2) {
                auto l1 = lists[i];
                auto l2 = new ListNode();
                if (i + 1 < k) {
                    l2 = lists[i + 1];
                } else {
                    l2 = nullptr;
                }
                auto temp = mergeList(l1, l2);
                mergedList.push_back(temp);
            }
            lists = mergedList;
        }
        return lists[0];
    }

    // leetcode #21 merge two sorted lists
    // O(n)
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        auto cur = ans;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 == nullptr) ? l2 : l1;
        auto ans2 = ans->next;
        delete ans;
        return ans2;
    }
};
