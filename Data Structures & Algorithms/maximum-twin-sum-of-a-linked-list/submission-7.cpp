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
        std::vector<int> arr;
        int max = 0;
        while (head) {
            arr.emplace_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        max = arr[0] + arr[n - 1];
        for (int i = 1; i < n / 2; i++) {
            max = std::max(max, arr[i] + arr[n - 1 - i]);
        }
        return max;
    }
};