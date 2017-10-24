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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
            head=NULL;
        if(!head) return head;
        int count=1;
        ListNode* iterator=head;
        ListNode* reshead=head;
        while(iterator->next)
        {
            count++;
            iterator=iterator->next;
        }
        int Index=count-n;
        if(Index==0)
            return head->next;
        for(int i=1;i<Index;i++)
        {
            reshead=reshead->next;
        }
        if(n==1)
        {
           reshead->next=NULL;
           return head;
       }
        reshead->next=reshead->next->next;
        return head;
    }
};