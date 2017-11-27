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
    void reorderList(ListNode* head) {        
        if(!head||!head->next) return;
        
        ListNode *fastPointer=head;
        ListNode *SlowPointer=head;
        
        while(fastPointer->next&&fastPointer->next->next)
        {
            SlowPointer=SlowPointer->next;
            fastPointer=fastPointer->next->next;
        }
        //Above code , set two pointer so we can divide list into to part,the previous one and the latter one.
        
        fastPointer=SlowPointer->next;
        SlowPointer->next=NULL;
        
        
        ListNode *Sechead=fastPointer;
        ListNode* curPos=fastPointer->next;
        Sechead->next=NULL;
        while(curPos)
        {
            auto temp=curPos->next;
            curPos->next=Sechead;
            Sechead=curPos;
            curPos=temp;
        }
        
        //Above code is to resverse the second part
        
        ListNode * newhead=head;
        ListNode *help=Sechead->next;
        while(Sechead&&newhead)
        {
            auto temp1=newhead->next;
            auto temp2=Sechead->next;
            Sechead->next=newhead->next;
            newhead->next=Sechead;
            newhead=temp1;
            Sechead=temp2;
        }

        
    }
};
