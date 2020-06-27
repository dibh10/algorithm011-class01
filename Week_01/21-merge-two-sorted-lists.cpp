/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *pa = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                pa->next = l1;
                l1 = l1->next;
            }
            else
            {
                pa->next = l2;
                l2 = l2->next;
            }
            pa = pa->next;
        }
        if (l1)
        {
            pa->next = l1;
        }
        if (l2)
        {
            pa->next = l2;
        }

        return dummy.next;
    }
};