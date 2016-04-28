class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fake_head = new ListNode(0);
        fake_head -> next = head;
        ListNode* curr = fake_head;
        ListNode* curr_next = head;
        if (curr_next == NULL) {
            return NULL;
        }
        bool duplicate = false;
        while (curr_next->next != NULL) {
            if (curr_next->next->val == curr->next->val) {
                duplicate = true;
            } else {
                if (duplicate) {
                    curr->next = curr_next->next;
                    duplicate = false;
                } else {
                    curr = curr->next;
                }
            }
            curr_next = curr_next->next;
        }
        if (duplicate) {
            curr->next = NULL;
        }
        return fake_head->next;
    }
};