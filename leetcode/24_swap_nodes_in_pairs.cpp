class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head) {
			return NULL;
		}
		ListNode* result = new ListNode(0);
		result->next = head;
		ListNode* first = result;
		ListNode* second = head;
		while (second && second->next) {
			first->next = second->next;
			second->next = first->next->next;
			first->next->next = second;
			first = first->next->next;
			second = first->next;
		}
		return result->next;
	}
};