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
	int getSize(ListNode* head) {
		ListNode* phead = head;
		int size = 0;
		while (phead != NULL) {
			size++;
			phead = phead->next;
		}
		return size;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int size = getSize(head);
		ListNode* phead = head;
		if (n == size) return phead->next;
		int i = size - n - 1;
		while (i--) {
			phead = phead->next;
		}
		phead->next = phead->next->next;
		return head;
	}
};