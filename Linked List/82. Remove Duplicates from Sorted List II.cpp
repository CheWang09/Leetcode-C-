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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode* help=new ListNode(0);
        help->next=head;
        ListNode* pre=help;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            while(cur->next!=NULL&&pre->next->val==cur->next->val)
            {
                cur=cur->next;
            }
            if(pre->next!=cur)
            {
                pre->next=cur->next;
            }
            else
                pre=pre->next;
            cur=cur->next;
        }
        return help->next;
    }
};
