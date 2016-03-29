class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* curr_l1 = l1;
		ListNode* curr_l2 = l2;
		ListNode* result = new ListNode(0);
		ListNode* result_tail = result;
		while (curr_l1 && curr_l2) {
			if (curr_l1->val < curr_l2->val) {
				result_tail->next = curr_l1;
				curr_l1 = curr_l1->next;
			}
			else {
				result_tail->next = curr_l2;
				curr_l2 = curr_l2->next;
			}
			result_tail = result_tail->next;
		}
		if (curr_l1) {
			result_tail->next = curr_l1;
		}
		else {
			result_tail->next = curr_l2;
		}
		return result->next;
	}
};