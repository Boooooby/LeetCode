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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode *head = nullptr;
        ListNode *current = nullptr;
        int carry = 0, sum = 0;

        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;

            if (head == nullptr) {
                head = new ListNode(sum % 10);
                current = head;
            }
            else {
                current->next = new ListNode(sum % 10);
                current = current->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            sum = l1->val + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            l1 = l1->next;
        }

        while (l2 != nullptr) {
            sum = l2->val + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            l2 = l2->next;
        }

        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        return head;
    }
};