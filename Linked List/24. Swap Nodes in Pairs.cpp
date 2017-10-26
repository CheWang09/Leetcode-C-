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
    ListNode* swapPairs(ListNode* head) {
        ListNode *ResHead=head;
        while(head!=NULL&&head->next!=NULL)
        {
            int temp=head->val;
            head->val=head->next->val;
            head->next->val=temp;
            head=head->next->next;       
        }
        return ResHead;
    }
};
