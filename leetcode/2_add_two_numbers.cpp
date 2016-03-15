/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int flag = 0;

        ListNode *result = NULL;

        ListNode *curr;

        while (l1 && l2) {

            ListNode *next = new ListNode((l1->val + l2->val + flag) % 10);

            flag = (l1->val + l2->val + flag) / 10;

            if (result) {

                curr->next = next;

            } else {

                result = next;

            }

            curr = next;

            l1 = l1->next;

            l2 = l2->next;

        }

        while (l1) {

            ListNode *next = new ListNode((l1->val + flag) % 10);

            flag = (l1->val + flag) / 10;

            if (result) {

                curr->next = next;

            } else {

                result = next;

            }

            curr = next;

            l1 = l1->next;

        }

        while (l2) {

            ListNode *next = new ListNode((l2->val + flag) % 10);

            flag = (l2->val + flag) / 10;

            if (result) {

                curr->next = next;

            } else {

                result = next;

            }

            curr = next;

            l2 = l2->next;

        }

        if (flag) {

            ListNode *next = new ListNode(flag);

            curr->next = next;

        }

        return result;

    }

};
