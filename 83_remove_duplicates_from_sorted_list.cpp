class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* curr = head;
        ListNode* sec = head->next;
        while (sec != NULL) {
            if (curr->val == sec->val) {
                curr->next = sec->next;
            } else {
                curr = curr->next;
            }
            sec = sec->next;
        }
        return head;
    }
};