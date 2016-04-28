class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) { return head; }
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* start = fake_head;
        ListNode* end = fake_head->next;;
        int i = 1;
        while (i < m) {
            start = start->next;
            end = end->next;
            ++i;
        }
        while (i < n) {
            end = end->next;
            ++i;
        }
        while (start->next != end) {
            ListNode* tmp = end->next;
            end->next = start->next;
            start->next = start->next->next;
            end->next->next = tmp;
        }
        return fake_head->next;
    }
};