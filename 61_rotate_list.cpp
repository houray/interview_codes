class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) {
			return NULL;
		}
		int count = 1;
		ListNode* node = head;
		while (node->next != NULL) {
			++count;
			node = node->next;
		}
		node->next = head;
		int r = count - k % count;
		while (r > 0) {
			node = node->next;
			--r;
		}
		head = node->next;
		node->next = NULL;
		return head;
	}
};