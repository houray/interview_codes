class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* less_tail = less;
        ListNode* other = new ListNode(0);
        ListNode* other_tail = other;
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                less_tail->next = curr;
                less_tail = less_tail->next;
                curr = curr->next;
                less_tail->next = NULL;
            } else {
                other_tail->next = curr;
                other_tail = other_tail->next;
                curr = curr->next;
                other_tail->next = NULL;
            }
        }
        if (less_tail == less) { return other->next; }
        less_tail->next = other->next;
        return less->next;
    }
};