class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *front = head;
		ListNode *end = NULL;
		int i = 0;
		while (i < n) {
			front = front->next;
			++i;
		}
		while (front) {
			front = front->next;
			if (end) {
				end = end->next;
			}
			else {
				end = head;
			}
		}
		if (end) {
			end->next = end->next->next;
		}
		else {
			head = head->next;
		}
		return head;
	}
};