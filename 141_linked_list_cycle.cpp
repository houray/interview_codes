class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) { return false; }
        ListNode* back = head;
        ListNode* front = head;
        while (back->next != NULL && back->next->next != NULL) {
            back = back->next->next;
            front = front->next;
            if (back == front) { return true; }
        }
        return false;
    }
};