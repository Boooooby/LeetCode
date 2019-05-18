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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;
        
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *first = temp, *second = first->next, *third = second->next;
        
        while (true) {
            second->next = third->next;
            third->next = second;
            first->next = third;
            
            if (second->next == NULL || second->next->next == NULL) 
                break;
            
            first = second;
            second = first->next;
            third = second->next;
        }
        
        return temp->next;
    }
};