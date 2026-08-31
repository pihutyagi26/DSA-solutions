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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        while (curr && curr->next) {
            int a = prev->val;
            int b = curr->val;
            int c = curr->next->val;

            if ((b > a && b > c) || (b < a && b < c)) {
                pos.push_back(idx);
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (pos.size() < 2) return {-1, -1};

        int mn = INT_MAX;

        for (int i = 1; i < pos.size(); i++) {
            mn = min(mn, pos[i] - pos[i - 1]);
        }

        int mx = pos.back() - pos.front();

        return {mn, mx};
    }
};