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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        ListNode *pre=newhead;
        for(int i=1;i<=m-1;i++)
        {
            pre=pre->next;
        }
        ListNode *Cur=pre->next;
        for(int i=0;i<n-m;i++)
        {
            //if(Cur->next==NULL)
            //{
              //  break;
            //}
            ListNode *temp=Cur->next;
            Cur->next=temp->next;
            temp->next=pre->next;//??? Why it can not be temp->next=Cur????
            pre->next=temp;
        }
        return newhead->next;
    }
};
