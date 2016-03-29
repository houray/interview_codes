class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* new_head = tail;
        while (head != tail) {
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }
        if (k == 1) {
            return head;
        }
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* group_tail = fake_head;
        ListNode* group_head = fake_head;
        int dist = 0;
        while (group_tail) {
            if (dist == k) {
                dist = 0;
                ListNode* next_head = group_head->next;
                group_head->next = reverse(group_head->next, group_tail->next);
                group_head = next_head;
                group_tail = next_head;
            }
            ++dist;
            group_tail = group_tail->next;
        }
        return fake_head->next;
    }
};
