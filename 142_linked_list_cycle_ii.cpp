class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) { return NULL; }
        ListNode *front = head;
        ListNode *back = head;
        while(front->next != NULL && front->next->next != NULL) {
            front = front ->next->next;
            back = back->next;
            if (front == back) { 
                back = head;
                while (back != front) {
                    back = back->next;
                    front = front->next;
                }
                return back;
            }
        }
        return false;
    }
};