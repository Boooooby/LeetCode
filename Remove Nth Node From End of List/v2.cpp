/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = new ListNode(0, head);
        ListNode *first = tmp, *second = tmp;
        
        for (int i = 0; i <= n; i++) {
            second = second->next;
        }

        while (second != NULL) {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;

        return tmp->next;
    }
};